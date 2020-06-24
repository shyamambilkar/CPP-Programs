/*Polynomial- Representation, Addition, Multiplication*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct poly
{
int coeff;
int exp;
struct poly *next;
}*head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL,*temp,*ptr;

void create();
void makenode(int,int);
struct poly *insertend(struct poly *);
void display(struct poly *);
struct poly *addtwopoly(struct poly *,struct poly *,struct poly *);
struct poly *subtwopoly(struct poly *,struct poly *,struct poly *);
struct poly *multwopoly(struct poly *,struct poly *,struct poly *);
struct poly *dispose(struct poly *);
int search(struct poly *,int);

void main()
{
int ch,coefficient,exponent;
int listno;
while(1)
{
clrscr();
printf(“ntMenu”);
printf(“nt1. Create First Polynomial.”);
printf(“nt2. Display First Polynomial.”);
printf(“nt3. Create Second Polynomial.”);
printf(“nt4. Display Second Polynomial.”);
printf(“nt5. Add Two Polynomials.”);
printf(“nt6. Display Result of Addition.”);
printf(“nt7. Subtract Two Polynomials.”);
printf(“nt8. Display Result of Subtraction.”);
printf(“nt9. Multiply Two Polynomials.”);
printf(“nt10. Display Result of Product.”);
printf(“nt11. Dispose List.”);
printf(“nt12. Exit”);
printf(“nntEnter your choice?”);
scanf(“%d”,&ch);
switch(ch)
{
case 1:
printf(“nGenerating first polynomial:”);
printf(“nEnter coefficient?”);
scanf(“%d”,&coefficient);
printf(“nEnter exponent?”);
scanf(“%d”,&exponent);
makenode(coefficient,exponent);
head1 = insertend(head1);
break;
case 2:
display(head1);
break;
case 3:
printf(“nGenerating second polynomial:”);
printf(“nEnter coefficient?”);
scanf(“%d”,&coefficient);
printf(“nEnter exponent?”);
scanf(“%d”,&exponent);
makenode(coefficient,exponent);
head2 = insertend(head2);
break;
case 4:
display(head2);
break;
case 5:
printf(“nDisposing result list.”);
head3=dispose(head3);
head3=addtwopoly(head1,head2,head3);
printf(“Addition successfully done!”);
break;
case 6:
display(head3);
break;
case 7:
head3=dispose(head3);
head3=subtwopoly(head1,head2,head3);
printf(“Subtraction successfully done!”);
getch();
break;
case 8:
display(head3);
break;
case 9:
head3=dispose(head3);
head4=dispose(head4);
head4=multwopoly(head1,head2,head3);
break;
case 10:
display(head4);
break;
case 11:
printf(“Enter list number to dispose(1 to 4)?”);
scanf(“%d”,&listno);
if(listno==1)
head1=dispose(head1);
else if(listno==2)
head2=dispose(head2);
else if(listno==3)
head3=dispose(head3);
else if(listno==4)
head4=dispose(head4);
else
printf(“Invalid number specified.”);
break;
case 12:
exit(0);
default:
printf(“Invalid Choice!”);
break;
}
}
}

void create()
{
ptr=(struct poly *)malloc(sizeof(struct poly));
if(ptr==NULL)
{
printf(“Memory Allocation Error!”);
exit(1);
}
}

void makenode(int c,int e)
{
create();
ptr->coeff = c;
ptr->exp = e;
ptr->next = NULL;
}

struct poly *insertend(struct poly *head)
{
if(head==NULL)
head = ptr;
else
{
temp=head;
while(temp->next != NULL)
temp = temp->next;
temp->next = ptr;
}
return head;
}

void display(struct poly *head)
{
if(head==NULL)
printf(“List is empty!”);
else
{
temp=head;
while(temp!=NULL)
{
printf(“(%d,%d)->”,temp->coeff,temp->exp);
temp=temp->next;
}
printf(“bb “);
}
getch();
}

struct poly *addtwopoly(struct poly *h1,struct poly *h2,struct poly *h3)
{
/*
(5,3)->(6,1) + (7,3)->(9,2) = (12,3)->(6,1)->(9,2)
*/
struct poly *temp1,*temp2,*temp3;
temp1=h1;
temp2=h2;
while(temp1!=NULL || temp2!=NULL)
{
if(temp1->exp==temp2->exp)
{
makenode(temp1->coeff+temp2->coeff,temp1->exp);
h3=insertend(h3);
}
else
{
makenode(temp1->coeff,temp1->exp);
h3=insertend(h3);
makenode(temp2->coeff,temp2->exp);
h3=insertend(h3);
}
temp1=temp1->next;
temp2=temp2->next;
}
if(temp1==NULL && temp2!=NULL)
{
while(temp2!=NULL)
{
makenode(temp2->coeff,temp2->exp);
h3=insertend(h3);
temp2=temp2->next;
}
}
if(temp2==NULL && temp1!=NULL)
{
while(temp1!=NULL)
{
makenode(temp2->coeff,temp2->exp);
h3=insertend(h3);
temp1=temp1->next;
}
}
return h3;
}

struct poly *subtwopoly(struct poly *h1,struct poly *h2,struct poly *h3)
{
/*
(5,3)->(6,1) – (7,3)->(9,2) = (-2,3)+(6,1)-(9,2)
*/
struct poly *temp1,*temp2,*temp3;
temp1=h1;
temp2=h2;
while(temp1!=NULL || temp2!=NULL)
{
if(temp1->exp==temp2->exp)
{
makenode(temp1->coeff-temp2->coeff,temp1->exp);
h3=insertend(h3);
}
else
{
makenode(temp1->coeff,temp1->exp);
h3=insertend(h3);
makenode(-temp2->coeff,temp2->exp);
h3=insertend(h3);
}
temp1=temp1->next;
temp2=temp2->next;
}
if(temp1==NULL && temp2!=NULL)
{
while(temp2!=NULL)
{
makenode(temp2->coeff,temp2->exp);
h3=insertend(h3);
temp2=temp2->next;
}
}
if(temp2==NULL && temp1!=NULL)
{
while(temp1!=NULL)
{
makenode(-temp2->coeff,temp2->exp);
h3=insertend(h3);
temp1=temp1->next;
}
}
return h3;
}

struct poly *multwopoly(struct poly *h1,struct poly *h2,struct poly *h3)
{
/*
h1=(5,3)->(6,1) * h2=(7,3)->(9,2)
(5,3)->(7,3),(9,2) = (35,6),(45,5)
(6,1)->(7,3),(9,2) = (42,4),(54,3)
h3->(35,6)->(45,5)->(42,4)->(54,3)
(35,6)+(45,5)+(42,4)+(54,3)=Result
*/
int res=0;
struct poly *temp1,*temp2,*temp3;
printf(“nDisplaying First Polynomial:ntt”);
display(h1);
printf(“nDisplaying Second Polynomial:ntt”);
display(h2);

temp1=h1;
while(temp1!=NULL)
{
temp2=h2;
while(temp2!=NULL)
{
makenode(temp1->coeff*temp2->coeff,temp1->exp+temp2->exp);
h3=insertend(h3);
temp2=temp2->next;
}
temp1=temp1->next;
}

printf(“nDisplaying Initial Result of Product:ntt”);
display(h3);
getch();

temp1=h3;
while(temp1!=NULL)
{temp2=temp1->next;
res=0;
while(temp2!=NULL)
{
if(temp1->exp==temp2->exp)
res += temp2->coeff;
temp2=temp2->next;
}
if(search(head4,temp1->exp)==1)
{
makenode(res+temp1->coeff,temp1->exp);
head4=insertend(head4);
}
temp1=temp1->next;
}
return head4;
}

int search(struct poly *h,int val)
{
struct poly *tmp;
tmp=h;
while(tmp!=NULL)
{if(tmp->exp==val)
return 0;
tmp=tmp->next;
}
return 1;
}

struct poly *dispose(struct poly *list)
{
if(list==NULL)
{
printf(“List is already empty.”);
return list;
}
else
{
temp=list;
while(list!=NULL)
{
free(temp);
list=list->next;
temp=list;
}
return list;
}
}