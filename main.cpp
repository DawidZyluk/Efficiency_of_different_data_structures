#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

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
	node* Delete(node* p);
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
int* RandomArrayGenerator(int n);
int* AscendingArrayGenerator(int n);
int* DescendingArrayGenerator(int n);
void DisplayArray(int* A, int n);
int* Insert(int* A, int len, int x, int index);
int* Delete(int* A, int len, int index);
int* Search(int* A, int len, int x);
int Random(int max, int min = 1);
double Average(double* A, int n);

int main()
{
	clock_t start, end;
	double executionTime;
	string fname = "dane.txt";
	/*cout << "Wybierz plik: ";
	cin >> fname;*/

	/*int size = GetSize(fname);
	int* tab = GetData(fname);*/

	double* InsertionTimes = new double[10];
	double* SearchingTimes = new double[10];
	double* DeletionTimes = new double[10];
	double CollectiveData[27]{ 0 };

	cout.setf(ios::fixed, ios::floatfield);

	int* array = nullptr;
	int size = 300000000;
	for (int i = 0; i < 10; i++)
	{
		int number = Random(size);
		int index = Random(size-1);

		array = AscendingArrayGenerator(size);

		start = clock();
		Search(array, size, number);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		SearchingTimes[i] = executionTime;

		start = clock();
		array = Insert(array, size, number, index);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		InsertionTimes[i] = executionTime;

		start = clock();
		array = Delete(array, size, index);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		DeletionTimes[i] = executionTime;
		delete[] array;
	}
	cout << "########## Array ##########\n";
	cout << "Size " << size << endl;
	cout << "\nAverage times for ascending order (insertion, search and deletion):\n";
	cout << Average(InsertionTimes, 10) << endl;
	cout << Average(SearchingTimes, 10) << endl;
	cout << Average(DeletionTimes, 10) << endl << endl;


	for (int i = 0; i < 10; i++)
	{
		int number = Random(size);
		int index = Random(size - 1);

		array = DescendingArrayGenerator(size);

		start = clock();
		Search(array, size, number);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		SearchingTimes[i] = executionTime;

		start = clock();
		array = Insert(array, size, number, index);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		InsertionTimes[i] = executionTime;

		start = clock();
		array = Delete(array, size, index);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		DeletionTimes[i] = executionTime;
		delete[] array;
	}
	cout << "Average times for descending order (insertion, search and deletion):\n";
	cout << Average(InsertionTimes, 10) << endl;
	cout << Average(SearchingTimes, 10) << endl;
	cout << Average(DeletionTimes, 10) << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		int number = Random(size);
		int index = Random(size - 1);

		array = RandomArrayGenerator(size);

		start = clock();
		Search(array, size, number);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		SearchingTimes[i] = executionTime;

		start = clock();
		array = Insert(array, size, number, index);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		InsertionTimes[i] = executionTime;

		start = clock();
		array = Delete(array, size, index);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		DeletionTimes[i] = executionTime;
		delete[] array;
	}
	cout << "Average times for random order (insertion, search and deletion):\n";
	cout << Average(InsertionTimes, 10) << endl;
	cout << Average(SearchingTimes, 10) << endl;
	cout << Average(DeletionTimes, 10) << endl << endl;

	size = 40000;
	
	for (int i = 0; i < 10; i++)
	{
	array = AscendingArrayGenerator(size);
	List list1(array, size);
		int number = Random(size);
		int index = Random(size - 1);

		start = clock();
		list1.Search(number);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		SearchingTimes[i] = executionTime;

		start = clock();
		list1.Insert(number, index);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		InsertionTimes[i] = executionTime;

		start = clock();
		list1.Delete(index);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		DeletionTimes[i] = executionTime;
	}
	cout << "########## List ##########\n";
	cout << "Size " << size << endl;
	cout << "\nAverage times for ascending order (insertion, search and deletion):\n";
	cout << Average(InsertionTimes, 10) << endl;
	cout << Average(SearchingTimes, 10) << endl;
	cout << Average(DeletionTimes, 10) << endl << endl;
	
	for (int i = 0; i < 10; i++)
	{
	array = DescendingArrayGenerator(size);
	List list2(array, size);

		int number = Random(size);
		int index = Random(size - 1);

		start = clock();
		list2.Search(number);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		SearchingTimes[i] = executionTime;

		start = clock();
		list2.Insert(number, index);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		InsertionTimes[i] = executionTime;

		start = clock();
		list2.Delete(index);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		DeletionTimes[i] = executionTime;

	}
	cout << "Average times for descending order (insertion, search and deletion):\n";
	cout << Average(InsertionTimes, 10) << endl;
	cout << Average(SearchingTimes, 10) << endl;
	cout << Average(DeletionTimes, 10) << endl << endl;
	
	
	for (int i = 0; i < 10; i++)
	{
	array = RandomArrayGenerator(size);
	List list3(array, size);

		int number = Random(size);
		int index = Random(size - 1);

		start = clock();
		list3.Search(number);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		SearchingTimes[i] = executionTime;

		start = clock();
		list3.Insert(number, index);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		InsertionTimes[i] = executionTime;

		start = clock();
		list3.Delete(index);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		DeletionTimes[i] = executionTime;

	}
	cout << "Average times for random order (insertion, search and deletion):\n";
	cout << Average(InsertionTimes, 10) << endl;
	cout << Average(SearchingTimes, 10) << endl;
	cout << Average(DeletionTimes, 10) << endl << endl;
	

	size = 60000;
	for (int i = 0; i < 10; i++)
	{
		array = AscendingArrayGenerator(size);
		BST tree1(array, size);

		int number = Random(size);

		start = clock();
		tree1.Insert(number);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		InsertionTimes[i] = executionTime;

		start = clock();
		BST::node* p = tree1.Search(number);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		SearchingTimes[i] = executionTime;

		start = clock();
		tree1.Delete(p);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		DeletionTimes[i] = executionTime;

	}
	cout << "########## Tree ##########\n";
	cout << "Size " << size << endl;
	cout << "\nAverage times for ascending order (insertion, search and deletion):\n";
	cout << Average(InsertionTimes, 10) << endl;
	cout << Average(SearchingTimes, 10) << endl;
	cout << Average(DeletionTimes, 10) << endl << endl;


	for (int i = 0; i < 10; i++)
	{
		array = DescendingArrayGenerator(size);
		BST tree2(array, size);

		int number = Random(size);

		start = clock();
		tree2.Insert(number);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		InsertionTimes[i] = executionTime;

		start = clock();
		BST::node* p = tree2.Search(number);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		SearchingTimes[i] = executionTime;

		start = clock();
		tree2.Delete(p);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		DeletionTimes[i] = executionTime;

	}
	cout << "Average times for descending order (insertion, search and deletion):\n";
	cout << Average(InsertionTimes, 10) << endl;
	cout << Average(SearchingTimes, 10) << endl;
	cout << Average(DeletionTimes, 10) << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		array = RandomArrayGenerator(size);
		BST tree3(array, size);

		int number = Random(size);

		start = clock();
		tree3.Insert(number);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		InsertionTimes[i] = executionTime;

		start = clock();
		BST::node* p = tree3.Search(number);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		SearchingTimes[i] = executionTime;

		start = clock();
		tree3.Delete(p);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		DeletionTimes[i] = executionTime;

	}
	cout << "Average times for random order (insertion, search and deletion):\n";
	cout << Average(InsertionTimes, 10) << endl;
	cout << Average(SearchingTimes, 10) << endl;
	cout << Average(DeletionTimes, 10) << endl << endl;	
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

