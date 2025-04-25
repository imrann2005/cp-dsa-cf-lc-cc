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

void solve(vi &a, vi &b, int n)
{
    // Write your solution here
    sort(all(a));
    sort(all(b), greater<int>());
    int i = 0;
    int d = 0;
    ll ans = 1;
    while (i < n)
    {
        int num = b[i];
        auto it = lower_bound(all(a), num);
        if (it!=a.end() && num <= (*it))
        {
            int val = *it;
            int idx = it - a.begin();
            if (num == val)
            {
                ll cnt = 1LL*(n-1-idx-d);
                ans = (ans*cnt)%MOD;
            }
            else
            {
                ll cnt = 1LL * (n-1 - idx + 1 - d);
                ans = (ans*cnt)%MOD;
            }
            d++;
        }
        else{
            cout<<0<<endl;
            return;
        }
        i++;
    }
    cout<<ans<<endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
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

        solve(a, b, n);
    }

    return 0;
}