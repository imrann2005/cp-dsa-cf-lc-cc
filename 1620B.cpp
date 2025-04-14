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

void solve() {
    // Write your solution here
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int w,h;
        cin >> w>>h;
        int h1;
        cin >> h1;
        vi hor1(h1);
        ll mx = -1;
        for (int i = 0; i < h1; i++)
        {
            cin >> hor1[i];
        }
        ll mxh1 = hor1[h1-1] - hor1[0];
        mx = max(mx,mxh1*h*1LL);
        int h2;
        cin >> h2;
        vi hor2(h2);
        for (int i = 0; i < h2; i++)
        {
            cin >> hor2[i];
        }
        ll mxh2 = hor2[h2-1] - hor2[0];
        mx = max(mx,mxh2*h*1LL);
        int v1;
        cin >> v1;
        vi ver1(v1);
        
        for (int i = 0; i < v1; i++)
        {
            cin >> ver1[i];
        }
        ll mxv1 = ver1[v1-1] - ver1[0];
        mx = max(mx,mxv1*w*1LL);
        int v2;
        cin >> v2;
        vi ver2(v2);
        
        for (int i = 0; i < v2; i++)
        {
            cin >> ver2[i];
        }
        ll mxv2 = ver2[v2-1] - ver2[0];
        mx = max(mx,mxv2*w*1LL);

        cout<<mx<<endl;
        //solve();
    }

    return 0;
}