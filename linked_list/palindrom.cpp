#include<bits/stdc++.h>

using namespace std;

class node{
public:
	int data;
	node *next;
	node(int data){
		this->data=data;
		this->next=0;
	}
};

node* create_list(vector<int> v){
	node *head=0;
	if(v.size()==0)
		return head;
	node *t=new node(v[0]);
	head=t;
	for(int i=1;i<v.size();i++){
		node *temp=new node(v[i]);
		t->next=temp;
		t=t->next;
	}
	return head;
}

node* find_middle(node *head){
	if(head==0||head->next==0)
		return head;
	node *slow,*fast;
	slow=head;
	fast=head;
	int i=0;
	while(fast->next!=0){
		if(i==0){
			fast=fast->next;
			i=1;
		}
		else{
			slow=slow->next;
			fast=fast->next;
			i=0;
		}
	}
	return slow;
}

bool check(node *head1,node *head2){
	while(head1!=0&&head2!=0){
		if(head1->data!=head2->data)
		{
				return false;
		}
		head1=head1->next;
		head2=head2->next;
	}
	return true;
}

void traverse(node *head1){
	if(head1==0)
		return;
	cout<<head1->data<<" ";
	traverse(head1->next);
	return;
}

node* reverse(node *head){
	node *temp,*nxt;
	temp=0,nxt=0;
	while(head){
		nxt=head->next;
		head->next=temp;
		temp=head;
		head=nxt;
	}
	return temp;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v={4,1,2,1,4};
	node *head=create_list(v);
	//write your code here
	node *mid=find_middle(head);
	traverse(head);
	cout<<endl;
	mid->next=reverse(mid->next);
	node *head1,*head2;
	head1=head;
	head2=mid->next;

	if(check(head1,head2)){
		cout<<"palindrom"<<endl;
	}
	else{
		cout<<"not palindrom"<<endl;
	}
	mid->next=reverse(mid->next);
	traverse(head);
	return 0;
}