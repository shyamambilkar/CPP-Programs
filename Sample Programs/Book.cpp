#include<iostream>
using namespace std;

class Book
{
   public:
   int b_id;
   char b_name[50];
   char b_author[30];
   char b_publication[20];

   void getdata()
   {
     cout<<"Enter Book details: ";
     cout<<"\nBook id is: ";
     cin>>b_id;
     cout<<"Book name is: ";
     cin>>b_name;
     cout<<"Book author is: ";
     cin>>b_author;
     cout<<"Book publication is: ";
     cin>>b_publication;     

    } 
   
   void display()
   {
     cout<<"\n Book details: ";
     cout<<"\n Book id: "<<b_id;
     cout<<"\n Book name: "<<b_name;
     cout<<"\n Book author: "<<b_author;
     cout<<"\n Book publication: "<<b_publication;
   } 
};

int main()
{
   Book B1,B2;
   int ch;
 //  int i,n=2;
   cout<<"Enter choice : ";
   cin>>ch;
  {
   switch (ch)
   {
     case 1:
        B1.getdata();
        B1.display();
        break;
     case 2:
        B2.getdata();
        B2.display();
        break;
 
   }   
  }
  /* for(i=1;i<=n;i++)
   {
     B.getdata();
   }
   for(i=1;i<=n;i++)
   {
     B.display();
   } */
   return 0;
}
