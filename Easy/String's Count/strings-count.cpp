//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


long long int countStr(long long int n){
    //complete the function here
    long long int c1=1;// all 1
    long long int c2=n;//one b
    long long int c3=n;//one c;
    long long int c4=(n*(n-1));//one b,one c
    long long int c5=(n*(n-1))/2;//two c
    long long int c6=(n*(n-1)*(n-2))/2;//one b, one c


    return c1+c2+c3+c4+c5+c6;
}