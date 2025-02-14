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

ll smallestGrtEquNum(vll &b, ll n, ll num)
{
    auto it = lower_bound(b.begin(), b.end(), num);
    if (it == b.end())
    {
        return -1;
    }
    return *it;
}

void solve(vll &a, vll &b, ll n, ll m)
{
    // Write your solution here
    sort(all(b));
    
    ll prev = LLONG_MIN;

    for (int i = 0; i < n; i++)
    {

        ll b1 = smallestGrtEquNum(b, m, prev + a[i]);
        if (b1 != -1)
        {
            if(a[i] < prev){
                a[i] = b1-a[i];
            }
            else{
                a[i] = min(a[i],b1-a[i]);
            }

        }

        if (a[i] < prev)
        {
            no;
           
            return;
        }
        prev = a[i];
    }
    yes;
   
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vll a(n);
        vll b(m);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        solve(a, b, n, m);
    }

    return 0;
}