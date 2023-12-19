//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        // code here 
        string ans="";
        ans.push_back(s[0]);
        int n=s.size();
        int dp[n+1][n+1]={0};
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                if(ans.size()<2)
                {
                    ans=s.substr(i,2);
                }
            }
            else
                dp[i][i+1]=0;
        }
        for(int len=3;len<=n;len++)
        {
            for(int win=0;win<=n-len+1;win++)
            {
                int end=win+len-1;
                if(s[win]==s[end]&&dp[win+1][end-1])
                {
                    dp[win][end]=1;
                    if(ans.size()<len)
                    {
                        ans=s.substr(win,len);
                    }
                }
                else
                    dp[win][end]=0;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends