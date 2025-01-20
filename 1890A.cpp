/* Doremy's Paint problem 
Parity based basic problem
Some mathematical aspect : x,y,z : x+y = k, then y+z=k : z = k-y => z=x;
More than 2 elements means it will never be good 
 */

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

void solve(vi &a, int n)
{
    // Write your solution here
    int d1 = a[0];
    int b1 = 1;
    int d2 = -1;
    int b2 = 0;
    for (size_t i = 1; i < n; i++)
    {
        if (d1 == a[i])
            b1++;
        else if (d2 == -1)
        {
            d2 = a[i];
            b2++;
        }
        else if (d2 == a[i])
        {
            b2++;
        }
        else
        {
            no;
            return;
        }
    }
    if (d2 == -1 || b1==b2 || abs(b1-b2)==1)
    {
        yes;
        return;
    }
    no;
    
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(a, n);
    }

    return 0;
}