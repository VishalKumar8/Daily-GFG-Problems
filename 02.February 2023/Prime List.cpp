//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    bool isPrime(int n){
    	if(n==1) return false;
    	if(n==2 || n==3)
    		return true;
    	for(int i=2;i<=sqrt(n);i++){
    		if(n%i==0){
    			return false;
    		}
    	}
    	return true;
    }
    Node *primeList(Node *head){
        Node *temp=head;
        while(temp!=NULL){
            int num=temp->val,num1,num2;
            num1=num2=num;
            if(num==1){
                temp->val=2;
                temp=temp->next;
                continue;
            }
            while(!isPrime(num1)){
                num1--;
            }
            while(!isPrime(num2)){
                num2++;
            }
            if(num-num1>num2-num){
                temp->val=num2;
            }
            else{
                temp->val=num1;
            }
            temp=temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
