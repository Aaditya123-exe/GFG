//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool solve(int asum,int k,int a[],int n)
    {
        int cnt=1;
        int currsum=0;
        for(int i=0;i<n;i++)
        {
            if(currsum+a[i]<=asum)
            {
                currsum+=a[i];
            }else{
                cnt++;
                if(a[i]>asum||cnt>k)
                    return false;
                currsum=a[i];
            }
        }
        return true;
        
    }
    int splitArray(int a[] ,int n, int k) {
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        int left=1,right=sum;
        int sumallowed=1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(solve(mid,k,a,n))
            {
                sumallowed=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return sumallowed;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends