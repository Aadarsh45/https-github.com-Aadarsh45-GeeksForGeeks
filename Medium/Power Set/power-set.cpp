//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		void solve( string &s , int i , string &temp , vector<string>&ans )
        {
            if( i == s.size() )
            {
                if(temp!="")
                {
                    ans.push_back(temp) ;
                }
                
                return ;
            }
            
            
            temp += s[i] ;
            
            solve( s , i+1 , temp , ans ) ;
            
            temp.pop_back() ;
            
            solve( s , i +1 , temp , ans ) ;
            
            
        }
        vector<string> AllPossibleStrings(string s){
            // Code here
            vector<string>ans ;
            
            string temp = "" ;
            
            solve( s , 0 , temp , ans ) ;
            
            sort( ans.begin() , ans.end() ) ;
            
            return ans ;
        }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends