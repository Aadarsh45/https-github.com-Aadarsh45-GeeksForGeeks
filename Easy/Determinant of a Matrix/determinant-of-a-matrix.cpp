//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    vector<vector<int>> sub_matrix(vector<vector<int> > matrix, int row, int col)
    {
        int n= matrix.size();
        vector<vector<int>>sub(n-1, vector<int>(n-1, 0));
        int n_row=0, n_col=0;
         for (int i = 0; i < n; i++)
            {
                if (i != row)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j != col)
                        {
                            sub[n_row][n_col] = matrix[i][j];
                            n_col++;
                        }
                    }
                    n_col = 0;
                    n_row++;
                }
            }
            return sub;
    }
    int solve(vector<vector<int>> matrix, int n)
    {
        if(n==1) return matrix[0][0];
        if(n==2)
        {
            return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
        }
        int det=0;
        for( int i=0; i<n; i++)
        {
            int coef= pow(-1,i) * matrix[0][i] * solve( sub_matrix(matrix, 0, i) , n-1);
            det+=coef;
        }
        return det;
    }
    
    
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // code here
        return solve(matrix, n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends