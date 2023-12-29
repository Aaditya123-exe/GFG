//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
 int kSubstrConcat (int n, string s, int k)
    {
        // Your Code Here
        if(n%k != 0)
            return 0;
        
        int i, j;
        
        map<string, int> m;
        
        for(i=0; i <= n-k; i += k){
            string sub = s.substr(i, k);
            
            m[sub]++;
            
        }
        
        if(m.size() > 2)
            return 0;
        
        if(m.size() == 1)
            return 1;
        
        bool flag = false;
        for(auto it : m){
            if(it.second == 1){
                flag = true;
            }
        }
        
        if(flag)
            return 1;
        
        return 0;
        
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends