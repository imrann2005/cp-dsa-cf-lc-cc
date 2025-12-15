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

void solveD(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int o=0;
    int c=0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='('){
            o++;
        }
        else{
            c++;
        }
    }
    if(o!=c){
        cout<<-1<<endl;
        return;
    }
    o=0,c=0;
    stack<pair<char,int>>st;
    vector<int>vis(n,0);
    int cnt = 1;
    bool f = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='('){
            //o++;
            st.push({s[i],i});
        }
        else{
            if(!st.empty()){
                //o--;
                int idx = st.top().second;
                vis[i] = 1;
                vis[idx] = 1;
                st.pop();
                f = 1;
            }
            else{
                cnt = 2;
            }
        }
    }

    if(cnt==1){
        cout<<cnt<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<vis[i]<<" ";
        }
        cout<<endl;
        return;

    }
    while (!st.empty())
    {
        /* code */
        st.pop();
    }
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    reverse(all(s));
    cnt = 1;
    f = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='('){
            //o++;
            st.push({s[i],i});
        }
        else{
            if(!st.empty()){
                //o--;
                int idx = st.top().second;
                vis[i] = 1;
                vis[idx] = 1;
                st.pop();
                f = 1;
            }
            else{
                cnt = 2;
            }
        }
    }
    if(cnt==1){
        cout<<cnt<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<vis[i]<<" ";
        }
        cout<<endl;
        return;

    }
    cout<<cnt<<endl;
    for (int i = n-1; i >=0 ; i--)
    {
        if(vis[i]!=0){
            cout<<1<<" ";
        }
        else cout<<2<<" ";
    }
    cout<<endl;
}

void solve(int x,int k) {
    // Write your solution here
    if(x % k != 0){
        cout<<1<<endl;
        cout<<x<<endl;
        return;
    }
    cout<<2<<endl;
    cout<<x-1<<" "<<1<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solveD();
    }

    return 0;
}