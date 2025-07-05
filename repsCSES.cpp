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
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve()
{
    // Write your solution here
    string s;
    cin>>s;
    int i=0,j=0;
    int n = s.length();
    ll mx = 0;
    while (j < n)
    {
        /* code */
        while (j<n && s[i]==s[j])
        {
            /* code */
            j++;
        }
        j--;
        ll len = j-i+1;
        mx = max(mx,len);

        i=j;
        j++;
        i++;
    }
    cout<<mx<<endl;
    
}

int main()
{
    fast_io;
    solve();

    return 0;
}