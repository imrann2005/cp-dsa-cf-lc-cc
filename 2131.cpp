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

void solveA()
{
    // Write your solution here
    ll n;
    cin >> n;
    vll a(n);
    vll b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            diff += (a[i] - b[i]);
        }
    }
    cout << diff + 1 << endl;
}

void solveB()
{
    ll n;
    cin >> n;
    // if(n==2){
    //     cout<<-1<<" "<<2<<endl;
    //     return;
    // }
    int cnt = n;
    for (int i = 1; i < n; i++)
    {
        if (i & 1)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << 3 << " ";
            
        }
    }
    if(n&1){
        cout<<-1<<endl;
    }
    else cout<<2<<endl;
    
}

void solveC(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    map<ll,ll>mpp;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        int rem = a[i]%k;
        mpp[rem]++;
        mpp[(k-rem)%k]++;
    }
    vll b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];

    }

    for(auto &it : b){
        int r = it%k;
        if(mpp.find(r) != mpp.end()){
            mpp[r]--;
            mpp[(k-r)%k]--;
            if(mpp[r]==0){
                mpp.erase(r);
            }
            if(mpp[(k-r)%k] == 0){
                mpp.erase((k-r)%k);
            }
        }
        else{
            no;
            return;
        }
    }

    yes;
 
}

void solveE(){
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>a[i];
    }
    vll b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    
    for(int i=0;i<n-1;i++){
       if((a[i]^a[i+1]) == b[i]){
            a[i] = b[i];
       }
    }
    for(int i=n-2;i>=0;i--){
        if((a[i]^a[i+1]) == b[i]){
            a[i] = b[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(a[i] != b[i]){
            no;
            return;
        }
    }

    yes;
    

}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        solveE();
    }

    return 0;
}