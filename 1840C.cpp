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

void solve(vll&a,ll n,ll k,ll q) {
    // Write your solution here
    int i=0,j=0;
    ll cnt = 0;
    while (j < n)
    {
        if(a[j] <= q){
            int len = j-i+1;
            if(len >= k){
                cnt ++;
                cnt += len-k;
            }
        }
        else{
            i = j;
            i++;
        }
        j++;
    }

    cout<<cnt<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll n,k,q;
        cin >> n>> k>>q;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        solve(a,n,k,q);
    }

    return 0;
}