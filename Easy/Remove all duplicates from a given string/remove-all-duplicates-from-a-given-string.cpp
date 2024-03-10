//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	      unordered_map<char,int>mp;
        for(char x: str)
        {
            mp[x]++;
        }
        string res;
       
       for(auto x: str)
       {
           if(mp.find(x)!=mp.end()&& mp[x]>0)
           {
               res+=x;
               mp[x]=0;
           }
       }
        return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends