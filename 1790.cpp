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

void solveD(vll&a,ll n) {
    // Write your solution here
    sort(all(a));
    int l=0;
    int r = 0;
    ll len = 0;
    ll mx = 0;
    ll cnt = 0;
    while (r < n && l < n)
    {
        /* code */
        while (r<n && a[l]==a[r])
        {
            /* code */
            len = r-l+1;
            mx = max(mx,len);
            r++;
        }
        if(a[r]-a[l] > 1){
            cnt += mx;
            mx = 0;
        }
        else{
            if(len < mx){
                cnt += (mx-len);
                mx = len;
            }
        }
        l = r;
    }
    cnt += mx;
    cout<<cnt<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin>>n;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solveD(a,n);
    }

    return 0;
}