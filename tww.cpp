#include<iostream>
using namespace std;

class Queue
{ private:
int size;
int f;
int r;
long int *phone;
string *name;
  public:
    Queue(int size);
    void Insert();
    void Delete();
    void display();
};
 
Queue::Queue(int size) {
    this->size = size;
    f = -1;
    r = -1;
    phone = new long int[size];
    name = new string[size];
}

 
void Queue::Insert()
{ if((r + 1) % size == f)
   f = (f+1)%size;
  
if(f==-1 )
   { f=0;
     r=0;
    }
else
   r = (r+1)%size;
   cout<<"Enter Phone Number : ";
   unsigned long int x;
   cin>>x;
   phone[r]=x;
   cout<<endl<<"Enter Name : ";
   string y;
   cin>>y;
   name[r]=y;

}
 
 
void Queue::display()
{cout<<endl;
 int i =r+1;
if(f == -1)
  cout<<"No call dialed till now"<<endl;
  else{
 do
  {   i = (i-1)%size;
      if(i==-1)
      i=size-1;
     
      cout<<name[i]<<"    "<<phone[i]<<endl;
  }
  while(i!=(f)%size);
  }
cout<<endl;
}
 
int main()
{ Queue q(10);
int ch;
 
  do {   cout<<"1) Insert Call"<<endl<<"2) Display call"<<endl<<"Press any other key to EXIT"<<endl;
           cout<<"Enter your choice : "<<endl;
           cin>>ch;
     switch (ch) {
        case 1: q.Insert();
        break;
        case 2: q.display();
        break;
     }
  } while(ch==1 || ch==2);

  cout<<"Code Exited as choice was other key";
}
