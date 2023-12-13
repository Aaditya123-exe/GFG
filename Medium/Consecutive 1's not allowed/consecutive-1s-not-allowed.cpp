//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    #define ll long long
    ll mod = 1e9 + 7;

    ll countStrings(int n) {
        // code here
        ll dp[n + 1][2];
        dp[1][0] = 1;
        dp[1][1] = 1;
        dp[2][0] = 2;
        dp[2][1] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][1] = dp[i - 1][0] % mod;
        }
        return (dp[n][0] + dp[n][1]) % mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends