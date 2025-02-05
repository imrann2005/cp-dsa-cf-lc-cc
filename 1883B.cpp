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

void solve(string &s, int n, int k)
{
    // Write your solution here
    map<char, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[s[i]]++;
    }
    int odds = 0;
    for (auto &it : mpp)
    {
        if (it.second & 1)
            odds++;
    }
  
    int f = n - k;
    if (f == 1)
    {
        yes;
        return;
    }
    if (f & 1)
    {
        /*odd*/
        if (odds - k <= 1)
        {
            yes;
            return;
        }
        no;
    }
    else
    {
        /* even */
        if (odds - k <= 0)
        {
            yes;
            return;
        }
        no;
    }
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        solve(s, n, k);
    }

    return 0;
}