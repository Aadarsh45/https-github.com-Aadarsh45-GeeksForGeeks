//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
private:
    void sub_sum(int idx,vector<int> &arr,int n,vector<int> &ds,int sum){
        if(idx == n){
            ds.push_back(sum);
            return;
        }
        
        
         sub_sum(idx+1,arr,n,ds,sum+arr[idx]);
        
         sub_sum(idx+1,arr,n,ds,sum);
        
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ds;
        
        
        sub_sum(0,arr,N,ds,0);
        
        return ds;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends