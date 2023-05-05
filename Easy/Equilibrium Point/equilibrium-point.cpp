//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
   // Using two pointer

int equilibriumPoint(long long a[], int n) {
        int i=0, j=n-1;
        long long prefix=0, suffix=0;
        while(i<=j){
            if(i==j && prefix==suffix){
                return i+1;
            }
            if(prefix<=suffix){
                prefix += a[i];
                i++;
            }else{
                suffix += a[j];
                j--;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends