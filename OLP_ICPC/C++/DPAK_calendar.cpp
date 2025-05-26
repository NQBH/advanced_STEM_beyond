/*
Source: New Zealand Contest 1993.
IDs for online judges: UVA 158. 
Status: Wrong Answer
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct event{
    int day;
    int month;
    int important;
    string name;
    int idxInput; 
};

bool compare(const event &x, const event &y) {
    if (x.month != y.month) {
        return x.month < y.month;
    }
    if (x.day != y.day) {
        return x.day < y.day;
    }
    if (x.important != y.important) {
        return x.important > y.important;
    }
    return x.idxInput < y.idxInput;
}

int get_day_in_month(int month, bool leap) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    }
    else if (month == 2) {
        if (leap) {
            return 29;
        }
        else return 28;
    }
    else {
        return 30;
    }
}

int main(){
    vector<event> a;
    int year; cin >> year;
    char c;

    bool leap = (year % 4 == 0);

    int indexInput = 0;
    while (cin >> c && c != '#') {
        if (c == 'A') {
            int day, month, important;
            string name;
            cin >> day >> month >> important;
            cin.ignore();
            getline(cin, name);
            a.push_back({day, month, important, name, indexInput});
            indexInput++;
        }
        else if (c == 'D') {
            int day, month;
            cin >> day >> month;
            cout << "Today is: " << day << " " << month << endl;
            sort(a.begin(), a.end(), compare);
            int idx = 0;
            while (idx < a.size()) {
                if (a[idx].day == day && a[idx].month == month) {
                    break;
                }
                idx++;
            }
            if (idx == a.size()) idx = 0;

            for (int i = idx; i < a.size(); i++) {

                if (a[i].day == day && a[i].month == month) {
                    cout << a[i].day << " " << a[i].month << " ";
                    cout << "*TODAY* " <<a[i].name << endl;
                }
                else {
                    int day_diff = 0;
                    
                    for (int j = month; j < a[i].month; j++) {
                        day_diff += get_day_in_month(j,leap);
                    }
                    day_diff += a[i].day;
                    day_diff -= day;

                    if (day_diff >= 1 && day_diff <= 7) {
                        cout << "   " << a[i].day << " " << a[i].month << " ";
                        for (int j = day_diff; j <= a[i].important; j++){
                            cout << "*";
                        }
                        cout << " " << a[i].name << endl;
                    }
                }
            }
            cout << endl;
        }
    }
}