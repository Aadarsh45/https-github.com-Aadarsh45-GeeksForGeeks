//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
       
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({a[i], i});
        }
        sort(v.begin(), v.end());
        
        int max_i = v[n-1].second;
        int diff = 0;
        
        for(int i = n-2; i>=0; i--){
            max_i = max(max_i, v[i+1].second);
            diff = max(diff, max_i - v[i].second);
        }
        
        return diff;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends