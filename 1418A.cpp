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

void solve(ll x,ll y,ll k) {
    // Write your solution here
    ll s = k*y + k;
    s--;
    ll n;
    ll xtra = x-1;
    if(s % xtra == 0){
        n = s/xtra;
    }
    else{
        n = s/xtra;
        n++;
    }

    cout<<n+k<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll x,y,k;
        cin>>x>>y>>k;
        solve(x,y,k);
    }

    return 0;
}