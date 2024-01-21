//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
    public:
        int vertexCover(int n, vector<pair<int, int>> &edges) {
            int ans=n;
            for(int mask=0;mask<(1<<n);mask++)
            {
                bool fl=true;
                for(int i=0;i<edges.size();i++)
                {
                    int x=edges[i].first-1;
                    int y=edges[i].second-1;
                    int a=mask & (1<<x);
                    int b=mask & (1<<y);
                    if(a==0 && b==0)
                    {
                        fl=false;
                        break;
                    }
                }
                if(!fl)
                continue;
                int ct=0;
                for(int i=0;i<32;i++)
                {
                    int val=mask & (1<<i);
                    if(val!=0)
                    ct++;
                }
                ans=min(ans,ct);
            }
            return ans;
                // code here
            }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends