#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define st set<int>
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve(vi& a,vi& b,int n,st& sa,st& sb) {
    // Write your solution here
    if((sa.size() == 1 && sb.size() < 3 )|| (sb.size() == 1 && sa.size() < 3 )){
        no;
        return;
    }
    yes;

}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vi a(n);
        vi b(n);
        st sa;
        st sb;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            sa.insert(a[i]);

        }
          for (int i = 0; i < n; i++)
        {
            cin>>b[i];
            sb.insert(b[i]);
        }
        
        solve(a,b,n,sa,sb);
    }

    return 0;
}