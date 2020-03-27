#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *prev,*next;
};
Node *head;

Node* createNode(int x){
	Node *temp=new Node;
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
void insertAtBeg(int item){
	Node *temp=createNode(item);
	if(head==NULL){
		head=temp;
		return;
	}
	head->prev=temp;
	temp->next=head;
	head=temp;
}

void insertAtEnd(int item){
	Node *temp=createNode(item);
	if(head==NULL){
		head=temp;
		return;
	}
	Node *cur=head;
	while(cur->next!=NULL){
		cur=cur->next;
	}
	cur->next=temp;
	temp->prev=cur;
}
void print(){
	Node *temp=head;
	cout<<"List is:";
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void reversePrint(){
	Node *temp=head;
	if(temp==NULL) return;
	
	while(temp->next!=NULL)
		temp=temp->next;
	
	cout<<"Reverse:";
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp=temp->prev;
	}
	cout<<endl;
}
int main(){
	head=NULL;
	insertAtBeg(1);
	print();
	reversePrint();
	insertAtEnd(2);
	print();
	reversePrint();
	insertAtBeg(3);
	print();
	reversePrint();
	return 0;
}
