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

void solve(ll a, ll b)
{
    // Write your solution here
    if (b > a)
    {
        cout << 1 << endl;
        return;
    }
    if (b == a)
    {
        cout << 2 << endl;
        return;
    }
    ll ans = 1e9;
    for (int i = 0; i <= 7; i++)
    {
        /* code */
        if (b + i >= 2)
        {
            ll x = a;
            ll t = i;

            while (x > 0)
            {
                t++;
                x = x / (b + i);
            }

            ans = min(ans, t );
        }
    }

    cout << ans << endl;
}

int main()
{
    fast_io;
    // cout<<((double)log(571787) / (double)log(83))+1<<endl;
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }

    return 0;
}