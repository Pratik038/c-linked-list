#include<constreaem.h>
#include<stdlib.h>

struct node{
	int data;
	node *next;
}*start=NULL;

void insertAtBeg(){
	node *temp=new node;
	cout<<"Enter a number:";
	cin>>temp->data;
	temp->next=start;
	start=temp;
}

void insertAtEnd(){
	node *temp;
	temp=new node;
	cout<<"Enter a number:";
	cin>>temp->data;
	temp->next=NULL;
	if(start==NULL)
		start=NULL;
	else{
		node *cur=start;
		while(cur->next!=NULL)
			cur=cur->next;
		cur->next=temp;
	}
}

void insertAtPos(int pos){
	node *temp=new node;
	cout<<"Enter a number:";
	cin>>temp->data;
	temp->next=NULL;
	if(start==NULL || pos==1){
		temp->next=start;
		start=temp;
	}
	else{
		node *cur=start;
		pos=pos-2;
		while(pos--){
			cur=cur->next;
		}
		temp->next=cur->next;
		cur->next=temp;
	}
}

void deleteFirstNode(){
	node *temp;
	if(start==NULL)
		cout<<"List is empty";
	else{
		temp=start;
		start=start->next;
		free(temp);
		cout<<"First node is deleted";
	}
}

void deleteLastNode(){
	node *temp;
	if(start==NULL)
		cout<<"List is empty";
	else{
		node *cur=start;
		while(cur->next!=NULL){
			temp=cur;
			cur=cur->next;
		}
		temp->next=NULL;
		free(cur);
		cout<<"Last node is deleted";
	}
}

void deleteAtPos(int pos){
	node *temp;
	if(start==NULL)
		cout<<"List is empty";
	else{
		node *cur=start;
		pos=pos-1;
		while(pos--){
			temp=cur;
			cur=cur->next;
		}
		temp->next=cur->next;
		free(cur);
		cout<<"Node deleted";
	}
}

void display(){
	node *n=start;
	if(n==NULL)
		cout<<"List is empty";
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->next;
	}
}

int menu(){
	int ch;
	cout<<"\n\t\t\tLINKED LIST\n";
	cout<<"\n1.Insert node at beginning";
	cout<<"\n2.Insert node at Position";
	cout<<"\n3.Insert node at last";
	cout<<"\n4.Delete First node";
	cout<<"\n5.Delete node at position";
	cout<<"\n6.Delete Last node";
	cout<<"\n7.Display";
	cout<<"\n8.Exit";
	cout<<"\n\nEnter your choice:";
	cin>>ch;
	return ch;
}

void main(){
	while(1){
		clrscr();
		switch(menu()){
			case 1:insertAtBeg();
			       break;
			case 2:int pos;
				cout<<"Enter postion:";
				cin>>pos;
				insertAtPos(pos);
			       break;
			case 3:insertAtEnd();
			       break;
			case 4:deleteFirstNode();
				break;
			case 5:	cout<<"Enter postion:";
				cin>>pos;
				deleteAtPos(pos);
				break;
			case 6:deleteLastNode();
				break;
			case 7:display();
				break;
			case 8:exit(0);
			default: cout<<"INVALID CHOICE!";
		}
		getch();
	}
}