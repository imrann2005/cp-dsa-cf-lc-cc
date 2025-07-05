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
    int cnt = 0;
    map<int,int>mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[a[i]] = i+1;
    }
    
    for(int i=0;i<n;i++){
        ll num = a[i];
        ll idx = i+1;
        for (int j = num; j <= 2*n; j+=num)
        {
            if(j-idx > 0 && (j-idx)>idx && mpp[j/num]==j-idx){
                cnt++;
            }
        }
        
    }
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