//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        bool flag=true;
        int num=0;
        if(s[0]=='-')
        {
            flag=false;
            for(int i=1;i<s.size();i++)
            {
                if(s[i]>='0'&&s[i]<='9')
                {
                 int curr=(int)(s[i]-'0');
                 num=num*10+curr;   
                }
                else{
                    return -1;
                }
            }
            num*=-1;
        }else{
            for(int i=0;i<s.size();i++)
            {
                if(s[i]>='0'&&s[i]<='9')
                {
                 int curr=(int)(s[i]-'0');
                 num=num*10+curr;   
                }
                else{
                    return -1;
                }
            }
        }
        return num;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends