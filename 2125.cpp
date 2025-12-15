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
    string s;
    cin>>s;
    int n = s.length();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='T'){
            cnt++;
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        /* code */
        cout<<"T";
    }
    for (int i = 0; i < n; i++)
    {
        if(s[i]!='T'){
            cout<<s[i];
        }
    }
    
    cout<<endl;
}

void solveB()
{
    ll a,b,k;
    cin>>a>>b>>k;
    if (a == 0 && b == 0) {
        cout << 0 << '\n';
        return;
    }

    ll g = __gcd(a, b);
    ll a2 = a / g;
    ll b2 = b / g;

    if (a2 <= k && b2 <= k) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solveB();
    }

    return 0;
}