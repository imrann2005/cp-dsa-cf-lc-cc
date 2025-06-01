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

void solve(vi&a,int n,int x) {
    // Write your solution here
    int p = find(all(a),x) - a.begin();
    cout<<p+1<<" ";
    rotate(a.begin(), a.begin() + p, a.begin() + p + 1);
}

int main() {
    fast_io;
    int n;
    cin>>n;
    int q;
    cin >> q;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
   
    while (q--) {
        int x;
        cin>>x;
        solve(a,n,x);
    }

    return 0;
}