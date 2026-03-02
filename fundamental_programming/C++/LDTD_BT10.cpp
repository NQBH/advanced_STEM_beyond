#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Bạn muốn nhập bao nhiêu số? Nhập n: ";
    cin >> n;

    for (int i = 0; i <= n; i++) {
        cout << i << " trong tiếng Anh là: ";

        switch (i) {
            case 0: cout << "Zero"; break;
            case 1: cout << "One"; break;
            case 2: cout << "Two"; break;
            case 3: cout << "Three"; break;
            case 4: cout << "Four"; break;
            case 5: cout << "Five"; break;
            case 6: cout << "Six"; break;
            case 7: cout << "Seven"; break;
            case 8: cout << "Eight"; break;
            case 9: cout << "Nine"; break;
            case 10: cout << "Ten"; break;
            case 11: cout << "Eleven"; break;
            case 12: cout << "Twelve"; break;
            case 13: cout << "Thirteen"; break;
            case 14: cout << "Fourteen"; break;
            case 15: cout << "Fifteen"; break;
            case 16: cout << "Sixteen"; break;
            case 17: cout << "Seventeen"; break;
            case 18: cout << "Eighteen"; break;
            case 19: cout << "Nineteen"; break;
            case 20: cout << "Twenty"; break;
            
            default: 
                cout << "Số này lớn quá, chưa có kết quả!"; 
                break;
        }
        cout << endl; 
    }

    return 0;
}