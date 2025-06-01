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

void solveA(int a,int b,int c) {
    // Write your solution here
    int mx = max(a,b);
    int mn = min(a,b);
    int d  = mx-mn;
    c = c-d;
    if(c == mx){
        yes;
    }
    else if(c>=mx){
        if((c-mx)%3==0){
            yes;
        }
        else no;
    }
    else{
        no;
    }
}

void solveB(vll&a,int n){
    vll suf(n);
    ll s = 0;
    vll mx(n);
    ll m = a[0];
    for (int i = 0; i < n; i++)
    {
        m = max(a[i],m);
        mx[i] = m;
    }
    for (int i = n-1; i>=0; i--)
    {
        /* code */
        s += a[i];
        suf[i] = s;
    }
    
    for (int i = n-1; i>=0; i--)
    {
        /* code */
        if(i==n-1){
            cout<<max(suf[i],mx[i])<<" ";
        }
        else cout<<max(suf[i],suf[i+1]+mx[i])<<" ";
    }
    cout<<endl;
    

}

void solveC(string&s,int n){
    char l = s[n-1];
    char f = s[0];
    if(f==l){
        if(l=='A'){
            cout<<"Alice"<<endl;

        }
        else cout<<"Bob"<<endl;
    }
    else{
        //int i = n-2;
        if(f=='A'){
            for (int i = 1; i < n-1; i++)
            {
                if(s[i]=='B'){
                    cout<<"Bob\n";
                    return;
                }
            }
            cout<<"Alice\n";
        }
        else{
            if(s[n-2]=='A'){
                cout<<"Alice\n";
            }
            else cout<<"Bob\n";
        }
    }
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
       int n;
       cin>>n;
       string s;
       cin>>s;
       solveC(s,n);
    }

    return 0;
}