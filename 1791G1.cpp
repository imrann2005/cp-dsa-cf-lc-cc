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

void solve(vll&a,int n,int c) {
    // Write your solution here
    for (int i = 0; i < n; i++)
    {
        a[i] += i+1;
    }
    sort(all(a));
    vll pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i-1] + a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(pre[i] > c ){
            cout<<i-1+1<<endl;
            return;
        }
    }
    cout<<n<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n,c;
        cin>>n>>c;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solve(a,n,c);
    }

    return 0;
}