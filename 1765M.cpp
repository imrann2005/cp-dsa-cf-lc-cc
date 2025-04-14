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

void solve(int n) {
    // Write your solution here
    if(n & 1){
        int mx = INT_MIN;
        int a=0,b=0;
      for (int i = 1; i <= n/2; i++)
      {
        if(__gcd(i,n-i) > mx){
            a = i;
            b = n-i;
        }
        mx = max(__gcd(i,n-i),mx);
      }
      cout<<a<<" "<<b<<endl;
        
    }
    else{
        int ans = n/2;
        cout<<ans<<" "<<ans<<endl;
        return;
    }
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        solve(n);
    }

    return 0;
}