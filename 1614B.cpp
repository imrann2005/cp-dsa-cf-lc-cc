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

bool comp(pii& p1,pii& p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}

void solve(vi&a,int n) {
    // Write your solution here
    vi x(n);
    vector<pii>p;
    for (int i = 0; i < n; i++)
    {
        p.push_back({a[i],i});
    }
    sort(p.begin(),p.end(),comp);
    int i=0;
    int cnt = 0;
     ll sum = 0;
    while (i<n)
    {
        cnt++;
        x[p[i].second] = cnt;
        sum += 2LL * abs(cnt) * p[i].first;;
        i++;
        if(i < n){
            x[p[i].second] = -cnt;
            sum += 2LL * abs(cnt) * p[i].first;
        }
        i++;
    }
    cout<<sum<<"\n";
    cout<<0<<" ";
    for (int i = 0; i < n; i++)
    {
        
        cout<<x[i]<<" ";
    }
    cout<<"\n";
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        solve(a,n);
    }

    return 0;
}