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

void solveB(vll&a,int n,ll s)
{
    // Write your solution here

}

int main()
{
    fast_io;

    int n, q;
    cin >> n >> q;
    vll a(n);
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    vll fv(n,-1);
    vll fvv(n,-1);
    ll sqti = -1;
    ll sqtv = -1;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            ll p, v;
            cin >> p >> v;
            p = p-1;
            int pos = fv[p];
            if(pos < sqti){
                s = s - sqtv + v;
            }
            else{
                if(pos == -1){
                    s = s - a[p] + v;
                }
                else s = s - fvv[p] + v;
            }
            fv[p] = i;
            fvv[p] = v;
            cout<<s<<endl;
        }
        else
        {
            ll v;
            cin >> v;
            sqti = i;
            sqtv = v;
            s = v*n;
            cout<<s<<endl;
        }
    }

    return 0;
}