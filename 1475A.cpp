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

void solve(ll n)
{
    // Write your solution here
    if (n & 1)
    {
        yes;
        return;
    }
    int i = 0;
    while (i < 64 && n > 1)
    {
        /* code */
        if (((n >> i) > 1) && ((n >> i) & 1))
        {
            yes;
            return;
        }

        i++;
    }
    no;
    return;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        solve(n);
    }

    return 0;
}