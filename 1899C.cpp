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
    ll s = a[0];
    ll mx = s;
    int i = 1;
    if(s < 0){
        s = 0;
    }
    while (i<n)
    {
        if((a[i]&1)==(a[i-1]&1)){
            s = 0;
            s+=a[i];
            mx = max(mx,s);
        }
        else{
            s += a[i];
            mx = max(mx,s);
        }
        if(s<0){
            s = 0;
        }
        i++;
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