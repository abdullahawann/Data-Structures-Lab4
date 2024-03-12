#include <iostream>
using namespace std;

template <class T>
class linkedlist
{
	struct node
	{
		T data;
		node* next;
	};

	node* head;

public:
	linkedlist()
	{
		head = NULL;
	}

	bool sortedInsert(T val)
    {
        node* temp = new node;
        temp->data = val;
        node* curr = head, *prev = 0;

        while (curr != NULL && curr->data < val)
        {
            prev = curr;
            curr = curr->next;
        }

        if (prev == 0)
        {
            head = temp;
        }
        else
        {
            prev->next = temp;
        }
        temp->next = curr;
        cout << "Element is inserted in Sorted Linked List" << endl;
        return 1;
	}

	void deleteatstart()
	{
		node* temp;
		temp=head;
		head=head->next;
		delete temp;
		temp=0;
	}

	void deleteatend()
	{
		node* cur=head,*prev=0,*seclast=0;
		while(cur!=NULL)
		{
			seclast=prev;
			prev=cur;
			cur=cur->next;
		}
		seclast->next=NULL;
		delete prev;
		prev=0;

	}

	void print()
	{
		node*cur=head;
		while(cur!=NULL)
		{
			cout<<cur->data<<" ";
			cur=cur->next;
		}
		cout<<endl;
	}
	void printnth(int ind)
	{
		int count=0;
		node* cur=head;
		while(cur != NULL && count!=ind)
		{
			count++;
			cur=cur->next;
		}
		cout << ind << "th index data is : " << cur->data;
	}

	~linkedlist()
	{
		while(head != NULL)
		{
			node*cur = head;
			head = cur->next;
			delete cur;
			cur = head;
		}
	}
};

int main()
{
	linkedlist<int> l1;
	l1.sortedInsert(4);
	l1.sortedInsert(3);
	l1.sortedInsert(2);
	l1.sortedInsert(1);
	l1.sortedInsert(5);
	l1.sortedInsert(6);
	l1.sortedInsert(7);
	l1.sortedInsert(8);
	cout << endl << "The linked list is : ";
	l1.print();
	cout << endl;
	l1.printnth(4);
	cout << endl << endl << "Value deleted from start : ";
	l1.deleteatstart();
	l1.print();
	cout << endl;
	l1.printnth(4);
	cout << endl << endl << "Value deleted from end : ";
	l1.deleteatend();
	l1.print();
	cout << endl;
	l1.printnth(4);
	cout << endl << endl;

	system("pause");
	return 0;
}