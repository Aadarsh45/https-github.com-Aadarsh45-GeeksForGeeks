//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
    public:
   vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    {   vector<int>ans;
        unordered_map<long,int>m;
        for(int i=0;i<M;i++){
            long int val =0;
            long long z = 1;
            for(int j =0;j<N;j++){
                val+=(z*matrix[i][j]);
                z*=2;
            }
            if(m[val]>0){
                ans.push_back(i);
            }
            m[val]++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends