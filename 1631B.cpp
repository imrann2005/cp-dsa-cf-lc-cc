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

void solve(vll&a,int n) {
    // Write your solution here
    ll m = n/2;
    ll i=n-1;
    ll x = a[n-1];
    ll cnt = 0;
    while (i>=)
    {
        if(a[i] != x){
            cnt++;
         
        }
        else i--;
    }
    for (int i = 0; i < m; i++)
    {
        if(a[i] != x){
            cnt++;
            break;
        }
    }
    cout<<cnt<<endl;

}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solve(a,n);
    }

    return 0;
}