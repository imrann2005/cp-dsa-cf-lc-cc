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

void solveD(vll&a,ll n,ll x,ll y) {
    // Write your solution here
    map<pair<ll,ll>,ll>mpp;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        ll modx = a[i]%x;
        ll mody = a[i]%y;
        ll find = (x-modx)%x;
        cnt += mpp[{find,mody}];
        mpp[{modx,mody}]++;
    }
    cout<<cnt<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll n,x,y;
        cin>>n>>x>>y;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solveD(a,n,x,y);
    }

    return 0;
}