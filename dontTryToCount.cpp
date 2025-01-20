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

void solve(string s, string x)
{
    // Write your solution here
    int cnt = 6;
    int ans = 0;
    while (cnt>0)
    {
        if (x.find(s) != string ::npos)
        {
            cout << ans << endl;
            return;
        }
        ans++;
        cnt--;
        x += x;
    }
    cout << -1 << endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        string s;
        string x;
        cin >> n >> m;
        cin >> x;
        cin >> s;

        solve(s, x);
    }

    return 0;
}