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

bool comp(pair<ll, int> &p1, pair<ll, int> &p2)
{
    return p1.first > p2.first;
}

int bs(vector<pair<ll, int>> &b, int l, ll x,int n,vector<ll>&pre)
{
    int h = n-1;
    
    while (l <= h)
    {

        int mid = (l + h) >> 1;
        if (b[mid].first > x)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
            x = pre[mid];
        }
    }
    return h;
}

void display(vector<pair<ll, int>> &b, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << b[i].first << "," << b[i].second << " ";
    }
    cout << endl;
}

void display2(vector<ll> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void solve(vi &a, int n)
{
    vector<pair<ll, int>> b;
    for (int i = 0; i < n; i++)
    {
        b.pb({(ll)a[i], i});
    }

    vll pre(n);
    ll sum = 0;
    sort(all(b));
    for (int i = 0; i < n; i++)
    {
        sum += b[i].first;
        pre[i] = sum;
    }

    vi ans(n);
    ans[b[n-1].second] = n-1;
    for (int i = n-2; i >= 0; i--)
    {
        if(pre[i] >= b[i+1].first){
            ans[b[i].second] = ans[b[i+1].second];
        }
        else ans[b[i].second] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve(a, n);
    }

    return 0;
}
