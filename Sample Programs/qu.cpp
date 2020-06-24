#include<iostream>
#include<string.h>
#define MAX 100
using namespace std;
typedef struct stack
{
	char data[MAX];
	int top;
}stack;

void init(stack *s)
{
	int i;
	for(i=0;i<MAX;i++)
	s->data[i]='\0';

	s->top=-1;
}
void print(stack s)
{

int i;
cout<<"\nstack element are:";
for(i=0;i<MAX;i++)
cout<<s.data[i];
cout<<"top="<<s.top;
}

int empty(stack s)
{
return s.top==-1?1:0;
}

int full(stack s)
{
return s.top==MAX-1?1:0;
}

void push(stack *s,char data[MAX])
{
int i;
for(i=0;data[i]!='\0';i++)
{
s->top+=1;
s->data[s->top]=data[i];
}
}

void pop(stack *s)
{
char data[MAX],data1[MAX];
int i=0;
while(!empty(*s))
{
data[i]=s->data[s->top];
s->top-=1;
i++;
}
data[i]='\0';
cout<<"\nOriginal String is="<<s->data;
cout<<"\nReversed string is::";
cout<<data;
if(strcmp(data,s->data))
cout<<"\nString is not palindrome";
else
cout<<"\nString is plindrome";
}


int main()
{
stack s;
char data[MAX]={'P','o','o','r',' ','D','a','n',' ','i','s',' ','a',' ','d','r','o','o','p','\0'};
char data1[MAX];
init(&s);
int ch,i,j=0;
for(i=0;data[i]!='\0';i++)
{
if(data[i]!=' ')
{
if(data[i]>=65&&data[i]<=90)
data1[j]=data[i]+32;
else
data1[j]=data[i];
j++;
}
}
data1[j]='\0';
while (ch!=3)
{
cout<<"\nStack \n";
cout<<"\n1.Push the string,print reverse string & check palindrome or not(pop)";
cout<<"\n2.Remove blank space,convert uppercase into lowercase,push the string & check palindrome or not (pop)";
cout<<"3.Exit";
cout<<"\nEnter your choice ::";
cin>>ch;
switch(ch)
{
case 1:
if(full(s))
cout<<"\nstack is full";
else
{
push(&s,data);
}
if(empty(s))
cout<<"\nStack is empty::";
else
pop(&s);
break;
case 2:
init(&s);
if(full(s))
cout<<"\nStack is full";
else
{
push(&s,data1);
}
pop(&s);
break;
}
}
return 0;
}







