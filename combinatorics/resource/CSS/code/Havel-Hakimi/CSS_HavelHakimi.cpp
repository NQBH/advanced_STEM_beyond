#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string is_graphical_sequence(int n, vector<int>& seq) {
    long long sum = 0;
    for (int x : seq) {
        if (x < 0) return "0";
        sum += x;
    }
    if (sum % 2 != 0) return "0";

    vector<int> sequence = seq;
    sort(sequence.rbegin(), sequence.rend());

    while (!sequence.empty() && sequence[0] > 0) {
        int d = sequence[0]; 
        sequence.erase(sequence.begin()); 

        if (d > sequence.size()) return "0";

        for (int i = 0; i < d; ++i) {
            sequence[i]--;
        }

        for (int x : sequence) {
            if (x < 0) return "0";
        }
        sort(sequence.rbegin(), sequence.rend());
        while (!sequence.empty() && sequence.back() == 0) {
            sequence.pop_back();
        }
    }

    if (sequence.empty()) return "1";
    string result;
    for (int i = 0; i < sequence.size(); ++i) {
        result += to_string(sequence[i]);
        if (i < sequence.size() - 1) result += " ";
    }
    return result;
}

int main() {
    int t;
    cin >> t; 
    vector<string> results;

    while (t--) {
        int n;
        cin >> n; 
        vector<int> sequence(n);
        for (int i = 0; i < n; ++i) {
            cin >> sequence[i]; 
        }
        results.push_back(is_graphical_sequence(n, sequence));
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}