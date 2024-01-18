//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<pair<int,int>> range;
        for(int i=0;i<n;i++){
            if(gallery[i]!=-1)
                range.push_back({max(0,i-gallery[i]),min(n-1,i+gallery[i])});
        }
        sort(range.begin(),range.end());
        
        
        int x=0,ans=0,i=0,cur=0;
        while(x<=n-1){
            cur=INT_MIN;
            while(i<range.size() && range[i].first<=x){
                cur=max(cur,range[i].second);
                i++;
            }
            if(cur==INT_MIN)
                return -1;
            ans++;
            x=cur+1;
        }
        return ans;
        
        
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends