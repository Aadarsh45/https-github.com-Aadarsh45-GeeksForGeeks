//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
      int n=a.size(), m= a[0].size();
      vector<vector<int>>sum(n,vector<int>(m));
      
      for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
              sum[i][j]= a[i][j]+ (j>0? sum[i][j-1]: 0);
          }
      }
      
      int mx=0,sr=0,er=-1,sc=0,ec=-1;
      
      for(int c1=0; c1<m; c1++){
          for(int c2=c1; c2<m; c2++){
              vector<int>temp(n,0);
              
              for(int i=0; i<n; i++){
                  temp[i]= sum[i][c2]-(c1>0 ? sum[i][c1-1]:0);
              }
              
              unordered_map<int,int>mp;int sum=0;
              mp[0]=-1;
              for(int i=0; i<n; i++){
                  sum+=temp[i];
                  if(mp.find(sum)!=mp.end()){
                      int area= (c2-c1+1)*(i-mp[sum]);
                      if(area>mx){
                          mx=area;
                          sr=mp[sum]+1;
                          er=i;
                          sc=c1;
                          ec=c2;
                      }
                  }
                  else{
                      mp[sum]=i;
                  }
              }
          }
      }
      
      vector<vector<int>>res;
      
      for(int i=sr; i<=er; i++){
          vector<int>temp;
          for(int j=sc; j<=ec; j++){
              temp.push_back(a[i][j]);
          }
          res.push_back(temp);
      }
      
      return res;
  }
};


//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends