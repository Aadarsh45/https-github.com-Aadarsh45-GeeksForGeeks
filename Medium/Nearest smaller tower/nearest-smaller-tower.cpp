//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n= arr.size() ; 
        stack<pair<int , int>> st1,st2 ;
        vector<int>nsl,nsr ;
        for(int i =0 ; i< n ;i++ )
        {
            
            if(st1.empty())
            nsl.push_back(-1) ;
            else if(st1.size()>0 && st1.top().first<arr[i])
            nsl.push_back(st1.top().second) ; 
            else if(st1.size()>0 && st1.top().first>=arr[i])
            {
                 
                 while(st1.size()>0 && st1.top().first>=arr[i])
                    st1.pop() ;
                    if(st1.empty())
                    nsl.push_back(-1) ;
                    else
                    nsl.push_back(st1.top().second) ; 
            }
            
            
            st1.push({arr[i], i }) ; 
        }
        
        for(int i =n-1 ;i>=0 ;i-- )
        {
             if(st2.empty())
            nsr.push_back(-1) ;
            else if(st2.size()>0 && st2.top().first<arr[i])
            nsr.push_back(st2.top().second) ; 
            else if(st2.size()>0 && st2.top().first>=arr[i])
            {
                 
                 while(st2.size()>0 && st2.top().first>=arr[i])
                    st2.pop() ;
                    if(st2.empty())
                    nsr.push_back(-1) ;
                    else
                    nsr.push_back(st2.top().second) ; 
            }
             
            
            st2.push({arr[i], i }) ; 
        }
        reverse(begin(nsr), end(nsr)) ;
        
        vector<int>ans(n) ;

        for(int i =0 ; i<n ;i++ )
        {
            if(nsl[i]==-1 && nsr[i]==-1)
                 ans[i]=-1 ;
             else if(nsl[i]==-1 || nsr[i]==-1)    
                 {
                nsl[i]==-1 ? ans[i] =nsr[i] : ans[i] =nsl[i] ;
                 }
                 else if((i-nsl[i]+1) < (nsr[i]-i+1))
                 {
                     ans[i] = nsl[i] ;
                 }
                 else if((i-nsl[i]+1) > (nsr[i]-i+1))
                 {
                     ans[i] =nsr[i];  
                 }
                 else if((i-nsl[i]+1) == (nsr[i]-i+1))
                 {
         arr[nsl[i]] <arr[nsr[i]] ? ans[i] = nsl[i] : (arr[nsl[i]] > arr[nsr[i]] ? ans[i] = nsr[i] : ans[i] =nsl[i]);    ; 
                   
                 }
        }
        
        return ans; 
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends