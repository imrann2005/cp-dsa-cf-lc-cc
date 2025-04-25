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
    sort(all(a));
    vll pre(n);
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        s+=a[i];
        pre[i] = s;
    }
    if(a[0]!=1){
        no;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if(a[i] <= pre[i-1]){

        }
        else{
            no;
            return;
        }
    }
    yes;

    
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