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
    
        int mx = INT_MIN;
        int a=1,b=n-1;
      for (int i = 2; i*i <= n; i++)
      {
        if(n%i == 0){
            a = n/i;
            b = n-a;
            break;
        }
      }

      cout<<a<<" "<<b<<endl;
      
  
    
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