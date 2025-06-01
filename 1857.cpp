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

void solveC(vector<pair<ll,ll>>&a,ll n) {
    // Write your solution here
    reverse(all(a));
    vll ans(n);
    ans[n-1] = a[0].first;
    int idx = 1;
    for (int i = 0; i < a.size() && idx < n; i++)
    {
        /* code */
        ll num = idx;
        while (a[i].second > 0 && idx<n)
        {
            /* code */
            ans[n-idx-1] = a[i].first;
            a[i].second -= idx;
            idx++;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin>>n;
        map<ll,ll>mpp;
        ll z = (n*(n-1))/2;
        for (int i = 0; i < z; i++)
        {
            /* code */
            ll x;
            cin>>x;
            mpp[x]++;
        }
        vector<pair<ll,ll>>v;
        for(auto&it : mpp){
            v.push_back({it.first,it.second});
        }
        solveC(v,n);
    }

    return 0;
}