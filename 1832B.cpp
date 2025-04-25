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

void solve(vll &a, ll n, ll k)
{

    // Write your solution here
    sort(all(a));
    vll pre(n);
    vll suff(n);
    ll s = 0;
    ll s3 = 0;
    for (ll i = 0; i < n; i++)
    {
        s += a[i];
        pre[i] = s;
    }
    for (ll i = n-1; i>=0; i--)
    {
        /* code */
        s3 += a[i];
        suff[i] = s3;
    }
    int mn = 2*k-1;
    int mx = n-1;
    ll maxi = 0;
    for (int i = 0; i <= k; i++)
    {
        /* code */
        ll mn1 = 0;
        ll mx1=0;
        if(i!=k){
            mn1 = pre[mn];
            mn-=2;
        }
        if(i!=0){
            mx1 = suff[mx];
            mx--;
        }
        maxi = max(maxi,s-(mn1+mx1));
    }
    cout<<maxi<<endl;
   
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(a, n, k);
    }

    return 0;
}