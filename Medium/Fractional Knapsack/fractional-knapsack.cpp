//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
    public:
        static bool cmp(pair<pair<int,int>,double>p, pair<pair<int,int>,double>q)
    {
        return p.second > q.second;
    }
    //Function to get the maximum total value in the knapsack.
   double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<pair<int,int>,double>>vec;
        
        for(int i=0; i<n; i++)
        {
            vec.push_back({{arr[i].value,arr[i].weight},(double)arr[i].value/(double)arr[i].weight});
        }
        
        sort(vec.begin(),vec.end(),cmp);
         double total = 0;
        
        for(int i=0; i<n; i++)
        {
            if(W==0) break;
            if(W>=vec[i].first.second)
            {
                total+= vec[i].first.first;
                W = W-vec[i].first.second;
            }
            else
            {
                total+= (vec[i].first.second - (vec[i].first.second-W)) * vec[i].second;
                W=0;
            }
            
        }
        return total;
        
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends