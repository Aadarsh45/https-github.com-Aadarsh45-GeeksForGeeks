//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    bool isprime(int a){
        if (a <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(a); i++)
        if (a % i == 0) return false;
 
    return true;
        
    }
    
    int minNumber(int arr[],int N)
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        int P=0;
        while(true){
            if( isprime(sum)) return P;
            else{
                sum++;
                P++;
            }
        }
        
        return P;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends