//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(vector<int> &arr, int idx, int n, set<vector<int>> &st)
    {
        if (idx == n - 1)
        {
            st.insert(arr);
            return;
        }
        for (int j = idx; j < n; j++)
        {
            swap(arr[j], arr[idx]);
            solve(arr, idx + 1, n, st);
            swap(arr[j], arr[idx]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr, int n)
    {
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(arr.begin(), arr.end());
        solve(arr, 0, n, st);
        for (auto &val : st)
        {
            ans.push_back(val);
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
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends