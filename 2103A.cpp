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

void solveA(vi &a, int n)
{
    // Write your solution here
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }
    cout << st.size() << endl;
}

void solveB(string &s, int n)
{
    int st = -1;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1'){
            st = i;
            break;
        }
    }
    int i = 0;
    int mx = 0;
    int idx = 0;
    int cnt = 0;
    while (i < n)
    {
        if (s[i] == '0')
        {
            cnt = 1;
            if(cnt > mx){
                idx = i;
                mx = cnt;
            }
            i++;
            mx = max(cnt,mx);
            while (i < n)
            {
                if (s[i] == '0')
                {
                    cnt++;
                    if(cnt > mx){
                        mx = cnt;
                        idx = i;
                    }
                    i++;
                }
                else{
                    break;
                }
            }
        }
        i++;
    }
    //cout<<idx<<endl;
    
    //cout<<st<<endl;
    while (st!=-1 && st<=idx)
    {
        swap(s[st],s[idx]);
        st++;
        idx--;
    }
    
    cnt = 0;
    i=0;
    //cout<<s<<endl;
    while (i<n)
    {
        /* code */
        if((s[i]=='0') && (i==0)){
            cnt++;
        }
        else if(i-1>=0 && s[i]==s[i-1]){
            cnt++;
        }
        else cnt+=2;
        //cout<<cnt<<" ";
        i++;
    }
    
    cout<<cnt<<endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin>>s;
        solveB(s,n);
    }

    return 0;
}