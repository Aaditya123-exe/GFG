//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> pattern(int N){
       if(N <= 0) return {N};
        vector<int> ans;
        int temp = N;
        ans.push_back(temp);
        temp -= 5;
        bool sub = true;
        bool add = false;
        while(temp <= N) {
            ans.push_back(temp);
            if(temp <= 0) {
                sub = false;
                add = true;
            }
            if(add) temp += 5;
            if(sub) temp -= 5;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends