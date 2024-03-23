//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        int curr=1,prev=0;
        vector<int>ans;
        ans.push_back(0);
        ans.push_back(1);
        int i=2;
        int MOD=1e9+7;
        while(i<=n)
        {
            int tmp=(curr+prev)%MOD;
            prev=curr;
            curr=tmp;
            ans.push_back(tmp);
            i++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends