//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
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

class Solution {

  public:
    long long solve(int i, int prevTaken, vector<int>& arr, vector<vector<long long>>& dp) {

    if (i >= arr.size()) return 0;
    
    if (dp[i][prevTaken] != -1) return dp[i][prevTaken];
    
    if (prevTaken == 0) {
        return dp[i][prevTaken] = solve(i+1, 1, arr, dp) + arr[i];
    } else {
        return dp[i][prevTaken] = max(solve(i+1, 1, arr, dp) + arr[i], solve(i+1, 0, arr, dp));
    }

}


long long findMaxSubsetSum(int N, vector<int>& A) {

    vector<vector<long long>> dp(N, vector<long long>(2, -1));
    
    	return max(solve(0, 0, A, dp), solve(0, 1, A, dp));

}
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
