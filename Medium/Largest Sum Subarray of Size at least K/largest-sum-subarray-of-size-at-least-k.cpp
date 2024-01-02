//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    /*
    approach:calculate maxsum subarray till each index.
    take sum of k size window,at each index from k+1 to n,
    add a[i] and remove a[i-k] and then also check if addition of maxsum[i-k] increases sum.
    */
    long long int maxSumWithK(long long int a[], long long int n, long long int k)
    {
        vector<long long> maxsum(n + 1);
        maxsum[0] = a[0];
        long long currmax = a[0];
        for (int i = 1; i < n; i++)
        {
            currmax = max(currmax + a[i], a[i]);
            maxsum[i] = currmax;
        }
        long long sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += a[i];
        }
        long long result = sum;
        for (int i = k; i < n; i++)
        {
            sum += a[i] - a[i - k];
            result = max(result, sum);
            result = max(result, sum + maxsum[i - k]); // include the maximum sum till [i-k] also if it increases overall sum.
        }
        return result;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends