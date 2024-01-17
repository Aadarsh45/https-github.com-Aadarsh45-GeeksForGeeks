//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   void solve(vector<int> &arr ,int idx,int n,set<vector<int>> &s){
       if(idx == n){
           s.insert(arr);
           return;
       }
       for(int i =idx;i<n;i++){
           swap(arr[i],arr[idx]);
           solve(arr,idx+1,n,s);
           
           
           swap(arr[i],arr[idx]);
           
       }
   }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>> ans;
        set<vector<int>>s;
        solve(arr,0,n,s);
        for(auto it: s){
            ans.push_back(it);
        }
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends