#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric>

using namespace std;

unsigned long long combination(int n, int k) {
    if (k < 0 || k > n) return 0;
    k = min(k, n - k);
    unsigned long long result = 1;
    for (int i = 1; i <= k; ++i) {
        result = result * (n - i + 1) / i;
    }
    return result;
}

vector<vector<unsigned long long>> pascal_triangle(int n) {
    vector<vector<unsigned long long>> triangle(n + 1);
    for (int k = 0; k <= n; ++k) {
        triangle[k].resize(k + 1);
        for (int j = 0; j <= k; ++j) {
            triangle[k][j] = combination(k, j);
        }
    }
    return triangle;
}

void print_pascal_triangle(const vector<vector<unsigned long long>>& triangle) {
    cout << "Tam giac Pascal:\n";
    int max_width = 0;
    for (const auto& row : triangle) {
        for (auto num : row) {
            max_width = max(max_width, (int)to_string(num).length());
        }
    }
    for (int i = 0; i < triangle.size(); ++i) {
        string row_str;
        for (auto num : triangle[i]) {
            row_str += to_string(num) + string(max_width - to_string(num).length() + 1, ' ');
        }
        cout << string((triangle.size() - i - 1) * (max_width + 1) / 2, ' ') << row_str << endl;
    }
}

string binomial_expansion(int n, string a = "a", string b = "b") {
    vector<string> terms;
    for (int k = 0; k <= n; ++k) {
        unsigned long long coef = combination(n, k);
        int power_a = n - k;
        int power_b = k;
        string term = to_string(coef);
        if (power_a > 0) term += "*" + a + (power_a > 1 ? "^" + to_string(power_a) : "");
        if (power_b > 0) term += "*" + b + (power_b > 1 ? "^" + to_string(power_b) : "");
        terms.push_back(term);
    }
    string result;
    for (int i = 0; i < terms.size(); ++i) {
        result += terms[i];
        if (i < terms.size() - 1) result += " + ";
    }
    return result;
}

string trinomial_expansion(int n, string a = "a", string b = "b", string c = "c") {
    vector<string> terms;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n - i; ++j) {
            int k = n - i - j;
            unsigned long long coef = combination(n, i) * combination(n - i, j);
            string term = to_string(coef);
            if (i > 0) term += "*" + a + (i > 1 ? "^" + to_string(i) : "");
            if (j > 0) term += "*" + b + (j > 1 ? "^" + to_string(j) : "");
            if (k > 0) term += "*" + c + (k > 1 ? "^" + to_string(k) : "");
            terms.push_back(term);
        }
    }
    string result;
    for (int i = 0; i < terms.size(); ++i) {
        result += terms[i];
        if (i < terms.size() - 1) result += " + ";
    }
    return result;
}

void generate_indices(int m, int n, int sum, vector<int>& current, vector<vector<int>>& indices) {
    if (m == 1) {
        current.push_back(n - sum);
        indices.push_back(current);
        current.pop_back();
        return;
    }
    for (int i = 0; i <= n - sum; ++i) {
        current.push_back(i);
        generate_indices(m - 1, n, sum + i, current, indices);
        current.pop_back();
    }
}

string multinomial_expansion(int n, int m, vector<string> terms = {}) {
    if (terms.empty()) {
        for (int i = 1; i <= m; ++i) {
            terms.push_back("a_" + to_string(i));
        }
    }
    vector<vector<int>> indices;
    vector<int> current;
    generate_indices(m, n, 0, current, indices);
    
    vector<string> result_terms;
    for (const auto& idx : indices) {
        unsigned long long coef = combination(n, idx[0]);
        for (int i = 1; i < idx.size(); ++i) {
            coef *= combination(n - accumulate(idx.begin(), idx.begin() + i, 0), idx[i]);
        }
        string term = to_string(coef);
        for (int i = 0; i < idx.size(); ++i) {
            if (idx[i] > 0) {
                term += "*" + terms[i] + (idx[i] > 1 ? "^" + to_string(idx[i]) : "");
            }
        }
        result_terms.push_back(term);
    }
    
    string result;
    for (int i = 0; i < result_terms.size(); ++i) {
        result += result_terms[i];
        if (i < result_terms.size() - 1) result += " + ";
    }
    return result;
}

int main() {
    int n = 4;
    int m = 3;

    auto triangle = pascal_triangle(n);
    print_pascal_triangle(triangle);

    cout << "\nMo rong (a + b)^" << n << ":\n";
    cout << binomial_expansion(n) << endl;

    cout << "\nMo rong (a + b + c)^" << n << ":\n";
    cout << trinomial_expansion(n) << endl;

    cout << "\nMo rong (a_1 + a_2 + ... + a_" << m << ")^" << n << ":\n";
    cout << multinomial_expansion(n, m) << endl;

    return 0;
}