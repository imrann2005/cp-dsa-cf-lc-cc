
#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int xor1 = 0;
	int xor2 = 0;
	
	int i=1;
	while(i<n){
	    int temp;
	    cin >> temp;
	    xor1 ^= temp;

	    i++;
	}
	
	for(int i=1;i<=n;i++){
	    xor2 ^= i;
	}
	
	int ans = xor1^xor2;
	std::cout <<ans;
	
	
	
	return 0;
}