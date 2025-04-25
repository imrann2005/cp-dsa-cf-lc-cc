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

void solve(int n,int x,vi&st1,vi&st2,vi&st3) {
    // Write your solution here
    set<int>st;
    int i = 0;
    while (i < 30)
    {
        if(x&(1<<i)){
            st.insert(i);
        }
        i++;
    }
    int a = 0;
    int idx=0;
    bool f = 1;
    while (idx<n)
    {
        /* code */
        if(a==x){
            yes;
            return;
        }
        int b = st1[idx];
        if(b>x){
            break;
        }
        else{
            int i = 0;
            while (i<30)
            {
                if(b&(1<<i)){
                    if(!st.count(i)){
                        f=0;
                        break;
                    }
                }
                i++;
            }
        }
        if(!f)break;
        a|=b;
        idx++;
    }
     idx=0;
     f=1;
    while (idx<n)
    {
        /* code */
        if(a==x){
            yes;
            return;
        }
        int b = st2[idx];
        if(b>x){
            break;
        }
        else{
            int i = 0;
            while (i<30)
            {
                if(b&(1<<i)){
                    if(!st.count(i)){
                        f=0;
                        break;
                    }
                }
                i++;
            }
        }
        if(!f)break;
        a|=b;
        idx++;
    }
    idx=0;
     f=1;
    while (idx<n)
    {
        /* code */
        if(a==x){
            yes;
            return;
        }
        int b = st3[idx];
        if(b>x){
            break;
        }
        else{
            int i = 0;
            while (i<30)
            {
                if(b&(1<<i)){
                    if(!st.count(i)){
                        f=0;
                        break;
                    }
                }
                i++;
            }
        }
        if(f==0)break;
        a|=b;
        idx++;
    }
    if(a==x){
        yes;
        return;
    }
    no;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n,x;
        cin>>n>>x;
        vi st1(n);
        vi st2(n);
        vi st3(n);
        for (int i = 0; i < n; i++)
        {
            cin>> st1[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>st2[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>st3[i];
        }
        
        solve(n,x,st1,st2,st3);
    }

    return 0;
}