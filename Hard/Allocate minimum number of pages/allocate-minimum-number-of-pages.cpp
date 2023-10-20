//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution
{
public:
    bool check(int mxvl, int A[], int n, int m)
    {
        int person = 1;
        int i = 0;
        int prev = 0;
        while (i < n)
        {
            if (prev + A[i] <= mxvl)
            {
                prev += A[i];
            }
            else
            {
                person++;
                if (person > m || A[i] >mxvl)
                    return false;
                prev = A[i];
            }
            i++;
        }
        return true;
    }
    int findPages(int A[], int N, int M)
    {
        if (N < M)
            return -1;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += A[i];
        }
        int l = 0, r = sum;
        int val = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(mid, A, N, M))
            {
                val = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return val;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends