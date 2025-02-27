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

void solve(string&s,int n) {
    // Write your solution here
    int l=0,r=1;
    int mx=1;
    while (r < n)
    {
        if(s[r]==s[r-1]){
            
        }
        else{
            l = r;
        }
        mx = max(mx,r-l+1);
        r++;
    }
    cout<<mx+1<<endl;
    

}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s,n);
    }

    return 0;
}