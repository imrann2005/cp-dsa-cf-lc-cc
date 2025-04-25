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
    vi f(30,0);
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < 30)
        {
            if((1<<j)&a[i]){
                f[j]++;
            }
            j++;
        }
    }
    ll mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ll s = 0;
        int j = 0;
        while (j < 30)
        {
            if((1<<j)&a[i]){
                s+= (ll)(1<<j)*(ll)(n-f[j]);
            }
            else{
                s+=(ll)(1<<j)*(ll)(f[j]);
            }
            j++;
        }
        mx = max(mx,s);
    }

    cout<<mx<<endl;
    
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        solve(a,n);
    }

    return 0;
}