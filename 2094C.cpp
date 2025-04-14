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

void solve(vector<vi> &a, int n)
{
    // Write your solution here
    vi b(2 * n);
    set < int > st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
                st.insert(a[i][j]);
                b[i + j + 1] = a[i][j];
        }
    }
    int t = (2*n)*(2*n + 1)/2;
    int s = 0;
    for (int i = 0; i < 2*n; i++)
    {
        s += b[i];
    }
    int e = t-s;
    b[0] = e;
    for (int i = 0; i < 2*n; i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    
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
        vector<vi> a(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        solve(a, n);
    }

    return 0;
}