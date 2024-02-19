//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{

public:

    int minValue(string s, int k){

        unordered_map<char,int>mp;

        for(auto it:s){

            mp[it]++;

        }

        priority_queue<int>pq;

        for(auto it:mp) {

            pq.push(it.second);

        }

        while(k--) {

            int freq=pq.top();

            freq--;

            pq.pop();

            if(freq>0) {

                pq.push(freq);

            }

        }

        int ans=0;

        while(!pq.empty()) {

            ans+=pow(pq.top(),2);

            pq.pop();

        }

        return ans;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends