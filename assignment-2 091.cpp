//Submitted by Mohammad Muazam 
// Reg. No. RA1911003010091

#include<iostream>
#include<time.h>

using namespace std;
#define size 10
struct Queue {
  int front = 0, rear = 0;
  long int phone[size];
  string fname[size], lname[size], tim[size];
};
void Insert(struct Queue * q) {
  cout << "Enter phone number : ";
  long int x = 0;
  cin >> x;
  cout << "Enter first Name : ";
  string y, _date, z;
  cin >> y;
  cout << "Enter last Name : ";
  cin >> z;
  time_t now = time(0);
  _date = ctime( & now);
  q -> rear = (q -> rear + 1) % size;
  q -> phone[q -> rear] = x;
  q -> fname[q -> rear] = y;
  q -> lname[q -> rear] = z;
  q -> tim[q -> rear] = _date;
}
void dequeue(struct Queue * q) {
  if (q -> front != q -> rear)
    q -> front = (q -> front + 1) % size;
}
void display(struct Queue q) {
  int i = q.rear + 1;
  cout << "-----Your Call Log:-----\n"<<endl;
  do {
    i = (i - 1) % size;
    if (i == -1)
      i = size - 1;
    cout << q.fname[i] << " " << q.lname[i] << "\t" << q.phone[i] << "\t" << q.tim[i] << endl;
  } while (i != (q.front + 1) % size);
  cout << endl;
}
int main() {
  struct Queue que;
  int choice, c = 0;
  do {
    cout << endl << "-----CALL LOG MENU-----" << endl <<"Press \n" 
    << "(1) To make a call" << endl
    << "(2) To Check your call log" << endl
    << "(0) To Exit" << endl;

    cout << "Enter your choice : " << endl;
    cin >> choice;
    switch (choice) {
    case 1:
      Insert(&que);
      c++;
      if (c >= 10)
        dequeue(&que);
      break;
    case 2:
      display(que);
      break;
    }
  } while (choice != 0);
  display(que);
}