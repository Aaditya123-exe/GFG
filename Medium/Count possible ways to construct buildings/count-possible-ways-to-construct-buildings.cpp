//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int MOD=1e9+7;
	int solve(int idx,vector<int>&dp)
	{
	    if(idx<=0)
	        return 1;
	    if(dp[idx]!=-1)
	        return dp[idx];
	   int pick=0;
	   pick=solve(idx-2,dp);
	   int npick=0;
	   npick=solve(idx-1,dp);
	   dp[idx]=(pick+npick)%MOD;
	}
	int TotalWays(int n)
	{
	    vector<int>dp(n+1,-1);
	    int ans=solve(n,dp);
	    return (1LL*ans*ans)%MOD;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends