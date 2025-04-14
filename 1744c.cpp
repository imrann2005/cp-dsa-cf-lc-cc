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

void solve(string&s,int n,char ch) {
    // Write your solution here
    if(ch == 'g'){
        cout<<0<<endl;
        return;
    }
    s += s;
    n += n;
    vi right(n);
    int idx = -1;
    for (int i = n-1; i >= 0; i--)
    {
        if(s[i]=='g'){
            right[i] = 0;
            idx = i;
            
        }
        else{
            right[i] = idx;
        }
    }
    int mx = -1;
    for (int i = 0; i < n/2; i++)
    {
        if(s[i] == ch){
           mx = max(mx,right[i]-i); 
        }
        
    }
    cout<<mx<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        char ch;
        cin >> n; 
        cin >> ch;
        cin >> s;
       
        solve(s,n,ch);
    }

    return 0;
}