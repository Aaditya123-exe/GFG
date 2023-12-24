//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}

// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int a[],int n)
{
    int sum=0,elsum=0;
    for(int i=0;i<n;i++)
    {
        sum+=i*a[i];
        elsum+=a[i];
    }
    int mxsum=sum;
    for(int i=0;i<n;i++)
    {
        sum=sum+n*a[i]-elsum;
        mxsum=max(sum,mxsum);
    }
    return mxsum;
}