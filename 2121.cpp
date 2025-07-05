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

// void solveA(vll &a, ll n, ll s)
// {
//     // Write your solution here
//     ll sum2 = 0;
//     for (int i = 1; i < n; i++)
//     {
//         sum2 += (a[i]-a[i-1]);
//     }
    
//     a.push_back(s);
//     sort(all(a));
//     int idx = -1;
//     for (int i = 0; i < a.size(); i++)
//     {
//         if(a[i]==s){
//             idx = i;
//             break;
//         }
//     }
//     ll sum = 0;
//     for (int i = idx+1; i < a.size(); i++)
//     {
//         sum += (a[i]-a[i-1]);
//     }
//     ll mn = sum;
//     sum = 0;
//     if(idx == a.size()-1){
//         cout<<sum2+(a[idx]-a[idx-1])<<endl;
//         return;
//     }
//     if(idx==0){
//         cout<<sum2+(a[idx+1]-a[idx])<<endl;
//         return;
//     }
//     for (int i = 1; i <= idx; i++)
//     {
//         /* code */
//         sum += (a[i]-a[i-1]);
//     }
   
//     mn = min(mn,sum);
  
//     cout<<sum2 + mn<<endl;
// }

void solveB(string&s,int n){
    set<char>st;
    st.insert(s[0]);
    for (int i = 1; i < n-1; i++)
    {
        if(st.count(s[i]) || s[i]==s[n-1]){
            yes;
            return;
        }
        st.insert(s[i]);
    }
    no;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        // ll n, s;
        // cin >> n >> s;
        // vll a(n);
        // for (int i = 0; i < n; i++)
        // {
        //     cin >> a[i];
        // }

        //solveA(a, n, s);
        ll n;
        cin>>n;
        string s;
        cin>>s;
        solveB(s,n);
    }

    return 0;
}