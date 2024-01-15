//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
        int max_courses(int n, int total, vector<int> &cost)

    {

        //Code Here

        vector<vector<int>> dp(n + 1, vector<int>(total+1,0));

        for(int ind=n-1;ind>=0;ind--){

            for(int j = 0; j<=total;j++){

                int pick = -1001;

                if(j >= cost[ind]){

                    pick = 1 + dp[ind + 1][j - (cost[ind] - (int)((0.9)*(cost[ind])))];

                }

                int not_pick = dp[ind + 1][j];

                dp[ind][j] = max(pick, not_pick);

            }

        }

        return dp[0][total];

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
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends