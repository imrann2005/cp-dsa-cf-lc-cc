#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

bool comp(pii &p1,pii &p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}

void solve(vi&a,int n,int k) {
    // Write your solution here
    vector<pii> order;
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i]%k;
        if(a[i] == 0)a[i] = k;
        order.pb({a[i],i+1});

    }

    sort(all(order),comp);
    for (int i = 0; i < n; i++)
    {
        cout<<order[i].second<<" ";
    }
    cout<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        solve(a,n,k);
    }

    return 0;
}