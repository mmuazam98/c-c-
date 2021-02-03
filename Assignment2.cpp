#include<iostream>
#include<time.h>

using namespace std;
struct Node {
  long int data;
  string name;
  string t;
  struct Node * next;
};
struct Node * front = NULL;
struct Node * rear = NULL;

void enqueue(string y, string w, long int x);
void dequeue();
void display(Node * temp);
//main function
int main() {
  int n, c = 0;
  string x, w;
  long int y;
  time_t now = time(0);
  do {
    cout << "Enter 1 for input" << endl << "Enter 2 for output" << endl << "Enter 0 to exit" << endl;
    cin >> n;
    switch (n) {
    case 1:
      cout << "Enter Name: ";
      cin >> x;
      cout << "Enter Phone Number: ";
      cin >> y;
      w = ctime( & now);
      enqueue(x, w, y);
      c++;
      break;
    case 2:
      if (c >= 11)
        dequeue();
      display(front);
      break;
    }
  } while (n != 0);
}

void enqueue(string y, string w, long int x) {
  struct Node * temp;
  temp = new Node;
  if (temp == NULL)
    cout << "Queue is full.\n";
  else {
    temp -> data = x;
    temp -> name = y;
    temp -> t = w;
    temp -> next = NULL;
    if (front == NULL)
      front = rear = temp;
    else {
      rear -> next = temp;
      rear = temp;
    }
  }
}
void dequeue() {
  int x = -1;
  struct Node * temp;
  if (front == NULL)
    cout << "No call log.\n";
  else {
    temp = front;
    front = front -> next;
    free(temp);
  }
}
void display(Node * temp) {
  if (temp == NULL)
    return;
  display(temp -> next);
  cout << temp -> name << " " << temp -> data << " " << temp -> t << endl;
  cout << endl;
}