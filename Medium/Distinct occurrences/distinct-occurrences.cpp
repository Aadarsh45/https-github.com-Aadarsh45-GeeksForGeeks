//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    long long int M = 1e9+7;
   
    int solve(int i,int j,int n,int m,string s,string t,vector<vector<int>>&dp){
        if(j == m) return 1;
        
        if(i == n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int take=0,not_take=0;
        if(s[i] == t[j]){
        
            take= solve(i+1,j+1,n,m,s,t,dp);
            take=take%M;
        }
        not_take= solve(i+1,j,n,m,s,t,dp);
        not_take=not_take%M;
        
        return dp[i][j] = (take+not_take)%M;
        
        
    }
    int subsequenceCount(string s, string t)
    {int n = s.length();
    int m = t.length();
    vector<vector<int>>dp(n,vector<int>(m,-1));
     int ans =  solve(0,0,n,m,s,t,dp);
    //  for(int i =1;i<n;i++){
    //      for(int j =0;j<m;j++){
    //          cout<<dp[i][j]<<" ";
    //      }
    //      cout<<endl;
    //  }
     return ans%M;
    
    
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends