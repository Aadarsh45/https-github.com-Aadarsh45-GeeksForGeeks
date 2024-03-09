//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
         int p = pow(2, r);
        int dig = n / p;
        int ind = n % p;
        string cp = "";
        cp.push_back(s[dig]);
        for(int i = 0; i < r; i++){
            string neu = "";
            for(auto j : cp){
                if(j == '1'){
                    neu.push_back('1');
                    neu.push_back('0');
                }else{
                    neu.push_back('0');
                    neu.push_back('1');
                }
            }
            cp = neu;
        }
        return cp[ind];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends