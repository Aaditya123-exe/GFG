//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    int cnt=0;
	    for(int i=a;i<=b;i++)
	    {
	        int num=i;
	        while(num%2==0)
	        {
	            cnt++;
	            num/=2;
	        }
	        for(int j=3;j*j<=num;j+=2)
	        {
	            while(num%j==0)
	            {
	                cnt++;
	                num/=j;
	            }
	        }
	        if(num>2)
	        {
	            cnt++;
	        }
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends