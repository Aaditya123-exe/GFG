//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        long long sum=0;
        int i=0,j=0;
        long long tmp=0;
        while(i<n)
        {
            tmp+=arr[i];
            while(i-j+1>k)
            {
                tmp-=arr[j++];
            }
            sum=max(tmp,sum);
            i++;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends