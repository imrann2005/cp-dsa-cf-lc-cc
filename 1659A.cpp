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

void solve(int n,int r,int b) {
    // Write your solution here
    vi a(b+1,1);
    int s = (b+1);
    int i=0;
    while (s < r)
    {
        a[i]++;
        s ++;
        i = (i+1)%(b+1);
    }
    int cnt = 0;
    for (int i = 0; i < b+1; i++)
    {
        for(int j=0;j<a[i];j++){
            cnt++;
            cout<<"R";
        }
       
        if(i != b)cout<<"B";
    }
    cout<<"\n";
    
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n,r,b;
        cin >>n>>r>>b;
        solve(n,r,b);
    }

    return 0;
}