//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    int mod=1e9+7;
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
	    for(int i=1;i<=sum;i++)
	    {
	        dp[0][1]=0;
	    }
	    dp[0][0]=1;
	    for(int i=1;i<=n;i++)
	    {
	        for(int tar=0;tar<=sum;tar++)
	        {
    	        int nottake=dp[i-1][tar];
    			int take=0;
    			if(arr[i-1]<=tar)
    			{
    				take=dp[i-1][tar-arr[i-1]];
    			}
    			dp[i][tar]=(take+nottake)%mod;
	        }
	    }
	    return dp[n][sum];
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends