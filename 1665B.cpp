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

void solve(vi&a,int n) {
    // Write your solution here
    map<int,int>mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[a[i]]++;
    }
    int maxfreq = 0;
    for(auto &it : mpp){
        maxfreq = max(maxfreq,it.second);
    }
    int ops = 0;
    ops += n-maxfreq;
    while (maxfreq < n)
    {
        maxfreq *= 2;
        ops++;
    }
    cout<<ops<<endl;
    
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