//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	
	public:
	void shuffleArray(int arr[],int n)
	{
	     // Your code goes here
        queue<int>q;
        int k = 0;


        for(int i = 0; i<n; i = i+2){
            
               if(i<n/2){
                   q.push(arr[i]);
                    q.push(arr[i+1]);
               }


           arr[i] = q.front();
           q.pop();
           arr[i+1] = arr[n/2 +(k++)];
        }
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
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends