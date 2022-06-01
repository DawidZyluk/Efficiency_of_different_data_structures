#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct list_node
{
	int data;
	list_node* next;
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
	DisplayArray(tab, size);
	
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

		res = new int[size];
		int i = 0;
		while (getline(file, line))
		{
			res[i++] = stoi(line);
		}
	}
	else
	{
		cout << "Plik nie istnieje";
		exit(0);
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


