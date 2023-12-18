//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     int gameOfXor(int n , int A[]) {
        // code here
        int ans=0;
        for(int i=0;i<32;i++){
            int p = 1<<i;
            int cnt=0;
            for(int j=0;j<n;j++){
                if(p&A[j]){
                    cnt+=(j+1)*(n-j);
                }
            }
            if(cnt%2!=0){
                ans+=p;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends