#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        char o = 0;
        if (count(s.begin(), s.end(), '?') == s.size()) o = 'B';
        else
        {
            int i = 0;
            for (; s[i] == '?'; i++);
            while (--i != -1)s[i] = 'B' + 'R' - s[i + 1];
        }
        for (auto &v : s)
        {
            if (v == '?') v = 'B' + 'R' - o;
            o = v;
        }
        cout << s << endl;
    }
}
