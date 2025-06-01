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

bool f(vll&a,ll n,ll x){
    ll s = x;
    ll t = a[s];
    ll cnt = 0;
    while (s < n)
    {
        /* code */
        if(a[s] != t){
            cnt++;
        }
        s += (x+1);
    }
    if(cnt <= 1)return true;
    return false;
}

void solveB(vll&a,ll n) {
    // Write your solution here
    ll l = 0;
    ll h = n-1;
    while (l <= h)
    {
        ll m = (l+h)>>1;
        if(f(a,n,m)){
            h = m-1;
        }
        else l = m+1;
    }
    cout<<l<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll n,k;
        cin>>n;
        cin>>k;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solveB(a,n);
    }

    return 0;
}