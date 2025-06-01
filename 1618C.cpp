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

void solve(vll &a, ll n)
{
    // Write your solution here
    ll d1 = a[0]; // 0,2,4,even idx
    ll d2 = a[1];

    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            d2 = __gcd(d2, a[i]);
        }
        else
            d1 = __gcd(d1, a[i]);
    }
    int f1 = 1, f2 = 1;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            // odd
            if ((a[i] % d1) == 0)
            {
                f1 = 0;
            }
        }
        else
        {
            /// even
            if ((a[i] % d2) == 0)
            {
                f2 = 0;
            }
        }
    }
    if (f1 && !f2)
        cout << d1 << endl;
    else if (!f1 && f2)
        cout << d2 << endl;
    else if (f1 && f2)
        cout << max(d1, d2) << endl;
    else
        cout << 0 << endl;
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
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(a, n);
    }

    return 0;
}