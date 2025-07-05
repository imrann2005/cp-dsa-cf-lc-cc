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

void solveB1(string &s, int n)
{
    // Write your solution here
    ll cnt = 0;
    if(n==1 && s[0]=='0'){
        cout<<"BOB\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '0')cnt++;
    }
    if(cnt == 0){
        cout<<"DRAW\n";
    }
    else if(cnt % 2 == 0){
        cout<<"BOB\n";
    }
    else cout<<"ALICE\n";
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        solveB1(s,n);
    }

    return 0;
}