#include<iostream>

using namespace std;

struct node{
	int info;
	node *link;
};

node *start=NULL;

node* createNode(){
	node *n;
	n=(node*)malloc(sizeof(node*));
	return n;
}

void insertNode(){
	node *temp,*t;
	temp=createNode();
	temp->link=NULL;
	cout<<"Enter a number";
	cin>>temp->info;
	if(start==NULL)
		start=temp;
	else{
		t=start;
		while(t!=NULL)
			t=t->link;
		t->link=temp;
	}
}

void deleteNode(){
	node *r;
	if(start==NULL)
		cout<<"List is empty";
	else{
		r=start;
		start=start->link;
		free(r);
	}
}

void viewList(){
	node *t;
	if(start==NULL)
		cout<<"List is empty";
	else{
		t=start;
		while(t!=NULL){
			cout<<t->info<<" ";
			t=t->link;
		}
	}
}

int menu(){
	int ch;
	cout<<"\n1.Add a new node.";
	cout<<"\n2.Delete a node.";
	cout<<"\n3.Traversal.";
	cout<<"\n4.exit";
	cout<<"\n\nEnter your choice: ";
	cin>>ch;
	return ch;
}
int main(){
	while(1){
		switch(menu()){
			case 1:insertNode();
					break;
			case 2:deleteNode();
					break;
			case 3:viewList();
					break;
			case 4:exit(0);
			default : cout<<"\nINVALID CHOICE! PLEASE ENTER CORRECT CHOICE."
		}
	}
	return 0;
}