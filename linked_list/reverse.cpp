/*
reverse a linked list
*/
#include<bits/stdc++.h>

using namespace std;
 
//recursive
void reverse(Node *temp,Node *prev,Node **head){
    if(temp==0){
        return;
    }
    if(temp->next==0){
        *head=temp;
        temp->next=prev;
        return;
    }
    
    reverse(temp->next,temp,head);
    temp->next=prev;
    return;
    
}

//iterative
struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    Node *temp,*prev,*curr;
    prev=0;
    curr=head;
    while(curr){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
 

int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
  //write your code here

  return 0;
}