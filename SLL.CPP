#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//singly linked structure



struct node{
 int data;
 struct node *next;//self refrential structure
}*start=NULL;


void star(void);
void createList(int);
void display(void);
void addbeg(int);
void addlast(int);
void addatspec(int,int);
int count(void);
void delbeg(void);
void dellast(void);
void delatspec(int);
void main(){
  clrscr();
  int ch,num;
  do{
   printf("\t\t");
   star();
   printf("\n\t\t SINGLY LINKED LIST\n\t\t");
   star();
   printf("\n\t 1. Create Linked List");
   printf("\n\t 2. Display");
   printf("\n\t 3. Exit");
   printf("\n\t 4. Add Begining");
   printf("\n\t 5. Add Last");
   printf("\n\t 6. Add At Specific Position");
   printf("\n\t 7. Count Number Of Nodes");
   printf("\n\t 8. Delete Beginning");
   printf("\n\t 9. Delete Last");
   printf("\n\t10. Delete At Specific Node");
   printf("\n\n  Enter your choice: ");
   scanf("%d",&ch);
   switch(ch){
     case 1:
	     clrscr();
	     printf("\t\t\t");
	     star();
	     printf("\n\t\t\t CREATE LINKED LIST\n\t\t\t");
	     star();
	     printf("\n\n\tEnter any number: ");
	     scanf("%d",&num);
	     createList(num);
	     printf("\n\n\tPress any key to continue");
	     getch();
	     clrscr();
	     break;
     case 2:
	     clrscr();
	     printf("\t\t\t");
	     star();
	     printf("\n\t\t\t DATA IN LINKED LIST\n\t\t\t");
	     star();
	     display();
	     printf("\n\n\tPress any key to continue");
	     getch();
	     clrscr();
	     break;
     case 3:
	     exit(0);
     case 4:
	     clrscr();
	     printf("\t\t\t");
	     star();
	     printf("\n\t\t\t  ADD AT BEGINNING\n\t\t\t");
	     star();
	     printf("\n\n\tEnter any number: ");
	     scanf("%d",&num);
	     addbeg(num);
	     printf("\n\n\tPress any key to continue");
	     getch();
	     clrscr();
	     break;
     case 5:
	     clrscr();
	     printf("\t\t\t");
	     star();
	     printf("\n\t\t\t      ADD AT LAST\n\t\t\t");
	     star();
	     printf("\n\n\tEnter any number: ");
	     scanf("%d",&num);
	     addlast(num);
	     printf("\n\n\tPress any key to continue");
	     getch();
	     clrscr();
	     break;
     case 6:
	     clrscr();
	     printf("\t\t\t");
	     star();
	     printf("\n\t\t\tADD AT SPEC POSITION\n\t\t\t");
	     star();
	     printf("\n\n\tEnter any number: ");
	     scanf("%d",&num);
	     int n;
	     printf("\n\n\tEnter the index position: ");
	     scanf("%d",&n);
	     addatspec(n,num);
	     printf("\n\n\tPress any key to continue");
	     getch();
	     clrscr();
	     break;
     case 7:
	     clrscr();
	     printf("\t\t\t");
	     star();
	     printf("\n\t\t\tCOUNT NO(S) OF NODES\n\t\t\t");
	     star();
	     printf("\n\n\tTotal No(s) of node(s): %d",count());
	     printf("\n\n\tPress any key to continue");
	     getch();
	     clrscr();
	     break;

     case 8: clrscr();
	     printf("\t\t\t");
	     star();
	     printf("\n\t\t\t DELETE AT BEGINNING\n\t\t\t");
	     star();
	     delbeg();
	     printf("\n\n\tPress any key to continue");
	     getch();
	     clrscr();
	     break;
     case 9: clrscr();
	     printf("\t\t\t");
	     star();
	     printf("\n\t\t\t   DELETE AT LAST\n\t\t\t");
	     star();
	     dellast();
	     printf("\n\n\tPress any key to continue");
	     getch();
	     clrscr();
	     break;
     case 10:clrscr();
	     printf("\t\t\t");
	     star();
	     printf("\n\t\t\tDEL AT SPEC POSITION\n\t\t\t");
	     star();
	     printf("\n\n\tEnter the index position: ");
	     scanf("%d",&n);
	     delatspec(n);
	     printf("\n\n\tPress any key to continue");
	     getch();
	     clrscr();
	     break;

     default:
	     clrscr();
	     printf("\t\t\t");
	     star();
	     printf("\n\t\t\t   INVALID CHOICE\n\t\t\t");
	     star();
	     printf("\n\n\t\tExiting!!!");
	     printf("\n\n\t\tPress any key to exit");
	     getch();
	     exit(0);
   }
  }while(1);
}

//createlist
void createList(int num){
 struct node *q,*temp;
 if(start==NULL){
   start=(struct node*)malloc(sizeof(struct node));
   start->data=num;
   start->next=NULL;
 }
 else{
   q=start;
   while(q->next!=NULL)
     q=q->next;
   temp=(struct node *)malloc(sizeof(struct node));
   temp->data=num;
   temp->next=NULL;
   q->next=temp;
 }
}
//display
void display(){
  struct node *q;
  int i=1;
  for(q=start;q!=NULL;q=q->next,i++)
    printf("\n\n\t%d--->%d",i,q->data);

}

//add beginning
void addbeg(int num){
 struct node *temp,*q;
 q=start;
 temp=(struct node *)malloc(sizeof(struct node));
 temp->data=num;
 temp->next=q;
 start=temp;



}
//insert at last
void addlast(int num){
 struct node *temp;
 temp=(struct node *)malloc(sizeof(struct node));
 temp->data=num;
 temp->next=NULL;
 if(start==NULL)
   start=temp;
 else{
   struct node *cur=start;
   while(cur->next!=NULL)
     cur=cur->next;
   cur->next=temp;
 }
}
//print * 20 times
void star(){
  for(int i=1;i<=20;i++)
    printf("*");
}

//insert at specific position
void addatspec(int n,int num){
  struct node *temp,*cur;
  temp=(struct node *)malloc(sizeof(struct node));
  cur=start;
  temp->data=num;
  temp->next=NULL;
  if(start==NULL||n==1){
    temp->next=start;
    start=temp;
  }
  else{
    int i=1;
    cur=start;
    while(i++<n-1){
      cur=cur->next;
    }
    temp->next=cur->next;
    cur->next=temp;
 }

}
//Count number of nodes

int count(){
  int n=1;
  struct node *cur=start;
  if(cur==NULL)
    return 0;
  else{
    while(cur->next!=NULL){
      n++;
      cur=cur->next;
    }
    return n;
  }
}
// Delete at beginning
void delbeg(){
  struct node *temp;
  if(start==NULL)
    printf("\n\n\tNo Node Available");
  else{
    temp->next=start;
    start=start->next;
    printf("\n\n\tFirst node deleted");
  }
  free(temp);
}

//Deletee at last
void dellast(){
  struct node *temp,*cur;
  temp=cur=start;
  if(start==NULL)
    printf("\n\n\tNo Node Available");
  else if(start->next==NULL){
    start=NULL;
    printf("\n\n\tLast node deleted");
  }
  else{
    while(cur->next!=NULL){
      temp=cur;
      cur=cur->next;
    }
    temp->next=NULL;
    free(cur);
    printf("\n\n\tLast node deleted");
  }
}
//delete the specific node
void delatspec(int n){
  struct node *temp,*cur;
  cur=start;
  if(start==NULL){
    printf("\n\n\tNo Node Available");
    return;
  }
  else if(start->next==NULL)
	   start=NULL;
       else{
	 int i=1;
	 while(i++<n){
	 temp=cur;
	 cur=cur->next;
       }
       temp->next=cur->next;
       free(cur);
      }
  printf("\n\n\tNode %d deleted",n);
}