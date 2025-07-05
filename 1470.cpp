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

void solveA() {
    // Write your solution here
    ll n,m;
    cin>>n>>m;
    vll a(n+1);
    vll b(m+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin>>b[i];
    }
    sort(all(a));

    int i=1;
    int j=n;
    ll cnt = 0;
    while (j>=1)
    {
        /* code */
        if(i<=m && a[j]>=i){
            cnt += b[i];
            i++;
        }
        else{
            cnt += b[a[j]];
        }
        j--;
    }
    
    cout<<cnt<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solveA();
    }

    return 0;
}