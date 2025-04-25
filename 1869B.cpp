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

ll d(ll x1, ll x2, ll y1, ll y2)
{
    return (ll)abs(x1 - x2) + (ll)abs(y1 - y2);
}

void solve(vector<vll> &m, ll n, ll k, ll a, ll b)
{
    // Write your solution here
    ll mn = LLONG_MAX;
    ll d1 = d(m[a - 1][0], m[b - 1][0], m[a - 1][1], m[b - 1][1]);
    if(k==0){
        cout<<d1<<endl;
        return;
    }
    mn = min(d1, mn);
    ll db = LLONG_MAX;
    ll da = LLONG_MAX;
    if (a <= k)
        da = 0;
    if (b <= k)
        db = 0;
    for (int i = 0; i < k; i++)
    {
        if (a > k)
        {
            ll da1 = d(m[a - 1][0], m[i][0], m[a - 1][1], m[i][1]);
            da = min(da, da1);
        }
        if (b > k)
        {
            ll db1 = d(m[b - 1][0], m[i][0], m[b - 1][1], m[i][1]);
            db = min(db, db1);
        }
    }
    //cout<<d1<<endl;
    ll d2 = da + db;
    //cout<<d2<<endl;
    ll ans = min(d2, d1);
    cout << ans << endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, a, b;

        cin >> n >> k >> a >> b;
        vector<vll> m(n, vector<ll>(2, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> m[i][j];
            }
        }

        solve(m, n, k, a, b);
    }

    return 0;
}