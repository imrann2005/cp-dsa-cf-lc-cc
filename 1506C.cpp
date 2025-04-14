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

int ops(string&a,string&b,int n,int m,int idx1,int idx2){
    int len = idx2-idx1+1;
    string sub = a.substr(idx1,len);
    int ans = 0;
    int mn = INT_MAX;
    for (int i = 0; i+len <= m; i++)
    {
        string sub1 = b.substr(i,len);
        int j = i+len-1;
        if(sub1 == sub){
            ans = i+idx1+m-j-1+n-idx2-1;
            mn = min(mn,ans);
        }
        
    }

    return mn;
    
}

void solve(string&a,string&b) {
    // Write your solution here
    int n = a.length();
    int m = b.length();
    int mn = m+n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int o = ops(a,b,n,m,i,j);
            mn = min(mn,o);
        }
        
    }

    cout<<mn<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        string a,b;
        cin >> a;
        cin >> b;
        solve(a,b);
    }

    return 0;
}