int* RandomArrayGenerator(int n)
{
	int* arr = new int[n];
	for (int i = 0; i < n; i++) arr[i] = (rand() % n);

	return arr;
}

int* AscendingArrayGenerator(int n)
{
	int* arr = new int[n];
	for (int i = 0; i < n; i++) arr[i] = i + 1;

	return arr;
}

int* DescendingArrayGenerator(int n)
{
	int* arr = new int[n];
	for (int i = 0; i < n; i++) arr[i] = n - i;

	return arr;
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

int Random(int min, int max)
{
	int range = max - min + 1;
	int num = rand() % range + min;
	return num;
}

double Average(double* A, int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++) sum += A[i];
	return sum / n;
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
		//cout << "Wrong Index!";
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
		//cout << "Wrong index";
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

BST::node* BST::Delete(node* p)
{
	node* q;

	if (p == nullptr) return nullptr;

	if (p->lchild == nullptr && p->rchild == nullptr)
	{
		if (p == root) root = nullptr;
		delete p;
		return nullptr;
	}
	else
	{
		if (Height(p->lchild) > Height(p->rchild))
		{
			q = Predecessor(p->lchild);
			p->data = q->data;
			p->lchild = Delete(p->lchild);
		}
		else
		{
			q = Successor(p->rchild);
			p->data = q->data;
			p->rchild = Delete(p->rchild);
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
