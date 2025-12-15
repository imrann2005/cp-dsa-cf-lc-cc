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

ll factn(ll n){
    ll f = 1;
    for (int i = 1; i <= n; i++)
    {
        f = (f*i)%MOD;
    }
    return f%MOD;
}

void solveB(){
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>a[i];
    }
    
    sort(all(a));
    vll b(n);
    b[0] = a[0];
    b[n-1] = a[1];
    int idx = 1;
    for (int i = 2; i < n; i++)
    {
        b[idx] = a[i];
        idx++;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<b[i]<<" ";
    // }
    // cout<<endl;
    vll pre(n);
    pre[0] = b[0];
    vll suff(n);
    ll s = b[0];
    for (int i = 1; i < n; i++)
    {
        s &= b[i];
        pre[i] = s;
    }
    suff[n-1] = b[n-1];
    s = b[n-1];
    for (int i = n-2; i>=0; i--)
    {
        s &= b[i];
        suff[i] = s;
    }
    
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<pre[i]<<" ";
    // }
    // cout<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<suff[i]<<" ";
    // }
    // cout<<endl;
    for (int i = 0; i < n-1; i++)
    {
        if(pre[i] != suff[i+1]){
            cout<<0<<endl;
            return;
        }
    }
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(pre[0] == a[i]){
            cnt++;
        }
        else break;
    }
    
    
    ll ans = (1LL*cnt*(cnt-1))%MOD;
    ans = (1LL*ans*factn(n-2))%MOD;
    cout<<ans%MOD<<endl;

}

int main() {
    fast_io;
    // int n;
    // cin>>n;
    int q;
    cin >> q;
    // vi a(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>a[i];
    // }
    
   
    while (q--) {
        // int x;
        // cin>>x;
        // solve(a,n,x);
        solveB();
    }

    return 0;
}