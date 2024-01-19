//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kTop(vector<int> &arr, int n, int k)
    {
        map<int, set<int>> mp;
        vector<vector<int>> ans;
        set<int> ff;
        map<int, int> freq;
        for (int i = 0; i < n; i++)
        {

            freq[arr[i]]++;
            ff.insert(freq[arr[i]]);
            mp[freq[arr[i]]].insert(arr[i]);
            // cout << i << " " << freq[arr[i]] << " " << ff.size() << " " << mp[freq[arr[i]]].size() << endl;
            if (freq[arr[i]] - 1 > 0)
            {
                int fre = freq[arr[i]] - 1;
                set<int> &tmp = mp[fre];
                tmp.erase(arr[i]);
                if (!tmp.size())
                {
                    ff.erase(fre);
                    mp.erase(fre);
                }
            }
            auto it = ff.rbegin();
            vector<int>tmp;
            int j=0;
            while (j < k && it != ff.rend())
            {
                int currfreq = *it;
                set<int> &st = mp[currfreq];

                auto set_it = st.begin(); // Use an iterator to respect order
                while (j < k && set_it != st.end())
                {
                    tmp.push_back(*set_it);
                    j++;
                    set_it++;
                }

                it++;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends