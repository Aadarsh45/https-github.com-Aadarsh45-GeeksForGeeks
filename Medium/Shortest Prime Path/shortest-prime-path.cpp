//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    int solve(int Num1,int Num2)
    { 
      int n=10000;
       vector<bool>prime(n,true); 
       for(int i=2;i*i<=9999;i++)
        {
            if(prime[i])
            {
                for(int j=i*i;j<=9999;j=j+i)
                prime[j]=false;
            }
        }
      unordered_set<string>vis;
      string dest=to_string(Num2);
      queue<string>q;
      q.push(to_string(Num1));
      vis.insert(to_string(Num1));
      int res=0;
      while(!q.empty())
      {
          int size=q.size();
          while(size--)
          {
              string curr=q.front();
              q.pop();
              if(curr==dest)
              return res;
              
              string temp=curr;
              for(int i=0;i<4;i++)
              {
                  temp=curr;
                  for(char j='0';j<='9';j++)
                  {
                      if(i==0 && j=='0')
                      continue;
                      temp[i]=j;
                      if(vis.find(temp)==vis.end() && prime[stoi(temp)]==true)
                      {
                          vis.insert(temp);
                          q.push(temp);
                      }
                  }
              }
          }
          res++;
      }
      return -1 ;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends