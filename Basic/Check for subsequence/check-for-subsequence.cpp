//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

// } Driver Code Ends

class Solution{
    public:
    bool isSubSequence(string a, string b) 
    {
        int i=0,j=0;
        while(i<a.size()&&j<b.size())
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i==a.size();
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0; 
} 

// } Driver Code Ends