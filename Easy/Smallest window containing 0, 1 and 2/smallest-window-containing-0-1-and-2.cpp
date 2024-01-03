//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        int n = s.length();
        
        int i = 0, j = 0;
        
        int result = INT_MAX;
        int zero = 0;
        int one  = 0;
        int two  = 0;
        
        while(j < n) {
            if(s[j] == '0')
                zero++;
            else if(s[j] == '1')
                one++;
            else 
                two++;
            
            while(zero > 0 && one > 0 && two > 0 && j-i+1 >= 3) {
                result = min(result, j - i + 1);
                
                if(s[i] == '0') zero--;
                else if(s[i] == '1') one--;
                else if(s[i] == '2') two--;
                
                i++;
            }
            
            j++;
            
        }
        
        return result == INT_MAX ? -1 : result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends