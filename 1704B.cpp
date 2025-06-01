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

void solveB(vi &a, int n, int x)
{
    // Write your solution here
    int mx = a[0] + x;
    int mn = a[0] - x;
    int i = 1;
    int cnt = 0;
    while (i < n)
    {
        int l = a[i] - x;
        int r = a[i] + x;
        if ((l > mx) || (r < mn))
        {
            cnt++;
            mx = r;
            mn = l;
        }
        mn = max(l,mn);
        mx = min(mx,r);
        i++;
    }
    cout << cnt << endl;
}

void solveC(vll&a,ll n,ll m){
    if(n == m){
        cout<<m<<endl;
        return;
    }
    sort(all(a));
    vll d(m);
    d[0] = (n - (a[m-1]-a[0])) - 1;
    for (int i = 1; i < m; i++)
    {
        d[i] = a[i] - a[i-1] - 1;
    }
    sort(all(d),greater<ll>());
    ll i = 0;
    ll pcnt = 0;
    // for (int i = 0; i < m; i++)
    // {
    //     cout<<d[i]<<"\t";
    // }
    // cout<<endl;
    while (i<m)
    {
        /* code */
        d[i] = d[i] - 4*i;
        if(d[i] <= 0){
            break;
        }
        // cout<<d[i]-1<<"\t";
        pcnt += max(1LL,d[i]-1);
        i++;
    }
    // cout<<pcnt<<endl;
    ll ans = n - pcnt;
    cout<<ans<<endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        // int n, x;
        // cin >> n >> x;
        // vi a(n);
        // for (int i = 0; i < n; i++)
        // {
        //     cin >> a[i];
        // }

        // solveB(a, n, x);
        ll n,m;
        cin>>n>>m;
        vll a(m);
        for (ll i = 0; i < m; i++)
        {
            cin>>a[i];
        }
        solveC(a,n,m);
    }

    return 0;
}