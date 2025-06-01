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

void solve(ll n,ll x,ll y) {
    // Write your solution here
    ll g = __gcd(x,y);
    ll lcm = (1LL*x*y)/g;
    int cm  = n/lcm;
    ll x1 = (n/x)-cm;
    ll y1 = (n/y)-cm;
    ll t1 = ((n)*(n+1))/2;
    t1 = t1 - (((n-x1)*(n-x1+1))/2);
    ll t2 = (y1*(y1+1))/2;

    cout<<t1-t2<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll n,x,y;
        cin>>n>>x>>y;
        solve(n,x,y);
    }

    return 0;
}