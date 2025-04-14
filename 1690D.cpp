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

void solve(string&a,int n,int k) {
    // Write your solution here
    int w=0,b=0;
    int i=0,j=0;
    while (j < k)
    {
        if(a[j]=='B')b++;
        else w++;
        j++;
    }
    //j--;
    int mn = w;
    
    while (i<n && j < n)
    {
       (a[j] =='W') ? w++ : b++;
       (a[i]=='W') ? w-- : b--;
       i++;
       mn = min(mn,w);
       j++;
       
    }

    cout << mn << endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        string a;
        cin >> a;
        
        solve(a,n,k);
    }

    return 0;
}