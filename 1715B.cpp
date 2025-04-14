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

void solve(ll n, ll k, ll b, ll s)
{
    // Write your solution here
    ll mx = b * k;
    vll a(n, 0);
    a[0] = mx;
    s -= mx;
    if (s < 0)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            int n = min(s,k-1);
            a[i] += n;
            s -= n;
        }
        if(s > 0){
            cout<<-1<<endl;
        }
        else{
            for (int i = 0; i < n; ++i) cout << a[i] << " ";
                cout << "\n";
        }
    }
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, b, s;
        cin >> n >> k >> b >> s;
        solve(n, k, b, s);
    }

    return 0;
}