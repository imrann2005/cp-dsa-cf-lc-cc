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

void solveC(vll&a,ll n,ll x) {
    // Write your solution here
    sort(all(a));
    vll p(n);
    p[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        p[i] = p[i-1] + a[i];
    }
    ll cnt = 0;
    int i = n-1;
    while (i >= 0)
    {
        /* code */
        if(p[i] <= x){
            ll r = (x-p[i]);
            r = (r)/(i+1);
            cnt += (r+1);
        }
        i--;
    }
    cout<<cnt<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll n,x;
        cin>>n>>x;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solveC(a,n,x);
    }

    return 0;
}