//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int m){
        //base contition 
        //if get n numbers
        if(i==0)
            return 1;
            
        //if before getting n numbers our sequence reached 0
        if(m==0)
            return 0;
            
        // if we take the element and passing it half to previous element
        int take=solve(i-1,m/2);
        
        // if we are  not taking the element and decreasing it by one
        int notTake=solve(i,m-1);
        
        //return count of both the sequences 
        return take+notTake;
            
            
    }
    int numberSequence(int m, int n){
        return solve(n,m);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends