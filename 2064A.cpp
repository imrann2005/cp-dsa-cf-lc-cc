#include <bits/stdc++.h>
using namespace std;

#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve(string &s, int n)
{
    // Write your solution here
    int cnt = 0;
    int ops = 0;
    bool z = 0;
    string t;
    int i = n - 1;
    while (i >= 0)
    {
        if (s[i] == '0')
        {
            if (cnt > 0)
            {
                if (z)
                {
                    ops += 2;
                }
                else
                {
                    ops += 1;
                }
                string sub = s.substr(i + 1, s.length() - i - 1);
                s.erase(i + 1, s.length() - i - 1);
                t += sub;
                int j = t.length() - 1;
                while (t[j] == '0')
                {
                    s.pb(t[j]);
                    t.pop_back();
                    j--;
                    i++;
                }
                cnt = 0;
                z = 0;
                i++;
            }
            z = 1;
        }
        else
        {
            cnt++;
        }
        i--;
    }
    if (cnt > 0)
    {
        if (z)
        {
            ops += 2;
        }
        else
        {
            ops += 1;
        }
        string sub = s.substr(0, s.length());
        s.erase(0,s.length());
        t += sub;
        int j = t.length() - 1;
        while (t[j] == '0')
        {
            s.pb(t[j]);
            t.pop_back();
            j--;
            i++;
        }
       
    }
    cout << ops << endl;
}
    int main()
    {
        fast_io;

        int t;
        cin >> t;
        while (t--)
        {
            int n;
            cin >> n;
            string s;
            cin >> s;
            solve(s, n);
        }

        return 0;
    }