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

bool works(vector<vector<ll>>&a,ll n,ll k){
    ll x=0,y=0;
    for(int i=0;i<n;i++){
        x = max(x-k,a[i][0]);
        y = min(y+k,a[i][1]);

        if(x>y){
            return false;
        }
    }
    return true;
}

void solve() {
    // Write your solution here
    ll n;
    cin>>n;
    vector<vector<ll>>a;
    for (int i = 0; i < n; i++)
    {
        /* code */
        int x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }

    ll l = 0;
    ll h = 1e9;

    while (l<=h)
    {
        /* code */

        ll mid = (l+h)>>1;
        if(works(a,n,mid)){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<l<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}