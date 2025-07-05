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

bool works(vector<pair<ll,ll>>&a,ll n,ll mid){
    for (int i = 0; i < n; i++)
    {
        if(mid >= a[i].first){
            mid += a[i].second;
        }
        else return false;
    }
    return true;
}

void solveC() {
    // Write your solution here
    ll n;
    cin>>n;
    vector<pair<ll,ll>>a;
    for (int i = 0; i < n; i++)
    {
        ll k;
        cin>>k;
        
        ll mx = LLONG_MIN;
        int idx = -1;
        
        for (int j = 0; j < k; j++)
        {
            ll x;
            cin>>x;
            if((x+1-j)>mx){
                mx = x+1-j;
                idx = j;
            }
        }
        // mx = (mx+1) - idx;
        a.pb({mx,k});
    }
    sort(all(a));
    ll l = a[0].first;
    ll h = a[n-1].first;

    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;
        if(works(a,n,mid)){
            h = mid-1;
        }
        else l = mid+1;
    }
    cout<<l<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solveC();
    }

    return 0;
}