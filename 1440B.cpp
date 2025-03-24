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
    ll skips = n - ceil((double)n/2.0);
    int i=n*k-1;
    i = i-skips;
    ll s = 0;
    s += a[i];
    int cnt = 1;
    while (cnt < k)
    {
        i = i - (skips+1);
        s += a[i];
        cnt++;
    }
    cout<<s<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll n,k;
        cin>>n>>k;
        vi a(n*k);
        for (size_t i = 0; i < n*k; i++)
        {
            cin >> a[i];
        }
        
        solve(a,n,k);
    }

    return 0;
}