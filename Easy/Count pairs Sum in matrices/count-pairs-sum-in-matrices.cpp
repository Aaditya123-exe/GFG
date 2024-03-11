//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    vector<int>v1,v2;
	    int cnt=0;
	    for(int i=0;i<mat1.size();i++)
	    {
	        for(int j=0;j<mat1[i].size();j++)
	        {
	            v1.push_back(mat1[i][j]);
	            v2.push_back(mat2[i][j]);
	        }
	    }
	    for(int i=0;i<v1.size();i++)
	    {
	        if(v1[i]>x)
	        {
	            break;
	        }
	        int curr=x-v1[i];
	        int l=0,h=v2.size()-1;
	        while(l<=h)
	        {
	            int mid=(l+h)/2;
	            if(v2[mid]==curr)
	            {
	                cnt++;
	                break;
	            }else if(v2[mid]<curr)
	            {
	                l=mid+1;
	            }else{
	                h=mid-1;
	            }
	        }
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends