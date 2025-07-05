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
    vll v;
    int prev = a[0];
    v.pb(1);
    for (int i = 0; i < n; i++)
    {
        if(prev != a[i])
        {
            v.pb(i+1);
            prev = a[i];
        }
    }
    ll q;
    cin>>q;
    while (q--)
    {
        /* code */
        ll l,r;
        cin>>l>>r;
        ll idx1 = lower_bound(all(v),l) - v.begin();
        ll idx2 = lower_bound(all(v),r) - v.begin();
        if (idx1 == v.size())
        {
            /* code */
            idx1--;
        }
        if(idx2 == v.size()){
            idx2--;
        }
        if(v[idx1] > l){
            idx1--;
        }
        if(v[idx2] > r){
            idx2--;
        }
        if(idx1==idx2){
            cout<<-1<<" "<<-1<<endl;
        }
        else{
            cout<<max(v[idx1],l)<<" "<<v[idx1+1]<<endl;
        }
        
    }
    
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
        cout<<endl;
    }

    return 0;
}