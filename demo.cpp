//DSA Assignment-1 
//Submitted by-MOHAMMAD MUAZAM
//Regst. No.: RA1911003010091
//Submitted to: Dr.Annie Uthra

#include<iostream>
using namespace std;

class linkedList{
	public:

	struct Node
	{
		int data;
		Node* next;
	};

	struct Node* head = NULL;


	// 1. Empty_List() function 

	void Empty_List(){//function checks if list is empty or not
		if (head == NULL) {
			cout << "List is empty.";
		}
		else {
			cout << "List is not empty.";
		}
	}

	// 2. INSERT() function 

	void Insert(int value){//function inserts node at the end of LL
		Node* new_node = new Node();
		Node* last = head;
		new_node->data = value;
		new_node->next = NULL;
		if(head == NULL)
		{
			head = new_node;
			return;
		}
		while(last->next!= NULL)
			last = last->next;
		last->next = new_node;
		return;

	}

	
	void Insert(int value,int pos){//function inserts node at the specified position

		Node* new_node = new Node();
		Node* pNode = head;
		if (pos == 1 || pNode == NULL) {
			new_node->data = value;
			new_node->next = pNode;
			head = new_node;
		}
		else {
			pos = pos - 2;
			while (pos != 0) {
				pNode = pNode->next;
				pos--;
				if (pNode == NULL)
					break;
			}
			if (pNode == NULL) {
				cout << "The position is invalid." << endl;
				return;
			}

			new_node->data = value;
			new_node->next = pNode->next;
			pNode->next = new_node;
		}
	}


	// 3. DELETE() function 

	void Delete(int position) {	//function deletes node at the specified position

		Node* pNode = head;
		if (position == 1) {
			head = pNode->next;
			free(pNode);
		}
		else {
			position -= 2;
			while (position--) {
				pNode = pNode->next;
				if (pNode == NULL)
					break;
			}
			if (pNode == NULL) {
				cout << "The position is invalid." << endl;
				return;
			}
			Node* temp = pNode->next;
			pNode->next = pNode->next->next;
			free(temp);
		}
	}

	
	void Delete(int val,int start) { //function deletes node with the specified value
		Node* pNode = head;
		Node* prevNode = pNode;
		if (pNode == NULL)
			cout << "The list is empty." << endl;
		else {
			while (pNode->data != val) {
				prevNode = pNode;
				pNode = pNode->next;
				if (pNode->next == NULL) {
					break;
				}
			}
			if (pNode->next == NULL && pNode->data == val) {
				prevNode->next = NULL;
				free(pNode);
			}
			else if(pNode->next == NULL)
				cout << "The element is not present in the list." << endl;
			else if(prevNode == pNode) {
				head = prevNode->next;
				free(prevNode);
			}
			else {
				Node* temp = prevNode->next;
				prevNode->next = prevNode->next->next;
				free(temp);
			}
		}
	}


	// 4. DISPLAY() function 


	void Display() {//function to display linked list
		struct Node* ptr;
		ptr = head;
		while(ptr != NULL) {
			cout << "->" << ptr->data;
			ptr= ptr->next;
		}
	}


	// 5.MERGE() function


	
	void Merge(linkedList& ob1,linkedList & ob2) {//function to merge and sort the linked lists
		//merge part
		Node* last= ob1.head;
		if(last == NULL)
			last = ob2.head;
		else {
			while(last->next!= NULL)
			{
				last = last->next;
			}
			last->next = ob2.head;
		}

		
	}
    void Sort(linkedList& ob1) {//function to merge and sort the linked lists
		
		Node* last= ob1.head;
        //sort part
		int temp;
		for (Node* i = ob1.head; i-> next!= NULL; i = i->next) {
			for (Node* j = ob1.head; j-> next!= NULL; j = j->next) {
				if (j->data > j->next->data) {
					temp = j->data;
					j->data = j->next->data;
					j->next->data = temp;
				}
			}
		}
    }
    
};

// main function 
int main() {

	//initializing variables and linked lists
	int size1, size2, element, pos, choice,exit=1;
	linkedList LL1, LL2;

    cout<<"\nOperations:\n1)Add elements to a linked list.\n2)Insert() at specific position.\n3)Delete() based on position.\n4)Delete() based on value.\n5)Check if list is empty.\n6)Sort() list.\n7)Merge() lists.\n8)Display lists.\n9)Exit.\n";
    while(exit!=0){
        cout<<"\nEnter choice:\n";
        cin>>choice;
        if(choice==9){
            exit=0;
            cout<<"\n\nThank you.";
            break;
        }
        else{
            switch (choice)
            {
                case 1:
                    cout << "Enter the size of linked list 1 - " << endl;//taking number of elements in list 1
                    cin >> size1 ;

                    //inputting elements for 1st list
                    cout << "Enter elements of 1st linked list:" << endl;
                    while (size1--) {
                        cin >> element;
                        LL1.Insert(element);
                    }
                    cout<<"Successfully added elements to LL1.\n";
                    continue;
                    
                case 2:
                    //inserting element at the specified position
                    cout << "Enter the element to insert in LL1: " << endl;
                    cin >> element ;
                    cout << "Enter the position where it should be inserted: " << endl;
                    cin >> pos;
                    LL1.Insert(element, pos);
                    cout<<"Inserting element...\nInsertion successful.\n";
                    continue;

                case 3:
                    //deleting element at the specified position
                    cout << "Enter the position which needs to be deleted: " << endl;
                    cin >> pos;
                    LL1.Delete(pos);
                    cout << "\nDeleting element...\nDeletion successful\n";
                    continue;

                case 4:
                    //deleting the specified element
                    cout << "Enter the element to delete in LL1: " << endl;
                    cin >> element;
                    LL1.Delete(element, 1);
                    cout << "\nDeleting element...\nDeletion successful\n";
                    continue;

                case 5:     
                    //checking if the list is empty
                    cout << "Checking if any list is empty... \n";
                    LL1.Empty_List();
                    cout << endl;
                    continue;
                case 6: 
                    cout<<"Sorting List 1...\nSorting successful.\n";
                    LL1.Sort(LL1); 
                    continue;    
                case 7:
                    //merging lists 
                    cout << "Merge lists..." << endl;

                    cout << "Enter the size of linked list 2 - " << endl;//taking number of elements in list 2
                    cin >> size2;
                    //inputting elements for 2nd list
                    cout << "Enter elements of 2nd linked list" << endl;
                    while (size2--) {
                        cin >> element;
                        LL2.Insert(element);
                    }
                    //output list 2
                    cout << "Displaying list 2(LL2): ";
                    LL2.Display();
                    cout << endl << endl;

                    cout << "\nMerging LL1 and LL2...\n";

                    LL1.Merge(LL1, LL2);
                    cout << "Merging successful. \n";
                    continue;
                  
                case 8:
                    //output list 
                    cout << "\nDisplaying list 1(LL1): ";
                    LL1.Display();
                    cout << endl << endl;
                    continue;
                    
                default:
                    break;
            }
        }
        
    }

	return 0;
}

