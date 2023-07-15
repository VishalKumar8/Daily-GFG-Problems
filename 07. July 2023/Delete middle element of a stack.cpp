//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    void deleteMid(stack<int>& s, int sizeOfStack) {
        stack<int> newStack;
        int cnt = sizeOfStack / 2; // number of elements present on the top of mid element
        
        while (cnt--) {
            newStack.push(s.top());
            s.pop();
        }
        
        s.pop(); // Mid Element
        
        while (!newStack.empty()) {
            s.push(newStack.top());
            newStack.pop();
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends
