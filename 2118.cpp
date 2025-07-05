#include <bits/stdc++.h>
using namespace std;

#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"


const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solveA(ll n, ll k)
{
    // Write your solution here
    ll c0 = n-k;

    if(k>0){
        cout<<1;
        k--;
    }
    int cnt0 = c0;
    for(int i=0;i<cnt0-1;i++){
        cout<<0;
        c0--;
    }
    for (int i = 0; i < k; i++)
    {
        /* code */
        cout<<1;
    }
    if(c0>0)cout<<0<<endl;
    else cout<<endl;
}

void solveB(ll n){
    std::cout << (2 * n - 1) << endl;

    for (int i = 1; i <= n; ++i) {
      
        std::cout << i << " 1 " << i << std::endl;

        if (i < n) {
            std::cout << i << " " << (i + 1) << " " << n << endl;
        }
    }
    
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        // ll n,k;
        // cin>>n>>k;
        // solveA(n,k);
        ll n;
        cin>>n;
        solveB(n);
    }

    return 0;
}