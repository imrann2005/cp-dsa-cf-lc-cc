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

void solve(vi &arr,int n,int k) {
    // Write your solution here
    for (size_t i = 0; i < n; i++)
    {
       if(arr[i] == k){
        yes;
        return;
       }
    }
    no;
}
int a[200000];
int pre[30][200001];

int works(int l,int val){
    int ans = 0;
    for (int i = 0; i < 30; i++)
    {
        if(pre[i][val+1]-pre[i][l]==0){
            ans += (1<<i);
        }
    }
    return ans;
    
}
void solveE(){
    ll n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int j = 0; j < 30; j++)
    {
        pre[j][0] = 0;
        for (int i = 0; i < n; i++)
        {
            if((1<<j)&a[i]){
                pre[j][i+1] = pre[j][i];
            }
            else{
                pre[j][i+1] = pre[j][i] + 1;
            }
        }
        
    }

    int q;
    cin>>q;
    while (q--)
    {
        /* code */
        int l,k;
        cin>>l>>k;
        l--;
        if(a[l] < k){
            cout<<-1<<" ";
            continue;
        }
        int low = l;
        int high = n-1;

        while (low <= high)
        {
            /* code */
            int mid = (low+high)>>1;
            if(works(l,mid) >= k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        cout<<low<<" ";
        
    }
    
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        // int n,k;
        // cin>>n>>k;
        // vi arr(n);
        // for (size_t i = 0; i < n; i++)
        // {
        //     cin>>arr[i];
        // }
        
        // solve(arr,n,k);
        solveE();
    }

    return 0;
}