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

#include <vector>
#include <string>
#include <set>
#include <algorithm> // For std::sort, std::transform
#include <cctype>    // For isalnum
#include <map>       // For custom sorting order

class Solution {
public:
    std::vector<std::string> validateCoupons(std::vector<std::string>& code, std::vector<std::string>& businessLine, std::vector<bool>& isActive) {
        int n = code.size();

        // Define valid business lines and their custom sort order
        std::map<std::string, int> bLineSortOrder;
        bLineSortOrder["electronics"] = 0;
        bLineSortOrder["grocery"] = 1;
        bLineSortOrder["pharmacy"] = 2;
        bLineSortOrder["restaurant"] = 3;

        std::set<std::string> bset;
        for (const auto& pair : bLineSortOrder) {
            bset.insert(pair.first);
        }
        
        std::vector<std::pair<std::string, std::string>> validCouponsData; 

        for (int i = 0; i < n; ++i) {
            
            if (code[i].empty()) {
                continue;
            }
            bool currentCodeIsValid = true;
            for (char c : code[i]) {
                if (!std::isalnum(c) && c != '_') { 
                    currentCodeIsValid = false;
                    break;
                }
            }
            if (!currentCodeIsValid) {
                continue; 
            }
            std::string currentBusinessLine = businessLine[i];
            std::transform(currentBusinessLine.begin(), currentBusinessLine.end(), currentBusinessLine.begin(), ::tolower);

            if (bset.find(currentBusinessLine) == bset.end()) {
                continue; 
            }


            if (!isActive[i]) {
                continue; 
            }


            validCouponsData.push_back({currentBusinessLine, code[i]});
        }


        std::sort(validCouponsData.begin(), validCouponsData.end(), [&](const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) {
            int orderA = bLineSortOrder[a.first];
            int orderB = bLineSortOrder[b.first];

            if (orderA != orderB) {
                return orderA < orderB;
            } else {
                return a.second < b.second; 
            }
        });

        vector<string> ans;
        for (int i = 0; i < validCouponsData.size(); ++i) {
            ans.push_back(validCouponsData[i].second);
        }
        return ans;
    }
};

void solveA() {
    // Write your solution here
    ll n,m;
    cin>>n>>m;
    vll a(n+1);
    vll b(m+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin>>b[i];
    }
    sort(all(a));

    int i=1;
    int j=n;
    ll cnt = 0;
    while (j>=1)
    {
        /* code */
        if(i<=m && a[j]>=i){
            cnt += b[i];
            i++;
        }
        else{
            cnt += b[a[j]];
        }
        j--;
    }
    
    cout<<cnt<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solveA();
    }

    return 0;
}