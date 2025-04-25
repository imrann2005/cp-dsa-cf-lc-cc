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

bool works(vll&a,ll n,ll w,ll x){
    ll s = 0;
    for (ll i = 0; i < n; i++)
    {
        s += (x-a[i] >= 0) ? x-a[i] : 0;
    }
    if(s <= w){
        return true;
    }
    return false;
}

void solve(vll&a,ll n,ll w) {
    // Write your solution here
    ll l = 1;
    ll h = w+1e9;
    while (l <= h)
    {
        ll mid = (l+h)>>1;
        if(works(a,n,w,mid)){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }

    cout<<h<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll n,w;
        cin >> n >> w;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        solve(a,n,w);
    }

    return 0;
}