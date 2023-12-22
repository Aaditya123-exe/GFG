//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &s,vector<int> &f){
        vector<int>ans;
        vector<pair<pair<int,int>,int>>vp;
        for(int i=0;i<s.size();i++)
        {
            vp.push_back({{f[i],s[i]},i+1});
        }
        sort(vp.begin(),vp.end());
        int prev=-1;
        for(int i=0;i<vp.size();i++)
        {
            if(vp[i].first.second>prev)
            {
                ans.push_back(vp[i].second);
                prev=vp[i].first.first;
            }
        }
        sort(ans.begin(),ans.end());
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
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends