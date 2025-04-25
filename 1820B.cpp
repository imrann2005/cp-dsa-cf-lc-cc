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

void solve(string& s) {
    // Write your solution here
    string t = s;
    int n = s.length();
    t =t+t;
    int i=0;
    int mx = 0;
    bool z = 0;
    while (i<t.length())
    {
        if(t[i]=='1'){
            int cnt = 1;
            mx = max(mx,cnt);
            i++;
            while (i<t.length())
            {
                /* code */
                if(t[i]=='1'){
                    cnt++;
                    mx = max(cnt,mx);

                    i++;
                }
                else break;
            }
            
        }
        else {
            z = 1;
            i++;}
    }
    if(z==0){
        cout<<1LL*n*n<<endl;
        return;
    }
    ll mxA = 1LL*((mx+1)/2)*((mx+2)/2);
    cout<<mxA<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin>>s;
        solve(s);
    }

    return 0;
}