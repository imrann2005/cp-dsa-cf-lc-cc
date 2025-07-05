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

void solveC(string&s,ll n,char &ch) {
    // Write your solution here
    bool f = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] != ch){
            f = 1;
        }
    }
    if(!f){
        cout<<0<<endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        bool f1 = 1;
        for (int j = i; j <= n; j+=i)
        {
            f1 &= (ch==s[j-1]);

        }
        if(f1){
            cout<<1<<endl;
            cout<<i<<endl;
            return;
        }
    }
    cout<<2<<endl;
    cout<<n<<" "<<n-1<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin>>n;
        char ch;
        cin>>ch;
        string s;
        cin>>s;
        solveC(s,n,ch);
    }

    return 0;
}