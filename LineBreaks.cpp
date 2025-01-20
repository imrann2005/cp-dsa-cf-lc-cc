#include <bits/stdc++.h>
using namespace std;
void solve(int n, int m, vector<string> &vec)
{
    int cnt = 0;
    for (auto &s : vec)
    {
        m -= s.length();
        if (m < 0)
            break;
        else
            cnt++;


    }

    cout << cnt << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> vec;
        string temp;
        for (int i = 0; i < n; i++)
        {
            cin>>temp;
            vec.push_back(temp);
        }
        solve(n, m, vec);
    }
    return 0;
}