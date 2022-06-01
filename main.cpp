#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node
{
	int data;
	node* next;
};

void DisplayArray(int* A, int n);
void DisplayList(node* head);
void GetData(string nazwa);
node* CreateList(int* A, int size);
int* Insert(int* A, int len, int x, int index);

int main()
{
	string nazwa;
	/*cout << "Wybierz plik: ";
	cin >> nazwa;*/
	nazwa = "dane.txt";

	int A[] = { 3, 5, 7, 10, 15 };
	int size = sizeof(A) / sizeof(A[0]);
	node* list =  CreateList(A, size);
	DisplayList(list);
	
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

void DisplayList(node* head)
{
	node* p = head;

	while (p != nullptr) 
	{
		cout << p->data << " -> " << flush;
		p = p->next;
	}
}

void GetData(string nazwa)
{
	fstream file;
	string line;
	file.open(nazwa, ios::in);

	if (file)
	{
		while (getline(file, line))
		{
			cout << line;
		}
	}
	else
	{
		cout << "Plik nie istnieje";
		exit(0);
	}

	file.close();
}

node* CreateList(int* A, int size)
{
	node* head = new node;

	node* temp;
	node* last;

	head->data = A[0];
	head->next = nullptr;
	last = head;

	for (int i = 1; i < size; i++)
	{
		temp = new node;

		temp->data = A[i];
		temp->next = nullptr;

		last->next = temp;
		last = temp;
	}
	return head;
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
