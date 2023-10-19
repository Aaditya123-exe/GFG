//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        /*
        2x5 matrix
        2 4  8  10 20
        2 10 12 12 20
        4 15 18 18 20

        Array:
        2 2 4 4 8 10 10 12 12 15 18 18 20 20 20
        0 1 2 3 4  5  6  7 8  9  10 11 12 13 14

        we have to identify if any monotonic fun is there

        X function : tell no of values less than or equal to given number
        2 2
        4 4
        8 5
        10 7
        it is increasing in nature and monotonic

        consider each elem and check if it is median
        eg: take 8, check value less or equal to 8, ans is 5 which is less than median index i.e 7
            take 18, value less than or equal to it is 11, greater than middle index so it can be median

            median:20->15->12
            l=1, r=40 mid=20, value less or equal than 20 =>15, lies on right hand side of middle so move to left
            l=1, r=19 mid=10, value -//-               10 =>7 , lies on left hand as its not greater than middle,move to right
            l=11,r=19 mid=15, value                    15 =>10, lies on rhs and can be median
            l=11,r=14 mid=12, value                    12 =>9 , greater than 7(middle), can be median
            l=11,r=11 mid=11, value                    11 =>7 , lies on lhs, move to right
            l=12,r=11 (l>r) break

            median=12

            find no of ele<=X in matrix
            take X=10
            find using upperbound(arr,10) for each row

                           upperbound
            2 4  8  10 20   4
            2 10 12 12 20   2
            4 15 18 18 20   1

            total=7(value less than or equal to 10)

            TC:log2(1e9)xNxlog2(M)
            SC:O(1)
        */
        int l = 1, r = 1e9;
        int median = 0;
        int total = R * C;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int lessthanequal = 0;
            for (int i = 0; i < R; i++)
            {
                int ub = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                lessthanequal += ub;
            }
            if (lessthanequal > total / 2)
            {
                median = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return median;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends