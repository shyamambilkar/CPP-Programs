 #include<iostream>
#include<string.h>
#define MAX 20
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

int empty(stack s)
{
	return s.top==-1?1:0;
}

int full(stack s)
{
	return s.top==MAX-1?1:0;
}

void push(stack *s,char data)
{
	s->top+=1;
	s->data[s->top]=data;
}
char pop(stack *s)
{
	char data;
	data=s->data[s->top];
	s->data[s->top]='\0';
	s->top-=1;
	return data;
}
int main()
{
	stack s;
	int i,found=0;
	char data[MAX],ch;
	init(&s);
	cout<<"\nEnter the expression:";
	cin>>data;
	for(i=0;i<strlen(data);i++)
	{

	if((data[i]=='(')||(data[i]=='[')||(data[i]=='{'))
			push(&s,data[i]);
        else
	{
	switch(data[i])
	{
	case ')':
	if(empty(s))
	{
	cout<<"\nInvalid expression";
	}
        ch=pop(&s);
	if((ch=='[')||(ch=='}'))
	{
	cout<<"\nInvalid Expression";
	found=1;
	}
	break;
	case ']':
	if(empty(s))
	{
	cout<<"\nInvalid Expression";
	found=1;
	}
	ch=pop(&s);
	if((ch=='(')||(ch=='{'))
	{
	cout<<"\nInva;id Expression";
	found=1;
	}
	break;
	case '}':
	if(empty(s))
	{
	cout<<"\nInvalid Expression";
	found=1;
	}
	ch=pop(&s);
	if((ch=='{')||(ch=='('))
	{
	cout<<"\nInvalid Expression";
	found=1;
	}
	break;
	}
	}
	}
	if(found==0)
	{
	if(empty(s))
	cout<<"Valid Expression";
	else
	cout<<"\nInvalid Expression";
	}
return 0;
}

