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

void solve() {
    // Write your solution here
    ll n,x,m;
    cin>>n>>x>>m;
    ll cs = x;
    ll ce = x;
    for (int i = 0; i < m; i++)
    {
        ll ns,ne;
        cin>>ns>>ne;
        if(ne < cs || ns > ce){
            continue;
        }
        if(ne >= cs){
            cs = min(cs,ns);
        }
        if(ne >= ce){
            ce = max(ce,ne);
        }
    }
    //cout<<cs<<" "<<ce<<endl;
    cout<<(ce-cs)+1<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}