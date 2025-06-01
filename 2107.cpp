#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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

void solveA(vll&a,ll n) {
    // Write your solution here
    vector<pair<ll,ll>>v;
    for (int i = 0; i < n; i++)
    {
        v.pb({a[i],i});
    }
    sort(all(v));
    ll g1 = v[n-1].first;
    ll g = v[0].first;
    for (int i = 0; i < n-1; i++)
    {
        ll x = v[i].first;
        g = __gcd(g,x);
    }
    if(g==g1){
        no;
        return;
    }
    yes;
    ll mx = v[n-1].second;
    for (int i = 0; i < n; i++)
    {
        if(i==mx){
            cout<<2<<" ";
        }
        else cout<<1<<" ";
    }
    cout<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin>>n;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        

        solveA(a,n);
    }

    return 0;
}