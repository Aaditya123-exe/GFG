//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int smallestSubstring(string s) {
        int l0=-1,l1=-1,l2=-1;
        int i = 0, n = s.size();
        int size=n+1;
        while (i < n) {
            if(s[i]=='0')
            {
                l0=i;
            }
            else if(s[i]=='1')
            {
                l1=i;
            }else{
                l2=i;
            }
            if(l0!=-1&&l1!=-1&&l2!=-1)
            {
                size=min(size,i-min({l0,l1,l2})+1);
            }
            i++;
        }
        
        if (size==n+ 1)
            return -1;
        
        return size;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends