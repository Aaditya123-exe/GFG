//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    long long int countPS(string s)
    {
        int n = s.size();
        long long dp[n][n] = {{0}};
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 3;
            }
            else
            {
                dp[i][i + 1] = 2;
            }
        }
        for (int len = 3; len <= n; len++)
        {
            for (int win = 0; win <= n - len; win++)
            {
                int end = win + len - 1;
                if (s[win] == s[end])
                {
                    dp[win][end] = (1 + dp[win][end - 1] + dp[win + 1][end]) % mod;
                }
                else
                {
                    dp[win][end] = (dp[win][end - 1] + dp[win + 1][end] - dp[win + 1][end - 1] + mod) % mod;
                }
            }
        }
        return dp[0][n - 1] % mod;
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends