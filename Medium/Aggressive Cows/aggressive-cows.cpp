//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

       bool check(int mindist, int k, vector<int> &stalls)
    {
        int cnt = 1;
        int prev = stalls[0];
        int i = 1;
        while (i < stalls.size())
        {
            if (stalls[i] - prev >= mindist)
            {
                cnt++;
                prev = stalls[i];
            }
            i++;
        }
        return cnt>=k;
    }
    int solve(int n, int k, vector<int> &stalls)
    {
        sort(stalls.begin(), stalls.end());
        int l = 0, r = stalls[n - 1];
        int dist = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(mid, k, stalls))
            {
                l = mid + 1;
                dist = mid;
            }
            else
                r = mid - 1;
        }
        return dist;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends