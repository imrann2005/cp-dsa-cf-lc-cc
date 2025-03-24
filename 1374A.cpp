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
    int c3 = 0, c2 = 0;
    while (n % 3 == 0)
    {
        c3++;
        n = n / 3;
    }
    while (n % 2 == 0)
    {
        c2++;
        n = n / 2;
    }
    if (n == 1)
    {
        if (c2 > c3)
        {
            cout << -1 << endl;
            return;
        }
        int ops = 0;
        ops += c3;
        ops += c3 - c2;
        cout << ops << endl;
    }
    else
    {
        cout << -1 << endl;
    }
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