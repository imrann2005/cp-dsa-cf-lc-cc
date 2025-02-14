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

void solve(vi&a,int n,int k) {
    // Write your solution here
    if(n==1){
        cout<<0<<endl;
        return;
    }
    sort(all(a));
    int l=0;
    int r=1;
    int mx = 0;
    while (r < n)
    {
        if((a[r]-a[r-1]) <= k){
            mx = max(mx,r-l+1);
            
        }
        else{
            l=r;
            mx = max(mx,r-l+1);
        }
        r++;
    }
    cout<<n-mx<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solve(a,n,k);
    }

    return 0;
}