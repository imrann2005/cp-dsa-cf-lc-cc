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

void solve(vi &a, int n, int m)
{
    // Write your solution here
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            int num = m - a[i];
            if (num <= a[i + 1])
            {
                if ((i == 0) || (i - 1 >= 0 && num >= a[i - 1]))
                {
                  
                    a[i] = num;
                }
                else
                {
                    no;
                    return;
                }
            }
            else
            {
                no;
                return;
            }
            
           
        }
    }
   
    
    yes;
    return;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n, m1,m;
        cin >> n >> m1;
        vi a(n);
        
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin>>m;
        solve(a, n, m);
    }

    return 0;
}