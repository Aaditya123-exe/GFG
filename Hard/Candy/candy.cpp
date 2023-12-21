//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int n, vector<int> &rate) {
        // code here
        int cnt=0;
        vector<int>candy(n);
        candy[0]=1;
        for(int i=1;i<n;i++)
        {
            if(rate[i]>rate[i-1])
            {
                candy[i]=candy[i-1]+1;
            }
            else{
                candy[i]=1;
            }
        } 
        for(int i=n-1;i>0;i--)
        {
            if(rate[i]>rate[i-1])
            {
                if(candy[i]<=candy[i-1])
                    candy[i]=candy[i-1]+1;
                    
            }
            else if(rate[i]<rate[i-1]){
                if(candy[i]>=candy[i-1])
                    candy[i-1]=candy[i]+1;
            }
        } 
        for(int i=0;i<n;i++)
        {
            cnt+=candy[i];
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends