//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public: 
	int solve(int sum,int i,string&str,vector<vector<int>>&dp)
	{
	    if(i==str.size())
	    {
	        return 1;
	    }
	    if(dp[sum][i]!=-1)
	        return dp[sum][i];
	    int ans=0;
	    int curr=0;
	    for(int j=i;j<str.size();j++)
	    {
	        curr+=str[j]-'0';
	        if(curr>=sum)
	        {
	            ans+=solve(curr,j+1,str,dp);
	        }
	    }
	    return dp[sum][i]=ans;
	}
	int TotalCount(string str){
	    vector<vector<int>>dp(1000,vector<int>(str.size(),-1));
	    return solve(0,0,str,dp);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends