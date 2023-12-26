//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        vector<int>ans;
        int N=matrix.size();
        int i=0;
        while(i<N)
        {
            int j=i;
            int k=0;
            while(j>=0)
            {
                ans.push_back(matrix[k][j]);
                j--;
                k++;
            }
            i++;
        }
        i=1;
        while(i<N)
        {
            int j=i;
            int k=N-1;
            while(j<N)
            {
                ans.push_back(matrix[j][k]);
                k--;
                j++;
            }
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
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends