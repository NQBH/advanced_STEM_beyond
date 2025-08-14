// TSP Route Optimizer for 63 Vietnam Provinces with Time and Cost Constraints
#include <windows.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <climits>
#include <algorithm>
#include <ctime>
#include <random>
#include <curl/curl.h>

using namespace std;

struct Point {
    double x, y;
    string name;
    double start_time; // Start of time window (hours, e.g., 8.0 for 8 AM)
    double end_time;   // End of time window (hours, e.g., 12.0 for 12 PM)
};

size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* s) {
    size_t newLength = size * nmemb;
    s->append((char*)contents, newLength);
    return newLength;
}

vector<Point> fetch_coordinates_from_osm(vector<pair<string, pair<double, double>>> inputs) {
    vector<Point> points;
    CURL* curl;
    CURLcode res;
    string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0");
        curl_easy_setopt(curl, CURLOPT_CAINFO, "C:/curl-8.14.1_2-win64-mingw/cacert.pem");

        for (const auto& input : inputs) {
            if (!input.first.empty()) {
                char* escaped = curl_easy_escape(curl, input.first.c_str(), 0);
                string url = "https://nominatim.openstreetmap.org/search?q=" + string(escaped) + ",+Vietnam&format=json";
                curl_free(escaped);

                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
                res = curl_easy_perform(curl);
                if (res != CURLE_OK) {
                    cerr << "Error fetching " << input.first << ": " << curl_easy_strerror(res) << endl;
                    continue;
                }

                size_t pos = readBuffer.find("\"lat\":\"");
                if (pos != string::npos) {
                    pos += 7;
                    size_t end = readBuffer.find("\"", pos);
                    double lat = stod(readBuffer.substr(pos, end - pos));

                    pos = readBuffer.find("\"lon\":\"", end);
                    if (pos != string::npos) {
                        pos += 7;
                        end = readBuffer.find("\"", pos);
                        double lon = stod(readBuffer.substr(pos, end - pos));
                        // Assign default time window [8 AM, 12 PM]
                        points.push_back({lon, lat, input.first, 8.0, 12.0});
                        cout << "Fetched: " << input.first << " => (" << lon << ", " << lat << ")\n";
                    }
                } else {
                    cerr << "Not found: " << input.first << endl;
                }
                readBuffer.clear();
            }
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return points;
}

double euclidean_distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

struct RouteInfo {
    vector<int> route;
    double total_distance;
    double total_time; // Total travel time in hours
    double total_cost; // Total delivery cost
    bool time_feasible; // Whether the route satisfies time constraints
};

RouteInfo calculate_route_info(const vector<Point>& points, const vector<int>& route, double speed_kmh = 50.0, double cost_per_km = 10.0) {
    double total_distance = 0.0;
    double total_time = 8.0; // Start at 8 AM
    double total_cost = 0.0;
    bool time_feasible = true;

    for (size_t i = 0; i < route.size() - 1; ++i) {
        double dist = euclidean_distance(points[route[i]], points[route[i + 1]]);
        total_distance += dist;
        total_cost += dist * cost_per_km; // Cost proportional to distance
        double travel_time = dist / speed_kmh; // Time = distance / speed
        total_time += travel_time;

        // Check time window for the next point
        int next = route[i + 1];
        if (total_time < points[next].start_time) {
            total_time = points[next].start_time; // Wait until start of time window
        } else if (total_time > points[next].end_time) {
            time_feasible = false; // Violates time window
        }
    }

    return {route, total_distance, total_time, total_cost, time_feasible};
}

pair<vector<int>, double> greedy_tsp(vector<Point>& points) {
    int n = points.size();
    vector<bool> visited(n, false);
    vector<int> route = {0};
    visited[0] = true;
    int current = 0;
    for (int i = 0; i < n - 1; ++i) {
        double min_dist = INT_MAX;
        int next = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && euclidean_distance(points[current], points[j]) < min_dist) {
                min_dist = euclidean_distance(points[current], points[j]);
                next = j;
            }
        }
        visited[next] = true;
        route.push_back(next);
        current = next;
    }
    route.push_back(0);
    auto info = calculate_route_info(points, route);
    return {info.route, info.total_distance};
}

// Function prototype for two_opt_swap
vector<int> two_opt_swap(const vector<int>& route, int i, int k);

pair<vector<int>, double> two_opt_optimize(const vector<Point>& points, vector<int> route) {
    auto best_info = calculate_route_info(points, route);
    double best_dist = best_info.total_distance;
    bool improved = true;
    while (improved) {
        improved = false;
        for (int i = 1; i < route.size() - 2; ++i) {
            for (int k = i + 1; k < route.size() - 1; ++k) {
                auto new_route = two_opt_swap(route, i, k);
                auto new_info = calculate_route_info(points, new_route);
                if (new_info.total_distance < best_dist && new_info.time_feasible) {
                    route = new_route;
                    best_dist = new_info.total_distance;
                    best_info = new_info;
                    improved = true;
                }
            }
        }
    }
    return {best_info.route, best_dist};
}

vector<int> two_opt_swap(const vector<int>& route, int i, int k) {
    vector<int> new_route = route;
    reverse(new_route.begin() + i, new_route.begin() + k + 1);
    return new_route;
}

int main() {
    int mode;
    cout << "Chọn chế độ:\n1. Nhập tay các điểm\n2. Dùng danh sách 63 tỉnh thành\n3. Đọc từ file\n> ";
    cin >> mode;
    cin.ignore();
    vector<pair<string, pair<double, double>>> inputs;
    vector<Point> manual_points; // Dùng cho trường hợp nhập đủ thông tin
    if (mode == 1) {
        int n;
        cout << "Nhập số lượng điểm: ";
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; ++i) {
            string line;
            cout << "Nhập tên tỉnh hoặc tọa độ (x y) cho điểm " << i + 1 << ": ";
            getline(cin, line);
            if (!line.empty() && (isdigit(line[0]) || line[0] == '-')) {
                istringstream iss(line);
                double x, y;
                iss >> x >> y;
                inputs.push_back({"", {x, y}});
            } else {
                inputs.push_back({line, {0, 0}});
            }
        }
    } else if (mode == 2) {
        vector<string> provinces = {
            "Hà Nội", "TP. Hồ Chí Minh", "Đà Nẵng", "Hải Phòng", "Cần Thơ", "An Giang", "Bà Rịa - Vũng Tàu", "Bắc Giang", "Bắc Kạn", "Bạc Liêu", "Bắc Ninh", "Bến Tre", "Bình Định", "Bình Dương", "Bình Phước", "Bình Thuận", "Cà Mau", "Cao Bằng", "Đắk Lắk", "Đắk Nông", "Điện Biên", "Đồng Nai", "Đồng Tháp", "Gia Lai", "Hà Giang", "Hà Nam", "Hà Tĩnh", "Hải Dương", "Hậu Giang", "Hòa Bình", "Hưng Yên", "Khánh Hòa", "Kiên Giang", "Kon Tum", "Lai Châu", "Lâm Đồng", "Lạng Sơn", "Lào Cai", "Long An", "Nam Định", "Nghệ An", "Ninh Bình", "Ninh Thuận", "Phú Thọ", "Phú Yên", "Quảng Bình", "Quảng Nam", "Quảng Ngãi", "Quảng Ninh", "Quảng Trị", "Sóc Trăng", "Sơn La", "Tây Ninh", "Thái Bình", "Thái Nguyên", "Thanh Hóa", "Thừa Thiên Huế", "Tiền Giang", "Trà Vinh", "Tuyên Quang", "Vĩnh Long", "Vĩnh Phúc", "Yên Bái"
        };
        for (const auto& p : provinces)
            inputs.push_back({p, {0, 0}});
    } else if (mode == 3) {
        string filename;
        cout << "Nhập tên file: ";
        getline(cin, filename);
        ifstream in(filename);
        string line;
        while (getline(in, line)) {
            // Loại bỏ khoảng trắng đầu/cuối dòng
            line.erase(0, line.find_first_not_of(" \t\r\n"));
            line.erase(line.find_last_not_of(" \t\r\n") + 1);
            if (line.empty()) continue;
            vector<string> tokens;
            istringstream iss(line);
            string token;
            while (iss >> token) tokens.push_back(token);
            int n = tokens.size();
            double st = 8.0, et = 12.0;
            double x = 0, y = 0;
            string name = "";
            if (n >= 5 && (isdigit(tokens[n-4][0]) || tokens[n-4][0] == '-' || tokens[n-4][0] == '.')) {
                // ... tên ... x y st et
                try {
                    x = stod(tokens[n-4]);
                    y = stod(tokens[n-3]);
                    st = stod(tokens[n-2]);
                    et = stod(tokens[n-1]);
                } catch (...) { continue; }
                for (int i = 0; i < n-4; ++i) {
                    if (i > 0) name += " ";
                    name += tokens[i];
                }
                manual_points.push_back({x, y, name, st, et});
            } else if (n >= 3 && (isdigit(tokens[n-2][0]) || tokens[n-2][0] == '-' || tokens[n-2][0] == '.')) {
                // ... tên ... x y
                try {
                    x = stod(tokens[n-2]);
                    y = stod(tokens[n-1]);
                } catch (...) { continue; }
                for (int i = 0; i < n-2; ++i) {
                    if (i > 0) name += " ";
                    name += tokens[i];
                }
                manual_points.push_back({x, y, name, st, et});
            } else if (n == 2 && (isdigit(tokens[0][0]) || tokens[0][0] == '-' || tokens[0][0] == '.')) {
                // x y
                try {
                    x = stod(tokens[0]);
                    y = stod(tokens[1]);
                } catch (...) { continue; }
                manual_points.push_back({x, y, "", st, et});
            } else {
                // Chỉ có tên, lấy từ OSM
                name = line;
                inputs.push_back({name, {0, 0}});
            }
        }
    }

    vector<Point> points;
    if (!manual_points.empty()) {
        points = manual_points;
    } else {
        points = fetch_coordinates_from_osm(inputs);
    }
    if (points.size() < 2) {
        cerr << "Error: Failed to fetch enough coordinates.\n";
        return 1;
    }

    auto greedy = greedy_tsp(points);
    auto greedy_info = calculate_route_info(points, greedy.first);
    auto optimized = two_opt_optimize(points, greedy.first);
    auto optimized_info = calculate_route_info(points, optimized.first);

    cout << "\nGreedy route:\n";
    for (int i : greedy_info.route) cout << i << "(" << points[i].name << ") ";
    cout << "\nDistance: " << greedy_info.total_distance << " degrees\n";
    cout << "Total Time: " << greedy_info.total_time << " hours\n";
    cout << "Total Cost: " << greedy_info.total_cost << " units\n";
    cout << "Time Feasible: " << (greedy_info.time_feasible ? "Yes" : "No") << endl;

    cout << "\n2-opt optimized route:\n";
    for (int i : optimized_info.route) cout << i << "(" << points[i].name << ") ";
    cout << "\nDistance: " << optimized_info.total_distance << " degrees\n";
    cout << "Total Time: " << optimized_info.total_time << " hours\n";
    cout << "Total Cost: " << optimized_info.total_cost << " units\n";
    cout << "Time Feasible: " << (optimized_info.time_feasible ? "Yes" : "No") << endl;

    system("pause");
    ofstream out("tsp_result.csv");
    out << "Name,Longitude,Latitude,StartTime,EndTime\n";
    for (int idx : optimized_info.route) {
        out << points[idx].name << "," << points[idx].x << "," << points[idx].y << ","
            << points[idx].start_time << "," << points[idx].end_time << "\n";
    }
    out.close();

    return 0;
}