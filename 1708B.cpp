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

void solve(int n,int l,int r) {
    // Write your solution here
    vll ans(n+1);
    for (int i = 1; i <= n; i++)
    {
        ll x = r/i;
        if(i*x >= l){
            ans[i] = i*x;
        }
        else{
            no;
            return;
        }
    }
    yes;
    for (int i = 1; i <= n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n,l,r;
        cin>>n>>l>>r;
        
        solve(n,l,r);
    }

    return 0;
}