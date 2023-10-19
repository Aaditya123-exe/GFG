//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X)
    {
        vector<int> vis(V, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int level = -1;
        while (!q.empty())
        {
            level++;
            int n = q.size();
            for (int i = 0; i < n; i++) // Fixed the loop initialization
            {
                int node = q.front();
                q.pop();
                if (node == X)
                    return level;
                for (int j = 0; j < adj[node].size(); j++) // Fixed the loop initialization
                {
                    if (!vis[adj[node][j]])
                    {
                        vis[adj[node][j]] = 1;
                        q.push(adj[node][j]);
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends