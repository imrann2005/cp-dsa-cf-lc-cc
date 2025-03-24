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

void solve(vll&a,ll n) {
    // Write your solution here
    ll i=n-2;
    ll j=n-1;
    ll num = a[i]+a[j]-1;
    i--;
    while (i>=0)
    {
        /* code */
        num = num+a[i]-1;
        i--;
    }
    cout<<num<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vll a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        if(n==1){
            cout<<a[0]<<endl;
            
        }
        else solve(a,n);
    }

    return 0;
}