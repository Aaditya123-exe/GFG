//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    bool isPrime( int n )
    {
        for( int i = 2 ; i <= sqrt(n) ; i++ )
        {
            if(n%i==0) return false ;
        }
        
        return true ;
    }
    int solve(int num1,int num2)
    {   
      //code here
      
        unordered_set<int> seen;    // 
        queue<int> q;
        q.push(num1);
        seen.insert(num1);
        int levels=0;
        while(q.size()){
            int sz=q.size();
            while(sz--){        // process all nodes at the level in this iteration
                int num=q.front();
                q.pop();
                if(num==num2)   return levels;
                for(int i=0;i<4;i++){   // 3124 // pow(10,1) -> 10
                    string s = to_string(num) ;
                    
                    for( int j = 0 ; j <= 9 ; j++ )
                    {
                        s[i] = '0' + j ;
                        int temp = stoi(s) ;
                        if( temp > 1000  && !seen.count(temp) && isPrime(temp) )
                        {
                            seen.insert(temp) ;
                            q.push(temp)  ;
                        }
                    }
                    
                    }
                }
                levels++;
            }
          
        return -1;   
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends