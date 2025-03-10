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

void solve(ll x, ll n)
{
    ll d = 0;

    // The value of `d` depends on `n % 4`
    if (n % 4 == 0)
    {
        d = 0;
    }
    else if (n % 4 == 1)
    {
        d = -n;
    }
    else if (n % 4 == 2)
    {
        d = 1;
    }
    else if (n % 4 == 3)
    {
        d = n + 1;
    }

    // Now handle the direction of the jump based on the parity of x
    if (x & 1) // If x is odd, jump right
    {
        d = x - d;
        cout << d << endl;
        return;
    }
    else // If x is even, jump left
    {
        d = x + d;
        cout << d << endl;
    }
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll x, n;
        cin >> x >> n;
        solve(x, n);
    }

    return 0;
}
