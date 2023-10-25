//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve(int currwt,int W,int N,int val[],int wt[],vector<int>&dp)
    {
        if(currwt==W)
            return 0;
        if(dp[currwt]!=-1)
            return dp[currwt];
        int ans=0;
        for(int i=0;i<N;i++)
        {
            if(currwt+wt[i]<=W)
            {
                ans=max(ans,val[i]+solve(currwt+wt[i],W,N,val,wt,dp));
            }
        }
        dp[currwt]=ans;
        return ans;
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
       vector<int>dp(W+1,-1);
       int currwt=0;
       return solve(currwt,W,N,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends