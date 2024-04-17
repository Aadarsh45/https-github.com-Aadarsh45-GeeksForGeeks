//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
      int merge(int arr[],int temp[],int l,int m,int r)
    {
        int i,j,k;
        int cnt=0;
        i=l; j=m; k=l;
        
        while((i<=m-1) && (j<=r))
        {
            if(arr[i]<=arr[j])
                temp[k++]=arr[i++];
            else
            {
                temp[k++]=arr[j++];
                cnt+=m-i;
            }
        }
        while(i<=m-1) temp[k++]=arr[i++];
        
        while(j<=r) temp[k++]=arr[j++];
        
        for(i=l;i<=r;i++)
            arr[i]=temp[i];
        return cnt;
        
    }
    int mS(int arr[],int temp[],int l,int r)
    {
        int m,cnt=0;
        if(r>l)
        {
            m=(r+l)/2;
            cnt+=mS(arr,temp,l,m);
            cnt+=mS(arr,temp,m+1,r);
            cnt+=merge(arr,temp,l,m+1,r);
        }
        return cnt;
    }
    int countPairs(int arr[] , int n ) 
    {   
        for(int i=0;i<n;i++)
        {
            arr[i]=i*arr[i];
        }
        int temp[n];
        int ans=mS(arr,temp,0,n-1);
        
        return ans;  
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends