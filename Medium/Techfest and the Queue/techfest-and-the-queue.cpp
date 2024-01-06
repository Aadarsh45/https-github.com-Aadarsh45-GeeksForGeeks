//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    int ans = 0;
	    for(int i = a; i <= b; ++i) {
	        int cnt = 0;
	        int n = i;
	        while(n%2 == 0) {
	            n >>= 1;
	            ++cnt;
	        }
	        
	        for(int j = 3; j*j <= n; j+=2) {
	            while(n%j == 0) {
	                n /= j;
	                ++cnt;
	            }
	        }
	        if(n > 2) {
	            ans += 1;
	        }
	        ans += cnt;
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends