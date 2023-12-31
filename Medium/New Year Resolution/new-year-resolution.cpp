//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    int solve(int idx,int sum,int n,vector<vector<int>>&dp,int coins[])
    {
        if(sum>2024)
            return 0;
        if(idx==n)
        {
            if(sum==0)
                return 0;
            if(sum==2024||sum%20==0||sum%24==0)
                return 1; 
            return 0;
        }
        if(dp[idx][sum]!=-1)
        {
            return dp[idx][sum];
        }
        int ans1=solve(idx+1,sum+coins[idx],n,dp,coins);
        int ans2=solve(idx+1,sum,n,dp,coins);
        return dp[idx][sum]=max(ans1,ans2);
    }
    int isPossible(int n , int coins[]) 
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=coins[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(0,0,n,dp,coins);
        
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends