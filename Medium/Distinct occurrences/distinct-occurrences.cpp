//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int MOD=1e9+7;
    int solve(int i,int j,string s,string t,vector<vector<int>>&dp)
    {
        if(j==t.size())
        {
            return 1;
        }
        if(i==s.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j]%MOD;
        }
        int ans=0;
        if(s[i]==t[j])
        {
            ans=(solve(i+1,j+1,s,t,dp)%MOD+solve(i+1,j,s,t,dp)%MOD)%MOD;
        }else{
            ans=solve(i+1,j,s,t,dp)%MOD;
        }
        return dp[i][j]=ans;
    }
    int subsequenceCount(string s, string t)
    {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,s,t,dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends