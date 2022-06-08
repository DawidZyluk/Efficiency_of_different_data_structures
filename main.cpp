#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// TO DO:
// 

class List
{
public:
	struct node
	{
		int data;
		node* next;
	};

	List() { head = nullptr; }
	List(int* A, int size) { for (int i = 0; i < size; i++) Insert(A[i], i); }
	node* getHead() { return head; }
	int Count(node* p);
	void Display();
	void Insert(int x, int index);
	void Delete(int index);
	node* Search(int x);
private:
	node* head;
};

class BST 
{
public:
	struct node
	{
		node* lchild;
		int data;
		node* rchild;
	};

	BST() { root = nullptr; }
	BST(int* A, int size) { for (int i = 0; i < size; i++) Insert(A[i]); }
	node* getRoot() { return root; }
	void Insert(int x);
	node* Delete(node* p, int x);
	int Height(node* p);
	node* Predecessor(node* p);
	node* Successor(node* p);
	void DisplayInorder(node* p);
	void DisplayPreorder(node* p);
	node* Search(int x);
private:
	node* root;
};

int* GetData(string fname);
int GetSize(string fname);
void DisplayArray(int* A, int n);
int* Insert(int* A, int len, int x, int index);
int* Delete(int* A, int len, int index);
int* Search(int* A, int len, int x);
List::node* CreateList(int* A, int size);

int main()
{
	string fname = "dane.txt";
	/*cout << "Wybierz plik: ";
	cin >> fname;*/

	int size = GetSize(fname);
	int* tab = GetData(fname);	
	DisplayArray(tab, size);

	/*List list;
	list.Insert(1, 0);
	list.Insert(2, 1);
	list.Insert(3, 2);
	list.Insert(4, 3);
	list.Insert(5, 4);*/


	/*BST tree;
	tree.Insert(30);
	tree.Insert(20);
	tree.Insert(40);
	tree.Insert(10);
	tree.Insert(25);
	tree.Insert(35);
	tree.Insert(45);*/
	
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

int* Delete(int* A, int len, int index)
{
	int* res = nullptr;
	if (index >= 0 && index < len)
	{
		res = new int[len - 1];
		int j = 0;
		for (int i = 0; i < len; i++)
		{
			if (i == index) i++;
			res[j++] = A[i];
		}
	}
	return res;
}

int* Search(int* A, int len, int x)
{
	int* res = nullptr;
	for (int i = 0; i < len; i++) if (A[i] == x) res = &A[i];
	return res;
}

List::node* CreateList(int* A, int size)
{
	List::node* head = new List::node;

	List::node* temp;
	List::node* last;

	head->data = A[0];
	head->next = nullptr;
	last = head;

	for (int i = 1; i < size; i++)
	{
		temp = new List::node;

		temp->data = A[i];
		temp->next = nullptr;

		last->next = temp;
		last = temp;
	}
	return head;
} 

int List::Count(node* p)
{
	int c = 0;
	while (p)
	{
		c++;
		p = p->next;
	}
	return c;
}

void List::Display()
{
	node* p = head;
	while (p != NULL)
	{
		cout << p->data << "->";
		p = p->next;
	}
}

void List::Insert(int x, int index)
{
	node* list = head;
	node* p = nullptr;
	node* temp = new node;
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
			p = new node;
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

void List::Delete(int index)
{
	node* p = getHead();
	node* q = nullptr;

	if (index < 1 || index > Count(p))
	{
		cout << "Wrong index";
	}
	else if(index == 1)
	{
		q = head;
		head = head->next;
		free(q);
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		free(p);
	}
}

List::node* List::Search(int x)
{
	node* p = getHead();
	node* q = nullptr;

	while (p != NULL)
	{
		if (x == p->data)
		{
			q->next = p->next;
			p->next = head;
			head = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}

void BST::Insert(int x)
{

	node* t = root; // tail pointer
	node* p = nullptr;
	node* r = nullptr;

	// root is empty
	if (root == nullptr)
	{
		p = new node;
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

	p = new node;
	p->data = x;
	p->lchild = nullptr;
	p->rchild = nullptr;

	if (x < r->data) r->lchild = p;
	else r->rchild = p;
}

BST::node* BST::Delete(node* p, int x)
{
	node* q;

	if (p == nullptr) return nullptr;

	if (p->lchild == nullptr && p->rchild == nullptr) 
	{
		if (p == root) root = nullptr;
		delete p;
		return nullptr;
	}

	if (x < p->data) 
	{
		p->lchild = Delete(p->lchild, x);
	}
	else if (x > p->data) 
	{
		p->rchild = Delete(p->rchild, x);
	}
	else 
	{
		if (Height(p->lchild) > Height(p->rchild)) 
		{
			q = Predecessor(p->lchild);
			p->data = q->data;
			p->lchild = Delete(p->lchild, q->data);
		}
		else 
		{
			q = Successor(p->rchild);
			p->data = q->data;
			p->rchild = Delete(p->rchild, q->data);
		}
	}
	return p;
}

int BST::Height(node* p)
{
	int x;
	int y;
	if (p == nullptr) 
	{
		return 0;
	}
	x = Height(p->lchild);
	y = Height(p->rchild);
	return x > y ? x + 1 : y + 1;
}

BST::node* BST::Predecessor(node* p)
{
	while (p && p->rchild != nullptr) 
	{
		p = p->rchild;
	}
	return p;
}

BST::node* BST::Successor(node* p)
{
	while (p && p->lchild != nullptr) 
	{
		p = p->lchild;
	}
	return p;
}

void BST::DisplayInorder(node* p)
{
	if (p) 
	{
		DisplayInorder(p->lchild);
		cout << p->data << ", ";
		DisplayInorder(p->rchild);
	}
}

void BST::DisplayPreorder(node* p)
{
	if (p)
	{
		cout << p->data << ", ";
		DisplayPreorder(p->lchild);
		DisplayPreorder(p->rchild);
	}
}

BST::node* BST::Search(int x)
{
	node* t = root;
	while (t != nullptr) {
		if (x == t->data) {
			return t;
		}
		else if (x < t->data) {
			t = t->lchild;
		}
		else {
			t = t->rchild;
		}
	}
	return nullptr;
}
