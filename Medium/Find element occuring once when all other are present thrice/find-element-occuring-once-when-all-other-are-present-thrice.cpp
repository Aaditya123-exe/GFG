//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int n) {
        long long int sum=0;
        unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            st.insert(arr[i]);
            sum+=arr[i];
        }
        long long int total=0;
        for(auto&val:st)
        {
            total+=3*val;
        }
        int rem=(total-sum)/2;
        return rem;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends