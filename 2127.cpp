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
    ll n;
    cin>>n;
    vll a(n);
    set<ll>st;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        
        // if(a[i]==0){
        //     no;
        //     return;
        // }
        
        st.insert(a[i]);
        
       
    }
    if(st.count(0)){
        no;
        return;
    }

    if(st.size() == 1 ){
        yes;
        return;
    }
    if(st.size() == 2 && st.count(-1)){
        yes;
        return;
    }
    no;
    
}

void solveB(){
    ll n;
    cin>>n;
    int pos;
    cin>>pos;
 
    string s;
    cin>>s;
 
 
    pos--;
 
 
    int jum=0;
    int dd=s.size();
    for(int i=pos;i<s.size();i++){
        if(s[i]=='#'){
            dd=(int)s.size()-i;
            jum++;
            break;
        }
    }
    int dm=s.size();
    for(int i=pos;i>=0;i--){
        if(s[i]=='#'){
            dm=i+1;
            jum++;
            break;
        }
    }
  //  cout<<jum<<" ";
    if(jum==0||pos==0||pos==s.size()-1){
        cout<<"1"<<endl;
    }else if(jum==1){
        if(dd==s.size()){
            cout<<min(dm+1,(int)s.size()-pos)<<endl;
           // cout<<"a"<<endl;
        }else{
            cout<<min(dd+1,pos+1)<<endl;
        }
    }else{
        cout<<min(min(pos+1,(int)s.size()-pos),max(dm,dd)+1)<<endl;
    }
    
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
