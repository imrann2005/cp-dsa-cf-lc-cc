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

void solve(int n, int k, int x)
{
    // Write your solution here

    if(x==1 && k==1){
        no;
        return;
    }

    if (x != 1)
    {   
        yes;
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            cout << 1 << " ";
        }
        cout << endl;
    }
    else
    {
        if (n & 1)
        {
            /* odd */
            if(k >= 3){
                yes;
                cout<<n/2<<endl;
                for (int i = 0; i < n/2 - 1; i++)
                {
                    cout<<2<<" ";
                }
                cout<<3<<" ";
                cout<<endl;
                
            }
            else{
                no;
                return;
            }
        }
        else
        {
            /* even */
            yes;
            cout << n / 2 << endl;
            for (int i = 0; i < n / 2; i++)
            {
                cout<<2<<" ";
            }
            cout<<endl;
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
        int n, k, x;
        cin >> n >> k >> x;
        solve(n, k, x);
    }

    return 0;
}