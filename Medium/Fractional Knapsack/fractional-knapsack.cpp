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
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        vector<pair<double,int>>freq;
        for(int i=0;i<n;i++)
        {
            double curr=arr[i].value/(arr[i].weight*1.0);
            freq.push_back({curr,i});
            // cout<<freq[i].first<<" "<<freq[i].second<<endl;
        }
        sort(freq.rbegin(),freq.rend());
        double value=0;
        int i=0;
        while(w>0&&i<n)
        {
            int wt=arr[freq[i].second].weight;
            // cout<<wt<<endl;
            if(w>=wt)
            {
                value+=arr[freq[i].second].value;
                w-=wt;
                // cout<<value<<" "<<w<<endl;
            }else{
                value+=freq[i].first*w;
                w=0;
                // cout<<value<<" "<<w<<endl;
            }
            i++;
        }
        return value;
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