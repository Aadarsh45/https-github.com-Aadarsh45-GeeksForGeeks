//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
  
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head == NULL || head->next == NULL){
            return true;
        }
      Node *temp1 = head;
      Node *temp2 = head;
      stack<int>stack;
      while(temp2 != NULL){
          stack.push(temp2->data);
          temp2=temp2->next;
      }
      
      while(!stack.empty()){
          if(temp1->data != stack.top()){
              return false;
          }
          temp1 = temp1->next;
          stack.pop();
      }
      
      
      return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends