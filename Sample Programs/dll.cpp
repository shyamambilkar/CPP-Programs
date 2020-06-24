#include<iostream.h>
#include<stdlib.h>
using namespace std;
struct dnode
{
 int data;
 struct dnode *next,*prev;
}dnode;
void main()
{
 dnode *head;
 int i,x,temp;
 head=NULL;
 cout<<"Enter the elements you want to insert:";
 cin>>x;
 for(i=0;i<n;i++)
 {
  if(head->next!=NULL)
  {
   temp=head->data;
   head->next=NULL;
  }
