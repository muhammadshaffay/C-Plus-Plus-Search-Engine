#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;


class Doc_Info
{
public:
	// Class Data Members
	int DocID;
	int term_frequency;
		
		Doc_Info()// Default Constructor
		{
			DocID = 0;
			term_frequency = 0;
		}
		
		Doc_Info(int d , int tf)// Parametrized Constructor
		{
			DocID = d;
			term_frequency = tf;			
		}
		
		void setDocID(int d)// Setter
		{	DocID = d;	}
		
		void setterm_frequency(int tf)// Setter
		{	term_frequency = tf;	}
		
		int getDocID()// Getter
		{	return DocID;	}
		
		int getterm_frequency()// getter
		{	return term_frequency;	}
		
		~Doc_Info()
		{
			term_frequency = 0;
			DocID = 0;
		}
};

template <class t>
class Node
{
public:
	//Class Data Members
	Node<t>* next;
	t data;

	Node()// Default Constructor
	{	next = NULL;	}
	
	Node(t val1)// Parametrized Constructors
	{
		data = val1;
		next=NULL;
	}
	
	~Node()// Destructor
	{
		next = NULL;
	}
	
	void setnext(Node<t>* s)// Setter
	{	next = s;	}
	
	Node<t>* getnext()// getter
	{	return next;	}
	
	t setdata(t x)// Setter
	{	data = x;	}
	
	t getdata()// Getter
	{	return data;	}
};

template <class T>
class list
{
public:
	// Class data Members
	Node<T>* head;
	Node<T>* tail;
	int size;
	
	list()// Default Constructor
	{
		head = NULL;
		tail = NULL;
	}
	
	~list()// Destructor
	{
		head = NULL;
		tail = NULL;
		size = 0;	
	}
	
	list(Node<T>* h)// Parametrized Constructor
	{	head = h;	}
	
	Node<T>* gethead()// Getter
	{	return head;	}
	
	Node<T>* gettail()// Getter
	{	return tail;	}
	
	void sethead(Node<T>* h)// Setter
	{	head = h;	}
	
	void settail(Node<T>* t)// Setter
	{	tail = t;	}
	
	int getsize()// Getter
	{	return size;	}
	
	void setsize(int s)// Setter
	{	size = s;	}
	
	void InsertAtStart(Node<Doc_Info> x)// Insertionc
	{
		Node<T>* node1 = new Node<T>(x);
		if (head == NULL)// If Empty
		{
			size = 1;
			head = node1;
		}
		else if (head != NULL)// If Not Empty
		{
			node1->setnext(head);
			head = node1;
			size += 1;
		}
	}
	
	void display()// Displayer
	{
			Node<T>* temp = head;
			while(temp!=NULL)// Displaying Till Null
			{
				cout << "  " ;
				cout << temp->getdata();
					temp=temp->getnext();
			}
			
	}
};

class Term_Info
{
	public:
	// Class data Members
	string term;
	list<Doc_Info> DI;
	
		Term_Info()// Default Constructor
		{
			term = "";
			DI = NULL;
		}
		
		Term_Info(string t)// Parametrized Constructor
		{	term = t;	}
		
		void setterm(string t)// Setter
		{	term = t;	}
		
		//void setDI(Doc_Info* di)
		//{	DI = di;	}
		
		string getterm()// Getter
		{	return term;	}
		
		//Doc_Info* getDI()
		//{	return DI;	}	
		
		~Term_Info()
		{
			term = "";
		}
};

template <class T>
class AVLNode
{
public:
	// Class data members
	T val;
	AVLNode* left;
	AVLNode* right;
	int height;

	AVLNode()// Default Constructor
	{
		left = NULL;
		right = NULL;
		height=0;
	}
	
	~AVLNode()// Destructor
	{
		left =  NULL;
		right = NULL;
		height = 0;
	}
	
	void setleft(AVLNode<T>* v)// Setter
	{	left=v;	}
	
	void setright(AVLNode<T>* v)// Setter
	{	right=v;	}
	
	AVLNode<T>* getleft()// Getter
	{	return left;	}
	
	AVLNode<T>* getright()// Getter
	{	return right;	}
	
	void setval(T s)// Setter
	{	val=s;	}
	
	T getval()// Getter
	{	return val;	}
	
	void seth(int s)// Setter
	{	height=s;	}
	
	int geth()// Getter
	{	return height;	}
};

template <class T>
class AVLTree
{
	// Class Data members
	AVLNode<T>* root;
	
public:
	AVLTree()// Default Constructor
	{	root = NULL;	}
	
	~AVLTree()// Destructor
	{	makeEmpty(root);	}

	AVLNode<T>* makeEmpty(AVLNode<T>* rt)// Emptier Function
	{
		if (rt == NULL)
			return NULL;
		{
			makeEmpty(rt->getleft());
			makeEmpty(rt->getright());
			delete rt;
		}
		return NULL;
	}

	AVLNode<T>* newNode(int key,string s,int f)// New Node Creator
	{
		AVLNode<T>* node = new AVLNode<T>(key,s,f);
		node->setleft(NULL);
		node->setright(NULL);
		node->seth(0);
		return node;
	}

	int getBalance(AVLNode<T>* node)// balance Checker
	{
		if (node == NULL){
			return 0;
		}

		return Height(node->getleft()) - Height(node->getright());
	}

	bool isBalance()//function to find if tree is balanced or not
	{	return isBalanced(root);	}
	
	bool isBalanced(AVLNode<T>* rt)// Balance Checker's Implementation
	{
		int lH;
		int rH;

		if (rt == NULL)
			return true;

		lH = Height(rt->getleft());
		rH = Height(rt->getright());

		if ((lH - rH) <= 1 && isBalanced(rt->getleft()) && isBalanced(rt->getright()))
			return true;

		return false;
	}
	
	void insert(AVLNode<T>* no,string term)// insert function
	{
		root = Insert(root,no ,term);
	}
	
	AVLNode<T>* Insert(AVLNode<T>* node,AVLNode<T>* no,string s)// Insertion
	{
		
		if (node == NULL)
		{	return no;	}
		
		if (s < node->val.term)
			node->setleft( Insert(node->getleft(),no,s));
			
		else if (s > node->val.term)
			node->setright(Insert(node->getright(),no,s));
			
		else 
			return node;
		
			
		node->seth(1+ max(Height(node->getleft()), Height(node->getright()))) ;

		int balance = getBalance(node);
		
		//single rotations
		if (balance > 1 && s < node->getleft()->val.term)
			return rightRotate(node);
		if (balance < -1 && s > node->getright()->val.term)
			return leftRotate(node);
			
		//double rotations
		if (balance > 1 && s > node->getleft()->val.term)
		{
			node->setleft(leftRotate(node->getleft())) ;
			return rightRotate(node);
		}
		else if (balance < -1 && s <  node->getright()->val.term)
		{
			node->setright(rightRotate(node->getright())) ;
			return leftRotate(node);
		}
		
		return node;
	}
	AVLNode<T>* rightRotate(AVLNode<T>* y)//function to rotate right
	{
		AVLNode<T>* x = y->getleft();
		AVLNode<T>* T2 = x->getright();

		// Performing rotation
		x->setright(y);
		y->setleft(T2);

		y->seth(max(Height(y->getleft()),
			Height(y->getright())) + 1) ;
		x->seth(max(Height(x->getleft()),
			Height(x->getright())) + 1);

		return x;
	}

	AVLNode<T>* leftRotate(AVLNode<T>* x)//function to rotate left
	{
		AVLNode<T>* y = x->getright();
		AVLNode<T>* T2 = y->getleft();

		// Performing rotation
		y->setleft(x);
		x->setright(T2);

		x->seth( max(Height(x->getleft()),
			Height(x->getright())) + 1);
		y->seth(max(Height(y->getleft()),
			Height(y->getright())) + 1);

		return y;
	}
	
	void displayInOrder()// Display Caller
	{	inOrderDisplay(root);	}
	
	void inOrderDisplay(AVLNode<T>* rt)// Displays INorder
	{
		if (rt != NULL)
		{
			inOrderDisplay(rt->getleft());
			cout << "term : "<<rt->val.term << endl;
			
			while(rt->val.DI.head!=NULL)// While Empties
			{
				cout<<"Docid  : "<<rt->val.DI.head->data.DocID<<endl;
				cout<<"frequency : "<<rt->val.DI.head->data.term_frequency<<endl;
				rt->val.DI.head=rt->val.DI.head->next;
			}
			
			cout<<endl<<endl;
			inOrderDisplay(rt->getright());
		}
	}
	
	T height()// height Checker Caller
	{	return Height(root);	}
	
	int Height(AVLNode<T>* node)// Height Checker
	{
		if (node == NULL)
			return -1;
		else
			return node->geth();
	}

	int Max(int a, int b)//max function
	{	return (a > b) ? a : b;	}

	AVLNode<T>* minValueNode(AVLNode<T>* node)	//function to find indorder successor
	{
		AVLNode<T>* currNode = node;

		while (currNode && currNode->getleft() != NULL)//finding leftmost leaf
		{	currNode = currNode->getleft();	}

		return currNode;
	}
};


class Search_Engine
{
	// Class Data members
	int c1;
	AVLTree<Term_Info> *index;
	AVLNode<Term_Info>* arr;
	
	public:
	Search_Engine()// Default Constructor
	{
		index = new AVLTree<Term_Info>[200];
	}
	
	~Search_Engine()// Destructor
	{
		index = NULL;
		arr = NULL;
	}
	
	AVLNode<Term_Info>* Create_Index(char Docs[300][300] , int n)
	{
	// Declaring Variables	
		AVLNode<Term_Info> *z;
		z = new AVLNode<Term_Info>[100];
		arr = new AVLNode<Term_Info>[100]; 
		
		int count=0;
		
		for(int i = 0; i < n; i++)
		{	Add_Doc_to_Index( Docs[i] , i+1,count);	}
		
		for (int i=0;i<count;i++)
		{	z[i]=arr[i];				}
			
		c1 = count;
		
		for (int i=0;i<count;i++)
		{
			AVLNode<Term_Info> *p=&arr[i];			
			index->insert(p,arr[i].val.term);
		}
		index->displayInOrder();

		return z;
	}

	void Add_Doc_to_Index(char fileName[256] , int id,int &count)
	{
	// Declaring Variables	
		int size = 0;
		int size_U = 0;
		int maxf=0;
		string text = filehandling(fileName);
		string *P = tokenizer(text , size);
    	string *U = new string[50];
		int *F = frequency(P , U, size, size_U,maxf);

	// Adding Documents To Indexes
		for(int i = 0; i <size_U; i++)
		{
			Node<Doc_Info> new_node_temp;// Creating A Node Of LL
			new_node_temp.data.term_frequency = F[i];
			new_node_temp.data.DocID = id;
			
			AVLNode<Term_Info> new_node;// Creating A Node Of AVLTree
			new_node.val.term = U[i] ;
			
			new_node.val.DI.InsertAtStart(new_node_temp);

			int found=0;
			if (count==0)
			{
				arr[count]=new_node;
				count++;
			}
			else
			{
				for (int j=0;j<count;j++)
			    {
			    	if (arr[j].val.term == new_node.val.term)
			    	{
			    		arr[j].val.DI.InsertAtStart(new_node_temp);
			    		found=1;
			    		break;
					}
				}
				if (found==0)
				{
					arr[count] = new_node;
					count++;
				}
				found = 0;
			}
		}
	}
	

	string filehandling(char fileName[256])
	{
	// Declaring Variables
		string text;
		string main = "";
		                             
	  	ifstream myfile;
	  	myfile.open (fileName);
	// Collecting File Data	 
		getline(myfile , main);   
		while (getline(myfile , text))
		{
			main = main + text;
		}
	
	  	myfile.close();
	// Returning Data
	  	return main;
	}

	string* tokenizer(string text , int &size)
	{
	// Declaring Variables
		string *P = new string[100];
		string temp = "";
		
		int c=0,row = 0;
	// Tokenizing On The Basis Of Spaces & Dots	
		for (int i = 0 ; text[i] != '\0'; i++)
		{
			if(text[i] == ' ' | text[i] == '.')
			{
				P[row] = temp;
				row += 1;
				c++;
				temp = "";
			}
			else
			{
				temp = temp + text[i];
			}
		}
		P[row] = temp;
		size = ++row;
	// Returning Tokenized Words
		return P;
	}

	int* frequency(string *P , string *U , int size, int &size_U,int &maxf)
	{
	// Decalring Variables
		int indexer = 0;
	// Extarcting Unique Words
		for (int i=0; i<=size+1; i++)
	    {
	        int j;
	        for (j=0; j<i; j++)
	           if (P[i] == P[j])
	               break;
	         if (i == j)
	         {
	         	U[indexer]=P[i];
	         	indexer++;
			 }
	    }
		indexer--;
		int *F = new int[indexer];
		int count = 0;
		// Counting Frequencies
		for (int i = 0; i < indexer; i++ )
		{
			for(int j = 0; j < size; j++)
			{
				if(U[i] == P[j])
				{
					count++;
				}
			}
			F[i] = count;
			count = 0;
		}
		size_U = indexer;
		// Returning Frequencies
		return F;
	}

	void display_rules(int *frequencies , int *ids , int count_freqs , int count_ids)
	{
	// Declaring Variables
		int indexer = 0;
		int *Unique = new int[count_ids];
		int * Unique_Freq = new int[count_ids];
		int *  Unique_Collective_Freq = new int[count_ids];
		
	// Extracting Unique Documents
		for (int i = 0; i <= count_ids; i++)
	    {
	    	int j;
	        for (j = 0; j < i; j++)
	        {
	        	if (ids[i] == ids[j])
	               break;
			}
	        if (i == j)
	        {
	         	Unique[indexer] = ids[i];
	         	Unique_Freq[indexer] = 0;
	         	Unique_Collective_Freq[indexer] = 0;
	         	indexer++;
			} 
	    }
		indexer--;
	// Calculating Doc Frequencies and Collective Term Frequencies	
		for(int i = 0; i < indexer; i++)
		{
			for(int j = 0; j <= count_ids; j++)
			{
				if(Unique[i] == ids[j])
				{
					Unique_Freq[i] += 1;
					Unique_Collective_Freq[i] += frequencies[j];
				}
			}
		}
	// Arranging According to 3 Display Rules
		for(int x = 0; x < indexer; x++)
		{
			for(int y = x + 1; y < indexer; y++)
			{
				if(Unique_Freq[x] < Unique_Freq[y])// Rule 1
				{
					swap(Unique_Freq[x] , Unique_Freq[y]);
					swap(Unique[x] , Unique[y]);
					swap(Unique_Collective_Freq[x] , Unique_Collective_Freq[y]);
				}
				else if(Unique_Freq[x] == Unique_Freq[y])
				{
					if(Unique_Collective_Freq[y] > Unique_Collective_Freq[x])// Rule 2
					{
						swap(Unique_Freq[x] , Unique_Freq[y]);
						swap(Unique[x] , Unique[y]);
						swap(Unique_Collective_Freq[x] , Unique_Collective_Freq[y]);
					}
					else if(Unique_Collective_Freq[x] == Unique_Collective_Freq[y])// Rule 3
					{
						if(Unique[x] > Unique[y])
						{
							swap(Unique_Freq[x] , Unique_Freq[y]);
							swap(Unique[x] , Unique[y]);
							swap(Unique_Collective_Freq[x] , Unique_Collective_Freq[y]);
						}
					}
				}
			}
		}
	// Displaying Search Results
		cout << "\t\t\t\t\t\t\t   ================== \n";
		cout << "\t\t\t\t\t\t\t   | Search Results |\n";
		cout << "\t\t\t\t\t\t\t   ================== \n\n";
		
		for(int i = 0; i < indexer; i++)
		{
			cout << "\t\t\t\t\t---------------------------------------------------------------\n";
			cout << "\t\t\t\t\t| DOC-ID : " << Unique[i];
			cout << "  | DoC-Frequency : " << Unique_Freq[i];
			cout << "  | Collective Frequency : " << Unique_Collective_Freq[i] << " | " << endl;
		}
		cout << "\t\t\t\t\t---------------------------------------------------------------\n";
	}

	void searchquery(string *s , int row , AVLNode<Term_Info>*p)
	{
	// Decalring Variables
		int *frequencies = new int[30];
		int *ids = new int[30];
		
		int count_freqs = 0;
		int count_ids = 0;
		
		cout << "\t\t\t\t\t\t\t   ------------------ \n";
		cout << "\t\t\t\t\t\t\t   | Pre-Processing |\n";
		cout << "\t\t\t\t\t\t\t   ------------------ \n\n";
	// Extracting DoC-IDs & Frequencies
		for (int i = 0 ; i < row; i++)
		{
			for (int j = 0 ; j < c1 ; j++)
			{
				if (s[i] == p[j].val.term)
				{
					while (p[j].val.DI.head)
					{	
						frequencies[count_freqs] = p[j].val.DI.head->data.term_frequency;
						ids[count_ids] = p[j].val.DI.head->data.DocID;
						
						count_freqs += 1;
						count_ids += 1;
						
						cout << "\t\t\t\t\t\t\t------------ ------------- \n";
						cout << "\t\t\t\t\t\t\t|Frequency : "<< p[j].val.DI.head->data.term_frequency << " ";	
						cout << "Doc-ID :" << p[j].val.DI.head->data.DocID << " |\n";
						
						p[j].val.DI.head = p[j].val.DI.head->next;
					}
					cout<<endl;
				}
			}
		}
	// Function That Displays According To Rules
		cout << endl << endl << endl;
		display_rules( frequencies , ids , count_freqs , count_ids);
	}
};

int main()
{
// Filenames
	char filenames[10][300] = {"Doc1.txt" , "Doc2.txt" , "Doc3.txt" , "Doc4.txt"};
	
// Displaying Search Engine
	cout << "\t\t\t\t\t\t\t   ================= \n";
	cout << "\t\t\t\t\t\t\t   | Search Engine |\n";
	cout << "\t\t\t\t\t\t\t   ================= \n\n";
	
// AVL Tree Creation	
	Search_Engine s;
	AVLNode<Term_Info>* x = s.Create_Index(filenames , 4);

//Inserting Query Info	
	cout << "\t\t\t\t\t\t\t   ================= \n";
	cout << "\t\t\t\t\t\t\t   | Query Section |\n";
	cout << "\t\t\t\t\t\t\t   ================= \n\n";
	
	int size;
	cout << endl << "Enter the size of query : " ;
	cin>>size;
	
// Inserting Query	
	string *input=new string[size];
	cout << endl << "Enter the query : " ;
	for (int i=0;i<size;i++)
	{	cin>>input[i];	}
	
// Search Engine	
	s.searchquery(input, size ,x);
	return  0;
}
