//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int solve(string a,set<string>&st)
    {
        if(a.size()==0)
        {
            return 1;
        }
        for(int i=0;i<a.size();i++)
        {
            string tmp=a.substr(0,i+1);
            string tmp2=a.substr(i+1);
            if(st.find(tmp)!=st.end()&&solve(tmp2,st))
            {
                return 1;
            }
        }
        return 0;
    }
    int wordBreak(string a, vector<string> &b) {
        set<string>st;
        for(string s:b)
        {
            st.insert(s);
        }
        return solve(a,st);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends