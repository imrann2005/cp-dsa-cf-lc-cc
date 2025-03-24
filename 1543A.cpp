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

void solve()
{
    // Write your solution here
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << " " << 0 << endl;
        }
        else
        {
            ll mini = min(a, b);
            ll a1 = a;
            ll b1 = b;
            ll g1 = __gcd(a1, b1);
            a = a - mini;
            b = b - mini;
            ll g = __gcd(a, b);
            if (g == g1)
            {
                cout << g << " " << 0 << endl;
            }
            else
            {
                ll ops = min((a1 % g), g - (b1 % g));
                cout << g << " " << ops << endl;
            }
        }

        // solve();
    }

    return 0;
}