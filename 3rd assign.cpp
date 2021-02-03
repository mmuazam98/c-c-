#include <iostream>
using namespace std;

//Queue function  - YASH
struct queue
{
  string fname;
  string lname;
  int age;
  int year;
  struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;

void enq(string w, string x, int y, int z)
{
  struct queue *temp = new queue;

  if (temp == NULL)
    cout << "Queue is FUll\n";

  else
  {
    temp->fname = w;
    temp->lname = x;
    temp->age = y;
    temp->year = z;
    temp->next = NULL;

    if (front == NULL)
      front = rear = temp;

    else
    {
      rear->next = temp;
      rear = temp;
    }
  }
}

struct queue *deq()
{
  struct queue *temp;
  if (front == NULL)
  {
    cout << "Queue is Empty\n";
  }
  else
  {
    temp = front;
    front = front->next;
  }
  return temp;
}

void display_q()
{
  struct queue *temp = front;
  while (temp != NULL)
  {
    cout << temp->fname << " " << temp->lname << ", " << temp->age << ", " << temp->year << endl;
    temp = temp->next;
  }
  cout << endl;
}

//reverse function
void reverse()
{
  struct queue *p = front;
  struct queue *q = NULL, *r = NULL;
  while (p != NULL)
  {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  front = q;
} // YASH Ends

//Stack functions
struct stack
{
  string fname;
  string lname;
  int age;
  int year;
  struct stack *next;
};

struct stack *top = NULL;

void push(string w, string x, int y, int z)
{
  struct stack *temp = new stack;
  temp->fname = w;
  temp->lname = x;
  temp->age = y;
  temp->year = z;
  temp->next = top;
  top = temp;
}

struct stack *pop()
{
  struct stack *temp;
  if (top == NULL)
    cout << "Empty Stack" << endl;
  else
  {
    temp = top;
    top = top->next;
  }
  return temp;
}

void display_s()
{
  struct stack *temp;
  if (top == NULL)
  {
    cout << "Empty Stack";
    return;
  }
  else
  {
    temp = top;
    while (temp != NULL)
    {
      cout << temp->fname << " " << temp->lname << ", " << temp->age << ", " << temp->year << endl;
      temp = temp->next;
    }
  }
  cout << endl;
}

// unorder tree  - level or inorder traversal
struct tree
{
  string fname;
  string lname;
  int age;
  int year;
  struct tree *left;
  struct tree *right;
};
struct tree *root = NULL;

struct tree *createNode(string w, string x, int y, int z)
{
  struct tree *temp = new tree;
  temp->fname = w;
  temp->lname = x;
  temp->age = y;
  temp->year = z;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

struct Queue // Mayukh
{
  int front;
  int rear;
  int size;
  struct tree **Q;
};

struct Queue *createQueue()
{
  struct Queue *q = new Queue;
  q->front = -1;
  q->rear = 0;
  q->size = 0;
  q->Q = new tree *;
  return q;
}

void enq(struct Queue *q, struct tree *temp)
{
  q->Q[q->rear++] = temp;
  q->size++;
}

struct tree *deq(struct Queue *q)
{
  q->size--;
  return q->Q[++q->front];
}

void insert_tree(string w, string x, int y, int z)
{
  struct tree *newNode = createNode(w, x, y, z);
  if (root == NULL)
  {
    root = newNode;
    return;
  }
  else
  {
    struct Queue *q = createQueue();
    enq(q, root);

    while (true)
    {
      struct tree *temp = deq(q);
      if (temp->left != NULL && temp->right != NULL)
      {
        enq(q, temp->left);
        enq(q, temp->right);
      }

      else
      {
        if (temp->left == NULL)
        {
          temp->left = newNode;
          enq(q, temp->left);
        }

        else
        {
          temp->right = newNode;
          enq(q, temp->right);
        }
        break;
      }
    }
  }
}

void Preorder(struct tree *temp)
{
  if (temp)
  {
    cout << temp->fname << " " << temp->lname << ", " << temp->age << ", " << temp->year << endl;
    Preorder(temp->left);
    Preorder(temp->right);
  }
}

void Postorder(struct tree *temp)
{
  if (temp)
  {
    Postorder(temp->left);
    Postorder(temp->right);
    cout << temp->fname << " " << temp->lname << ", " << temp->age << ", " << temp->year << endl;
  }
}

// linked list function
struct node
{
  string fname;
  string lname;
  int age;
  int year;
  struct node *next;
};

struct node *head = NULL;
struct node *curr = NULL;

void treetolinkedlist(struct tree *p)
{
  if (p)
  {
    treetolinkedlist(p->left);

    struct node *temp = new node;
    temp->fname = p->fname;
    temp->lname = p->lname;
    temp->age = p->age;
    temp->year = p->year;
    temp->next = NULL;
    if (head == NULL)
    {
      head = curr = temp;
    }
    else
    {
      curr->next = temp;
      curr = temp;
    }
    treetolinkedlist(p->right);
  }
}

void display_ll()
{
  struct node *temp = head;
  while (temp != NULL)
  {
    cout << temp->fname << " " << temp->lname << ", " << temp->age << ", " << temp->year << endl;
    temp = temp->next;
  }
} // Myukh ends

//Quick sort function for an linklist  - Suvo
node *getTail(node *cur)
{
  while (cur != NULL && cur->next != NULL)
    cur = cur->next;

  return cur;
}

node *partition(node *head, node *end, node **newHead, node **newEnd)
{
  node *pivot = end;
  node *prev = NULL, *cur = head, *tail = pivot;
  while (cur != pivot)
  {
    if (cur->fname < pivot->fname)
    {
      if ((*newHead) == NULL)
        (*newHead) = cur;

      prev = cur;
      cur = cur->next;
    }

    else if (cur->fname == pivot->fname)
    {
      if (cur->lname < pivot->lname)
      {
        if ((*newHead) == NULL)
          (*newHead) = cur;

        prev = cur;
        cur = cur->next;
      }

      else if (cur->lname == pivot->lname)
      {
        if (cur->age < pivot->age)
        {
          if ((*newHead) == NULL)
            (*newHead) = cur;

          prev = cur;
          cur = cur->next;
        }

        else if (cur->age == pivot->age)
        {
          if (cur->year < pivot->year)
          {
            if ((*newHead) == NULL)
              (*newHead) = cur;

            prev = cur;
            cur = cur->next;
          }
          else
          {
            if (prev)
              prev->next = cur->next;

            node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
          }
        }
        else
        {
          if (prev)
            prev->next = cur->next;

          node *tmp = cur->next;
          cur->next = NULL;
          tail->next = cur;
          tail = cur;
          cur = tmp;
        }
      }

      else
      {
        if (prev)
          prev->next = cur->next;

        node *tmp = cur->next;
        cur->next = NULL;
        tail->next = cur;
        tail = cur;
        cur = tmp;
      }
    }

    else
    {
      if (prev)
        prev->next = cur->next;

      node *tmp = cur->next;
      cur->next = NULL;
      tail->next = cur;
      tail = cur;
      cur = tmp;
    }
  }

  if ((*newHead) == NULL)
    (*newHead) = pivot;

  (*newEnd) = tail;

  return pivot;
}

node *quickSortRecur(node *head, node *end)
{
  if (!head || head == end)
    return head;

  node *newHead = NULL, *newEnd = NULL;

  node *pivot = partition(head, end, &newHead, &newEnd);

  if (newHead != pivot)
  {

    node *tmp = newHead;

    while (tmp->next != pivot)
      tmp = tmp->next;

    tmp->next = NULL;
    newHead = quickSortRecur(newHead, tmp);
    tmp = getTail(newHead);
    tmp->next = pivot;
  }
  pivot->next = quickSortRecur(pivot->next, newEnd);

  return newHead;
}

void quickSort(node **headRef)
{
  (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
  return;
}

void insert_ll(string w, string x, int y, int z)
{
  struct node *temp = new node;
  temp->fname = w;
  temp->lname = x;
  temp->age = y;
  temp->year = z;
  if (head == NULL)
  {
    head = curr = temp;
  }
  else
  {
    curr->next = temp;
    curr = temp;
  }
  quickSort(&head);
}

int main()
{
  int n;
  string w, x;
  int y, z, t;
  struct queue *temp;
  struct stack *temp1;
  cin >> n;
  // int arr[n];

  cout << "Entering Entities in Queue" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> w >> x >> y >> z;
    enq(w, x, y, z);
  }
  cout << "Entering Entities in Queue done Sucessfully" << endl
       << endl;
  //dequeue  & reqeue
  cout << "Dequing Element form Queue" << endl;
  for (int i = 0; i < n; i++)
  {
    temp = deq();
    cout << temp->fname << " " << temp->lname << ", " << temp->age << ", " << temp->year << endl;
    w = temp->fname;
    x = temp->lname;
    y = temp->age;
    z = temp->year;
    enq(w, x, y, z);
  }
  cout << "Requeue element " << endl
       << endl;

  cout << "\nPress Any key to Continue : " << endl;
  cout << "Press 0 to exit : " << endl;
  cin >> t;
  if (t != 0)
  {
    cout << "Push element to Stack" << endl;
    for (int i = 0; i < n; i++)
    {
      temp = deq();
      w = temp->fname;
      x = temp->lname;
      y = temp->age;
      z = temp->year;
      push(w, x, y, z);
    }
    cout << "Pushed element to Stack Sucessfully" << endl
         << endl;
    //stack to queue
    cout << "Push Element form Stack to Queue" << endl;
    for (int i = 0; i < n; i++)
    {
      temp1 = pop();
      w = temp1->fname;
      x = temp1->lname;
      y = temp1->age;
      z = temp1->year;
      enq(w, x, y, z);
    }
    cout << "Push Element form Stack to Queue Sucessfully" << endl
         << endl;

    cout << "Reversing the Queue" << endl;
    reverse();

    cout << "Inserting into unordered tree" << endl;
    //queue to tree
    for (int i = 0; i < n; i++)
    {
      temp = deq();
      w = temp->fname;
      x = temp->lname;
      y = temp->age;
      z = temp->year;
      insert_tree(w, x, y, z);
    }

    cout << "\nPress Any key to Continue : " << endl;
    cout << "Press 0 to exit : " << endl;
    cin >> t;
    if (t != 0)
    {
      cout << "Preorder Traversal: " << endl;
      Preorder(root);
      cout << "\nPress Any key to Continue : " << endl;
      cout << "Press 0 to exit : " << endl;
      cin >> t;
      if (t != 0)
      {
        cout << "\nPostorder Traversal: " << endl;
        Postorder(root);
        cout << "\nPress Any key to Continue : " << endl;
        cout << "Press 0 to exit : " << endl;
        cin >> t;
        if (t != 0)
        {
          cout << "Entering Entities from tree to linkedlist" << endl;
          treetolinkedlist(root);
          cout << "\nPress Any key to Continue : " << endl;
          cout << "Press 0 to exit : " << endl;
          cin >> t;
          if (t != 0)
          {
            cout << "Sorting Linked list" << endl;
            quickSort(&head);
            display_ll();
            cout << "\nPress Any key to Continue : " << endl;
            cout << "Press 0 to exit : " << endl;
            cin >> t;
            if (t != 0)
            {
              cout << "Enter New Member : " << endl;
              cin >> w >> x >> y >> z;
              insert_ll(w, x, y, z);

              display_ll();
            }
          }
        }
      }
    }
  }
}
