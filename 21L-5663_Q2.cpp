#include <iostream>
using namespace std;

template <class T>
class doublylinkedlist
{
	struct node
	{
		T data;
		node *next,*prev;
	};
	node *head;

public:
	doublylinkedlist()
	{
		head=NULL;
	}
	
	bool insertatstart(T const val)
	{
		node *temp=new node;
		temp->data=val;
		if(head==NULL)
		{
		temp->next=head;
		head=temp;
		}
		else
		{
			temp->next=head;
			head->prev=temp;
			head=temp;
		}
		return 0;
	}

	bool insertatend(T const val)
	{
		node*temp=new node;
		temp->data=val;
		temp->next=NULL;
		node* cur=head;
		while(cur->next!=NULL)
		{
			temp->prev=cur->next;
			cur=cur->next;
		}
		if(head==NULL)
		{
			head=temp;
			return 0;
		}
		else
		{
			cur->next=temp;
			return 1;
		}
	}

	bool deletefromstart()
	{
		if(head == NULL)
		{
			return 0;
		}
		else
		{
			node*cur=head;
			head=cur->next;
			head->prev=nullptr;
			delete cur;
			cur=0;
			
			return 1;
		}
		
	}

	bool deletefromend()
	{
		if(head==NULL)
		{
			cout<<"list empty"<<endl;
			return 0;
		}
		else
		{
			node*cur=head,*last=0;
			while(cur!=NULL)
			{
				last=cur;
				cur=cur->next;
			}
			if(head->next==NULL)
			{
				head=nullptr;
				delete last;
				last=0;
				
				return 1;
			}
			else
			{
				last->prev->next=NULL;
				delete last;
				last=0;
				
				return 1;
			}
		}
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

	void reverseprint()
	{
		node*cur=head;
		while(cur->next!=NULL)
		{
			cur=cur->next;
		}
		while(cur!=head)
		{
			cout<<cur->data<<" ";
			cur=cur->prev;
		}
		cout<<cur->data;
		cout<<endl;
	}

	~doublylinkedlist()
	{
		while(head!=NULL)
		{
			node*cur=head;
			head=cur->next;
			delete cur;
			cur=head;
		}
	}
};

int main()
{
	doublylinkedlist<int> l1;
	l1.insertatstart(7);
	l1.insertatstart(5);
	l1.insertatstart(3);
	l1.insertatstart(1);
	l1.insertatend(9);
	l1.insertatend(11);
	l1.insertatend(13);
	l1.insertatend(15);
	cout << "Linked list is : ";
	l1.print();
	cout << endl << "Linked list in reverse order is : ";
	l1.reverseprint();
	cout << endl << "Element deleted form start : ";
	l1.deletefromstart();
	l1.print();
	cout << endl << "New Linked list in reverse order is : ";
	l1.reverseprint();
	cout << endl << "Element deleted form end : ";
	l1.deletefromend();
	l1.print();
	cout << endl << "New Linked list in reverse order is : ";
	l1.reverseprint();
	cout << endl;

	system("pause");
	return 0;
}