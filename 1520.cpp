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
    ll cnt = 0;
    map<ll,ll>mpp;
    for (int i = 0; i < n; i++)
    {
        int diff = a[i]-(i+1);
        if(mpp.find(diff) != mpp.end()){
            cnt += mpp[diff];
        }
        mpp[diff]++;
    }
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