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

void solveC(vll&a,ll n,ll k,ll x) {
    // Write your solution here
    sort(all(a));
    vll v;
    for (ll i = 1; i < n; i++)
    {
        ll diff = a[i]-a[i-1];
        if(diff > x){
            ll a = (diff-1)/x;
            //cout<<a<<endl;
            v.pb(a);
        }
    }
    sort(all(v));
    ll grp = v.size();
    if(grp == 0){
        cout<<1<<endl;
        return;
    }
    else if(k==0){
        cout<<grp+1<<endl;
        return;
    }
    else{
        ll s = 0;
        ll i = 0;
        for ( i = 0; i < grp && k>0; i++)
        {
            /* code */
            s += v[i];
            if(s == k){
                break;
            }
            else if(s > k){
                i--;
                break;
            }
        }
        //cout<<i<<endl;
        if(i==grp)i--;
        cout<<1+(grp-(i+1))<<endl;
        return;
    }
}

int main() {
    fast_io;

    // int t;
    // cin >> t;
    // while (t--) {
        ll n,k,x;
        cin>>n>>k>>x;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solveC(a,n,k,x);
    //}

    return 0;
}