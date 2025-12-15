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

vector<int> getSieve(int n){
vector<int>primes(n+1,1);
primes[0] = 0;
primes[1] = 0;
for(int i=2;i*i<=n;i++){
if(primes[i]==1){
for(int j = i*i ; j<=n;j+=i){
primes[j] = 0;
}
}
}
return primes;
}

class DisjointSet{
    //Either use by size or by rank
    //Ek sath mt use krna
    vi rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUPar(int node){
        if(parent[node]==node)return node;
        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        
    }
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

vi spfFind(int n){
    vi spf(n+1,1e9);
    vi primes(n+1,1);
    primes[0]=0;
    primes[1]=0;
    for (ll i = 2; i <= n; i++)
    {
        if(primes[i]){
            spf[i]=i;
            for (ll j = i*i; j < n; j+=i)
            {
                primes[j]=0;
                spf[j]=min(spf[j],(int)i);
            }
            
        }
    }

    return spf;
    
}

void solve() {
    // Write your solution here
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