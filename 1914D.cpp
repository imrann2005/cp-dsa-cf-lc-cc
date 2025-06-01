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

bool comp(pair<ll, ll> &p1, pair<ll, ll> &p2)
{
    return p1.first > p2.first;
}

void solve(vll &a, vll &b, vll &c, ll n)
{
    // Write your solution here
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>>mxhA;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>>mxhB;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>>mxhC;
    for (int i = 0; i < n; i++)
    {
        mxhA.push({a[i],i});
        mxhB.push({b[i],i});
        mxhC.push({c[i],i});
        if(mxhA.size() > 3){
            mxhA.pop();
        }
        if(mxhB.size() > 3){
            mxhB.pop();
        }
        if(mxhC.size() > 3){
            mxhC.pop();
        }
    }
    ll s = 0;
    vll a1(3);
    vll b1(3);
    vll c1(3);
    for (int i = 0; i < 3; i++)
    {
        a1[i] = mxhA.top().second;
        b1[i] = mxhB.top().second;
        c1[i] = mxhC.top().second;
        mxhA.pop();
        mxhB.pop();
        mxhC.pop();
    }
    
    for (auto& i : a1)
    {
        for (auto&j : b1)
        {
            for (auto &k : c1)
            {
                if(i!=j && j!=k && i!=k){
                    s = max(s,a[i]+b[j]+c[k]);
                }
            }
            
        }
        
    }

    cout<<s<<endl;
    
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll a(n);
        vll b(n);
        vll c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }

        solve(a, b, c, n);
    }

    return 0;
}