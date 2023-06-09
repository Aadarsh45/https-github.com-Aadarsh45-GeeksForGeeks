//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void fun(int i,string &S,set<string> &ds,string cur){
        if(i==S.length()){
            ds.insert(cur);
            return;
        }
        for(int j=i;j<S.length();j++){
            swap(cur[i],cur[j]);
            fun(i+1,S,ds,cur);
        }
        
        
    }
    vector<string>find_permutation(string S)
    {
            // Code here there
            vector<string>  ds;
            set<string> ans;
            fun(0,S,ans,S);
            for(auto i:ans){
                ds.push_back(i);
            }
            return ds;
    }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends