//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int idx, int n, int total, vector<int> &cost,  vector<vector<int>> &dp)
    {
        if (idx == n)
        {
            return 0;
        }
        if(total<=0)
            return 0;
        if (dp[idx][total] != -1)
        {
            return dp[idx][total];
        }
        int take = 0, nottake = 0;
        if (total >= cost[idx])
        {
            take = 1 + solve(idx + 1, n, total-cost[idx]/10.0, cost, dp);
        }

        nottake = solve(idx + 1, n, total, cost, dp);

        return dp[idx][total] = max(take, nottake);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n,vector<int>(total+1,-1));
        return solve(0, n, total, cost, dp);
    }
};




//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends