#include <bits/stdc++.h>
using namespace std;

/*ٱلْحَمْدُ لِلَّٰهِ رَبِّ ٱلْعَالَمِينَ */

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

void solve(vll&a,int n) {
    // Write your solution here
    vll p(n);
    vll s(n);
    p[0] = a[0];
    s[n-1]=a[n-1];
    for (int i = 1; i < n; i++)
    {
        p[i] = p[i-1] + a[i];
    }
    for (int i = n-2; i>=0; i--)
    {
        s[i] = s[i+1] + a[i];
    }
    ll mx = LLONG_MIN;
    for (int i = 0; i < n-1; i++)
    {
        mx = max(mx,__gcd(p[i],s[i+1]));
    }
    cout<<mx<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solve(a,n);
    }

    return 0;
}