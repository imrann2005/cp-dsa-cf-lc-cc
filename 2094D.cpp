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

void solve(string&p,string&s) {
    // Write your solution here
    vector<pair<char,int>>p1;
    vector<pair<char,int>>s1;
    int i = 0;
    while (i < p.size())
    {
        char c = p[i];
        int cnt = 0;
        while (p[i] == c)
        {
            cnt++;
            i++;
        }
        p1.pb({c,cnt});
    }
    i=0;
    while (i < s.size())
    {
        char c = s[i];
        int cnt = 0;
        while (s[i] == c)
        {
            cnt++;
            i++;
        }
        s1.pb({c,cnt});
    }

    if(s1.size() != p1.size()){
        no;
        return;
    }
    i = 0;
    while (i < s1.size())
    {
        /* code */
        if(s1[i].first != p1[i].first){
            no;
            return;
        }
        if(s1[i].second < p1[i].second){
            no;
            return;
        }
        if(s1[i].second > 2*p1[i].second){
            no;
            return;
        }
        i++;
    }
    yes;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        string p;
        string n;
        cin >> p;
        cin >> n;
        solve(p,n);
    }

    return 0;
}