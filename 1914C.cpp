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

void solve(vi &a, vi &b, int n, int k)
{
    // Write your solution here
    vi pre(n);
    int mx = b[0];
    pre[0] = mx;
    for (int i = 1; i < n; i++)
    {
        mx = max(mx, b[i]);
        pre[i] = mx;
    }
    ll s = 0;
    ll mx2 = -1;
    for (int i = 0; i < n; i++)
    {
        if(i >= k) break;
        s += a[i];
        ll ans = s + 1LL*((ll)pre[i]*(ll)(k-i-1));
        mx2 = max(ans,mx2);
    }

    cout<<mx2<<endl;
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
        vi a(n);
        vi b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        
        solve(a, b, n, k);
    }

    return 0;
}