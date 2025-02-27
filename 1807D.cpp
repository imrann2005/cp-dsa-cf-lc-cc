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

void solve(vi&a,int l,int r,int k,vi&pre,vi&suff) {
    // Write your solution here
    int sum = (r-l+1)*k;
    if(l-1 >= 0) sum += pre[l-1];
    if(r+1 < sz(a))sum+=suff[r+1];
    if(sum & 1)yes;
    else no;

}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n,q;
        cin >> n >> q;
        vi a(n);
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            
        }
        vi pre(n);
        vi suff(n);
        for (int i = 0; i < n; i++)
        {
            sum1 += a[i];
            sum2 += a[n-i-1];
            pre[i] = sum1;
            suff[n-i-1] = sum2;
        }
        
        
        for (int i = 0; i < q; i++)
        {
            int l,r,k;
            cin >> l >> r>> k;
            solve(a,l-1,r-1,k,pre,suff);
        }
        
        
    }

    return 0;
}