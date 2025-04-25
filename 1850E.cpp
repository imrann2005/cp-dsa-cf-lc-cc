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

long double works(vi&a,ll n,ll x){
    long double s = 0;
    for (ll i = 0; i < n; i++)
    {
        s += 1LL*(a[i]+2*x)*(a[i]+2*x);
    }
    return s;
}

void solve(vi&a,ll n,ll c) {
    // Write your solution here
    ll l = 1;
    ll h = 1e9;
    while (l <= h)
    {
        ll mid = (l+h)>>1;
        long double x = works(a,n,mid);
        if(x == c){
            cout<<mid<<endl;
            return;
        }
        if(x < c){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll n,c;
        cin>>n>>c;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        solve(a,n,c);
    }

    return 0;
}