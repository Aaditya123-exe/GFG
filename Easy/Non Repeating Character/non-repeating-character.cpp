//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
   char nonrepeatingCharacter(string s)
{
    unordered_map<char, int> fre;
    int idx = 0;
    for (int i = 0; i < s.size(); i++)
    {
        fre[s[i]]++;
        if (fre[s[idx]] > 1)
        {
            idx++;
            while (idx < s.size() && fre[s[idx]] > 1)
            {
                idx++;
            }
            if (idx == s.size())
                return '$';
        }
    }
    return s[idx];
}
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends