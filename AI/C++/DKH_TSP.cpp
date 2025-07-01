#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

// Hàm tính khoảng cách giữa hai thành phố
double tinhKhoangCach(const pair<double, double>& thanhPho1, const pair<double, double>& thanhPho2) {
    double dx = thanhPho1.first - thanhPho2.first;
    double dy = thanhPho1.second - thanhPho2.second;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    // Danh sách các thành phố (tọa độ x, y)
    vector<pair<double, double>> danhSachThanhPho = {
        {0, 0}, {1, 5}, {4, 2}, {7, 8}, {5, 0}, {2, 6}
    };
    int soThanhPho = danhSachThanhPho.size();

    // Chu trình ngắn nhất tìm được
    vector<int> chuTrinhNganNhat;
    double doDaiChuTrinhNganNhat = numeric_limits<double>::max();

    // Bắt đầu từ mỗi thành phố như là điểm xuất phát
    for (int diemBatDau = 0; diemBatDau < soThanhPho; ++diemBatDau) {
        vector<int> chuTrinhHienTai;
        vector<bool> daTham(soThanhPho, false);
        double doDaiHienTai = 0;

        int thanhPhoHienTai = diemBatDau;
        chuTrinhHienTai.push_back(thanhPhoHienTai);
        daTham[thanhPhoHienTai] = true;

        // Xây dựng chu trình
        for (int i = 0; i < soThanhPho - 1; ++i) {
            int thanhPhoTiepTheo = -1;
            double khoangCachNhoNhat = numeric_limits<double>::max();

            for (int j = 0; j < soThanhPho; ++j) {
                if (!daTham[j]) {
                    double khoangCach = tinhKhoangCach(danhSachThanhPho[thanhPhoHienTai], danhSachThanhPho[j]);
                    if (khoangCach < khoangCachNhoNhat) {
                        khoangCachNhoNhat = khoangCach;
                        thanhPhoTiepTheo = j;
                    }
                }
            }
            if (thanhPhoTiepTheo != -1) {
                chuTrinhHienTai.push_back(thanhPhoTiepTheo);
                daTham[thanhPhoTiepTheo] = true;
                doDaiHienTai += khoangCachNhoNhat;
                thanhPhoHienTai = thanhPhoTiepTheo;
            }
        }

        // Quay về thành phố xuất phát để hoàn thành chu trình
        doDaiHienTai += tinhKhoangCach(danhSachThanhPho[chuTrinhHienTai.back()], danhSachThanhPho[diemBatDau]);
        chuTrinhHienTai.push_back(diemBatDau);

        // Cập nhật chu trình ngắn nhất nếu tìm thấy
        if (doDaiHienTai < doDaiChuTrinhNganNhat) {
            doDaiChuTrinhNganNhat = doDaiHienTai;
            chuTrinhNganNhat = chuTrinhHienTai;
        }
    }

    // In kết quả
    cout << "Chu trinh ngan nhat theo heuristic Nearest Neighbor: ";
    for (int i = 0; i < chuTrinhNganNhat.size(); ++i) {
        cout << chuTrinhNganNhat[i] << (i == chuTrinhNganNhat.size() - 1 ? "" : " -> ");
    }
    cout << '\n';
    cout << "Do dai chu trinh: " << doDaiChuTrinhNganNhat << '\n';

    return 0;
}