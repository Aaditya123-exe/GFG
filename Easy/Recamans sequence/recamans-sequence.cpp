//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        set<int>st;
        vector<int>ans(n);
        int start=0;
        for(int i=1;i<n;i++)
        {
            int curr=start-i;
            if(curr>0&&st.find(curr)==st.end())
            {
                start=curr;
            }else{
                start=start+i;
            }
            ans[i]=start;
            st.insert(start);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends