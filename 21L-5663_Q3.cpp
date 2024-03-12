#include<iostream>
using namespace std;

template <class T>

class circulardoublylinkedlist
{
	struct node
	{
		T data;
		node *next,*prev;
	};
	node *tail;

public:
	circulardoublylinkedlist()
	{
		tail=NULL;
	}
	
	bool inatst(T const val)
	{
		node *temp=new node;
		temp->data=val;
		if(tail==NULL)
		{
		temp->next=temp;
		temp->prev=temp;
		tail=temp;
		}
		else
		{
			node *temp1=tail->next;
			temp->next=temp1;
			temp->prev=tail;
			temp1->prev=temp;
			tail->next=temp;
		}
		return 0;
	}

	bool inatend(T const val)
	{
		node*temp=new node;
		temp->data=val;
		if(tail==NULL)
		{
			tail=temp;
			return 0;
		}
		else
		{
			node* temp1=tail->next;
			temp->next=temp1;
			temp->prev=tail;
			tail->next=temp;
			temp1->prev=temp;
			tail=temp;
			return 1;
		}
	}

	bool delfromst()
	{
		if(tail == NULL)
		{
			return 0;
		}
		else
		{
			node*cur=tail->next;
			tail->next=cur->next;
			cur->next->prev=tail;
			delete cur;
			cur=0;
			
			return 1;
		}	
	}

	bool delfromend()
	{
		if(tail==NULL)
		{
			cout<<"list empty"<<endl;
			return 0;
		}
		else
		{
			node*cur=tail->prev;
				cur->next=tail->next;
				tail->next->prev=cur;
				delete tail;
				tail=cur;
				
				return 1;
		}
	}

	bool isCircular()
	{
		node*cur=tail->next;
		int flag=0;
		while(cur!=NULL)
		{
			if(cur==tail)
			{
				cout<<"circular"<<endl;
				flag=1;
				return true;
			}
			cur=cur->next;
		}
		if(flag==0)
			return false;
		else 
			return true;
	}

	void print()
	{
		node*cur=tail->next;
		while(cur!=tail){
			cout<<cur->data<<" ";
			cur=cur->next;
		}
		cout<<cur->data<<" ";
		cout<<endl;
	}

   ~circulardoublylinkedlist()
   {
    node* temp;
    node* cur = tail->next;
    while (cur != tail)
    {
        temp = cur;
        cur = cur->next;
        delete temp;
		temp=0;
		cur->prev=tail;
		tail->next=cur;
    }
	delete tail;
	tail=0;
    }
};

int main()
{
	circulardoublylinkedlist<int> l1;
	l1.inatst(7);
	l1.inatst(5);
	l1.inatst(3);
	l1.inatst(1);
	l1.inatend(9);
	l1.inatend(11);
	l1.inatend(13);
	l1.inatend(15);
	cout << "Linked list is : ";
	l1.print();
	l1.isCircular();
	cout << endl << "deleted from start : ";
	l1.delfromst();
	l1.print();
	l1.isCircular();
	cout << endl << "deleted from end : ";
	l1.delfromend();
	l1.print();
	l1.isCircular();
	cout << endl;

	system("pause");
	return 0;
}