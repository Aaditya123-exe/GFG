//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	vector<string> AllPossibleStrings(string s){
	    // Code here
	    
	    int n = s.length();
	    vector<string> ans;
	    
	    for(int i = 1; i < (1 << n); i++) {
	        string temp = "";
	        for(int j = 0; j < n; j++) {
	            // cout << i << " " << (1 << j) << " " << ((1 << j) & i) << endl;
	            if(((1 << j) & i) != 0) {
	                temp = temp + s[j];
	            }
	        }
	        // cout << temp << endl;
	        ans.push_back(temp);
	    }
	    sort(ans.begin(), ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends