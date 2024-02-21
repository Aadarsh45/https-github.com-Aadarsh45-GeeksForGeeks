//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod=1003;
    //pair<int,int>=(true,false);
    pair<int,int>solve(int i,int j,string s,vector<vector<pair<int,int>>>&dp){
        
        if(i==j){
            pair<int,int>p={0,0};
            if(s[i]=='T'){
                p.first=1;
                p.second=0;
            }
            else{
                p.first=0;
                p.second=1;
            }
            return p;
        }
        if(dp[i][j].first != -1 && dp[i][j].second!= -1){
            return dp[i][j];
        }
        pair<int,int>p={0,0};
        for(int ind=i;ind<=j;ind++){
            if(s[ind]=='|' || s[ind]=='&' || s[ind]=='^'){
                pair<int,int>left=solve(i,ind-1,s,dp);
                pair<int,int>right=solve(ind+1,j,s,dp);
                int total=(left.first+left.second)*(right.first+right.second);
                if(s[ind]=='|'){
                    int t=(left.first*right.second)+(left.second*right.first)+(left.first*right.first);
                    int f=total-t;
                    p.first=(p.first+t)%mod;
                    p.second=(p.second+f)%mod;
                }
                else if(s[ind]=='&'){
                    int t=left.first * right.first;
                    int f=total-t;
                    p.first=(p.first+t)%mod;
                    p.second=(p.second+f)%mod;;
                }
                else{
                    int t=left.first*right.second + left.second * right.first;
                    int f=total-t;
                    p.first=(p.first+t)%mod;;
                    p.second=(p.second+f)%mod;
                }
            }
        }
        return dp[i][j]=p;
    }
    int countWays(int n, string s){
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(n,{-1,-1}));
        pair<int,int>p=solve(0,n-1,s,dp);
        return p.first;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends