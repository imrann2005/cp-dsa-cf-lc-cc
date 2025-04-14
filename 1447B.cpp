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

void solve(vi&a,int n) {
    // Write your solution here
    ll sum = 0;
    int mn = abs(a[0]);
    int neg = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] < 0)neg++;
        mn = min(mn,abs(a[i]));
        sum += abs(a[i]);
    }
    if(neg&1){
        cout<<sum-2*mn<<endl;
        return;
    }

    cout<<sum<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        int m;
        cin >>n>>m;
        vi a(n*m);
        for (int i = 0; i < n*m; i++)
        {
            cin >> a[i];
        }
        
        solve(a,n*m);
    }

    return 0;
}