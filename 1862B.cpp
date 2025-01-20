#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve(vi&b, int n) {
    // Write your solution here
    vi a;
    a.pb(b[0]);
    int m=1;
    int i=1;
    while (i<n)
    {
        if(b[i] >= b[i-1]){
            a.pb(b[i]);
            m++;
        }
        else{
            a.pb(b[i]);
            a.pb(b[i]);
            m+=2;
        }
        i++;
    }
    if(m > 2*n) return;
    cout<<m<<endl;
    rep(i,0,m){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vi b(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        
        solve(b,n);
        
    }

    return 0;
}