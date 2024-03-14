//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        vector<vector<int>>top(n,vector<int>(n,0));
        vector<vector<int>>left(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='X')
                {
                    if(i!=0)
                    {
                        top[i][j]=top[i-1][j]+1;
                    }else
                        top[i][j]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='X')
                {
                    if(j!=0)
                    {
                        left[i][j]=left[i][j-1]+1;
                    }else
                        left[i][j]=1;
                }
            }
        }
        int maxSq=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(top[i][j]==0||left[i][j]==0)
                    continue;
                int currval=min(top[i][j],left[i][j]);
                while(currval>0)
                {
                    int top1=i-currval+1;
                    int left1=j-currval+1;
                    if(left[top1][j]>=currval&&top[i][left1]>=currval)
                    {
                        maxSq=max(maxSq,currval);
                        break;
                    }
                    currval--;
                }
            }
        }
        return maxSq;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends