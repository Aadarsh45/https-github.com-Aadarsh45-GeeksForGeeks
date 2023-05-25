//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
       sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0,j=0;i<a.length(),j<b.length();i++,j++){
            if(a[i]==b[j]){
                
            }
            else{
                return false;
            }
        }
        return true; 
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends