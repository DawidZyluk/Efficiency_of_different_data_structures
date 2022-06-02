#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Add BST::Insert. Implement List class 
// 

struct list_node
{
	int data;
	list_node* next;
};

class List
{
private:
	list_node* head;
public:
	List() { head = nullptr; }
	list_node* getHead() { return head; }
	int Count(list_node* p);
	void Insert(int x, int index);
};

struct bst_node
{
	bst_node* lchild;
	int data;
	bst_node* rchild;
};

class BST 
{
private:
	bst_node* root;
public:
	BST() { root = nullptr; }
	bst_node* getRoot() { return root; }
	void Insert(int x);
};

int* GetData(string fname);
int GetSize(string fname);
void DisplayArray(int* A, int n);
int* Insert(int* A, int len, int x, int index);
list_node* CreateList(int* A, int size);
void DisplayList(list_node* head);

int main()
{
	string fname = "dane.txt";
	/*cout << "Wybierz plik: ";
	cin >> fname;*/

	int size = GetSize(fname);
	int* tab = GetData(fname);	
	//DisplayArray(tab, size);


	List lista;
	lista.Insert(1, 0);
	lista.Insert(2, 1);
	lista.Insert(3, 2);
	lista.Insert(4, 0);
	DisplayList(lista.getHead());
	
}

int* GetData(string fname)
{
	fstream file;
	file.open(fname, ios::in);
	int* res = nullptr;

	if (file)
	{
		string line;
		getline(file, line);
		int size = stoi(line);

		res = new int[size+1];
		int i = 0;
		while (getline(file, line))
		{
			res[i++] = stoi(line);
		}
	}
	else
	{
		cout << "Plik nie istnieje";
	}

	file.close();
	return res;
}

int GetSize(string fname)
{
	fstream file;
	file.open(fname, ios::in);
	int size = 0;
	if (file)
	{
		string line;
		getline(file, line);
		size = stoi(line);
		file.close();
	}
	return size;
}

void DisplayArray(int* A, int n)
{
	cout << "[ ";
	for (int i = 0; i < n; i++)
	{
		cout << A[i];
		if (i < n - 1) cout << ", ";
	}
	cout << " ]" << endl;
}

int* Insert(int* A, int len, int x, int index)
{
	int* res = nullptr;
	if (index >= 0 && index < len)
	{
		res = new int[len + 1];
		int i = len - 1;

		while (index <= i)
		{
			res[i + 1] = A[i];
			i--;
		}
		res[index] = x;
		while (i >= 0)
		{
			res[i] = A[i];
			i--;
		}
	}
	return res;
}

list_node* CreateList(int* A, int size)
{
	list_node* head = new list_node;

	list_node* temp;
	list_node* last;

	head->data = A[0];
	head->next = nullptr;
	last = head;

	for (int i = 1; i < size; i++)
	{
		temp = new list_node;

		temp->data = A[i];
		temp->next = nullptr;

		last->next = temp;
		last = temp;
	}
	return head;
}

void DisplayList(list_node* head)
{
	list_node* p = head;

	while (p != nullptr) 
	{
		cout << p->data << " -> " << flush;
		p = p->next;
	}
}

void BST::Insert(int x)
{

	bst_node* t = root; // tail pointer
	bst_node* p = nullptr;
	bst_node* r = nullptr;

	// root is empty
	if (root == nullptr) 
	{
		p = new bst_node;
		p->data = x;
		p->lchild = nullptr;
		p->rchild = nullptr;
		root = p;
		return;
	}

	while (t != nullptr) 
	{
		r = t;
		if (x < t->data) t = t->lchild;
		else if (x > t->data) t = t->rchild;
		else return;
	}

	p = new bst_node;
	p->data = x;
	p->lchild = nullptr;
	p->rchild = nullptr;

	if (x < r->data) 
	{
		r->lchild = p;
	}
	else 
	{
		r->rchild = p;
	}

}

int List::Count(list_node* p)
{
	int c = 0;
	while (p)
	{
		c++;
		p = p->next;
	}
	return c;
}

void List::Insert(int x, int index)
{
	list_node* list = head;
	list_node* p = nullptr;
	list_node* temp = new list_node;
	temp->data = x;

	if (index < 0 || index > Count(list))
	{
		cout << "Wrong Index";
		return;
	}
	else
	{
		if (head == nullptr)
		{
			p = new list_node;
			p->data = x;
			p->next = nullptr;
			head = p;
			return;
		}
		else if(index == 0)
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			for (int i = 0; i < index - 1; i++)
				list = list->next;
			temp->next = list->next;
			list->next = temp;

		}
	}
}
