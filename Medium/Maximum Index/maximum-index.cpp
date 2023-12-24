//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        vector<int>pre(n),post(n);
        pre[0]=a[0];
        int minpre=a[0];
        for(int i=1;i<n;i++)
        {
            minpre=min(minpre,a[i]);
            pre[i]=minpre;
        }
        int maxpost=a[n-1];
        post[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxpost=max(maxpost,a[i]);
            post[i]=maxpost;
        }
        int i=0,j=0;
        int diff=0;
        while(i<n&&j<n)
        {
            if(pre[i]<=post[j])
            {
                diff=max(diff,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return diff;
        
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends