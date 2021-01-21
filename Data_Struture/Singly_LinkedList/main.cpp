// Singly Linked List :- 	Insert Node At First Position
//				Delete Node At First Position 
//				Display Linked List
//				Count Number Of Nodes
//				Reverse Linked List
//				Sorting Linked List in Ascending Order & Descending Order



#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SinglyLL
{
	private:
		PNODE Head;
		int size;
	
	public:
		SinglyLL();
		void InsertFirst(int );
		void DeleteFirst();
		void Display();
		int Count();
		void ReverseNodes();
		void PrintLine();
		void Sorting(char );
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SinglyLL::SinglyLL()
{
	Head = NULL;
	size = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL::InsertFirst(int num)
{
	PNODE newn = NULL;
	newn = new NODE;
	newn -> data = num;
	newn -> next = NULL;

	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{
		newn -> next = Head;
		Head = newn;
	}
	cout<<endl<<"Node Inserted Successfully.."<<endl;
	size++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL::DeleteFirst()
{
	PNODE temp = NULL;
	
	if(Head == NULL)
	{
		cout<<endl<<"There is no node in LinkedList"<<endl;
		return;
	}
	
	if(Head->next == NULL)
	{
		temp = Head;
		Head = NULL;
	}
	else
	{
		temp = Head;
		Head = Head->next;
	}
	cout<<endl<<"Node "<<temp->data<<", Deleted Successfully..."<<endl;
	free(temp);
	size--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL::Display()
{
	if(Head == NULL)
	{
		cout<<endl<<"There is no node in LinkedList"<<endl;
		return;
	}
	
	PNODE temp = Head;
	
	cout<<endl<<"Nodes are:"<<endl;
	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"| -> ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
		
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int SinglyLL::Count()
{
	if(Head == NULL)
	{
		return -1;
	}
	else
	{
		return size;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL::ReverseNodes()
{
	if(Head == NULL)
	{
		cout<<endl<<"There is no node in LinkedList"<<endl;
		return;
	}
	
	PNODE temp = Head, current = Head, previous = NULL;
	
	while(temp != NULL)
	{
		temp = temp -> next;
		current -> next = previous;
		previous = current;
		current = temp;
	}
	
	Head = previous;
	
	cout<<endl<<"After Reverse Linked List is:"<<endl;
	Display();

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL::Sorting(char ch)
{
	if(Head == NULL)
	{
		cout<<endl<<"There is no node in LinkedList"<<endl;
		return;
	}
	
	if( ch != 'a' && ch != 'd' && ch != 'A' && ch != 'D' )
	{
		cout<<"Invalid Sorting choice selected"<<endl<<"Note:Please select  'A'  or  'D'  or  'a'  or  'd' ";
		return;
	}
	
	if(ch == 'A' || ch == 'a')
	{
		//___________________________________________ Selection Sort
		cout<<endl<<"After Ascending Sorting Linked List is:"<<endl;
		
		PNODE temp = Head,current = NULL;
		int num=0;
	
		for(;temp->next != NULL; temp = temp->next)
		{
			for(current = temp->next; current != NULL; current = current->next)
			{
				if(current->data < temp->data)
				{
					num = temp->data;
					temp->data= current->data;
					current->data=num;
				}
			}
		}
	}
	else
	{
		//______________________________________________ Merge Sort
		cout<<endl<<"After Descending Sorting Linked List is:"<<endl;
		PNODE temp = Head;
		int num=0;
		bool bRet = true;
		
		for(int i = 0; i<size-1 && bRet != false; i++)
		{
			bRet = false;
			for(int j=0; temp->next != NULL && j < size-1-i ;temp = temp->next,j++)
			{
				if(temp->data < temp->next->data)
				{
					num = temp->data;
					temp->data = temp->next->data;
					temp->next->data = num;
					bRet = true;
				}
			}
			temp = Head;
		}
	}
	Display();
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL::PrintLine()
{
	cout<<endl<<"___________________________________________________________________"<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	SinglyLL sobj;
	int num=0,choice=1;
	char ch ;
	cout<<endl<<"_________________ViSHAL Singly Linked List_________________"<<endl;
	cout<<endl<<"--------------------------------------------------------------------------"<<endl;
	cout<<endl<<"1.Insert First\n2.Delete First\n3.Display\n4.Count\n5.Reverse\n6.Sorting\n0.Exit";
	cout<<endl<<"\n--------------------------------------------------------------------------"<<endl;
	while(choice)
	{
		cout<<"\nEnter ur Choice: ";
		cin>>choice;
	
		switch(choice)
		{
			case 1:
				cout<<"Enter any data: ";
				cin>>num;
				sobj.InsertFirst(num);
				sobj.PrintLine();
				break;
				
			case 2:
				sobj.DeleteFirst();
				sobj.PrintLine();
				break;
				
			case 3:
				sobj.Display();
				sobj.PrintLine();
				break;
				
			case 4:
				if(sobj.Count() == -1)
				{
					cout<<endl<<"There is no Node in LinkedList"<<endl;
				}
				else
				{
					cout<<endl<<"Number of nodes are: "<<sobj.Count();
				}
				sobj.PrintLine();
				break;
				
			case 5:
				sobj.ReverseNodes();
				sobj.PrintLine();
				break;
				
			case 6:
				cout<<endl<<"For Ascending,    Type    'A'  or  'a' "<<endl<<"For Descending,  Type  'D'  or  'd' "<<endl;
				cout<<endl<<"Enter: ";
				cin>>ch;
				sobj.Sorting(ch);
				sobj.PrintLine();
				break;
				
			
			case 0:
				cout<<endl<<"_________Thank you for using this application__________"<<endl;
				break;
				
			default:
				cout<<endl<<"Invalid choice entered\nNote:Please entered Valid Choice"<<endl;
				break;
		}
	}
	
	return 0;
}
				
			
			
			
			
			
			
			
				
				
