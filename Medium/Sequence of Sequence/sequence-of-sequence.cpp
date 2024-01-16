//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int curr,int end,int n,int m)
    {
        if(end==0)
            return 1;
        if(curr>m)
            return 0;
        int take=solve(curr*2,end-1,n,m);
        int nottake=solve(curr+1,end,n,m);
        return take+nottake;
    }
    int numberSequence(int m, int n){
        return solve(1,n,n,m);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends