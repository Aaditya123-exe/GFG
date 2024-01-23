//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre)
    {
        vector<int> ans;
        map<int, vector<int>> mp;
        map<int, int> inorder;
        for (int i = 0; i < m; i++)
        {
            mp[pre[i][1]].push_back(pre[i][0]);
            inorder[pre[i][0]]++;
        }
        queue<int> eq;
        for (int i = 0; i < n; i++)
        {
            if (inorder[i] == 0)
            {
                eq.push(i);
            }
        }
        if (eq.empty())
        {
            return {};
        }
        while (!eq.empty())
        {
            vector<int> &tmp = mp[eq.front()];
            ans.push_back(eq.front());
            inorder[eq.front()] = 0;
            eq.pop();
            for (int i = 0; i < tmp.size(); i++)
            {
                inorder[tmp[i]]--;
                if (inorder[tmp[i]] == 0)
                {
                    eq.push(tmp[i]);
                }
            }
        }
        for (auto &val : inorder)
        {
            if (val.second != 0)
            {
                return {};
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends