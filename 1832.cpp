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
    int i=1;
    ll cnt = 1;
    while (i<n)
    {
        if(a[i] == a[i-1])i++;
        else if(a[i]>a[i-1]){
            while (i<n && a[i]>=a[i-1])
            {
                /* code */
                i++;
            }
            cnt++;
            
        }else{
            while (i<n && a[i]<=a[i-1])
            {
                /* code */
                i++;
            }
            cnt++;
        }
    }
    // if(cnt==1){
    //     cout<<0<<endl;
    //     return;
    // }
    cout<<cnt<<endl;
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
        
        solve(a,n);
    }

    return 0;
}