#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Display(int* A, int n);
void GetData(string nazwa);
int* Insert(int* A, int len, int x, int indX);

int main()
{
	string nazwa;
	cout << "Wybierz plik: ";
	cin >> nazwa;
	nazwa = "dane.txt";

	GetData(nazwa);
}

void Display(int* A, int n)
{
	cout << "[ ";
	for (int i = 0; i < n; i++)
	{
		cout << A[i];
		if (i < n - 1) cout << ", ";
	}
	cout << " ]" << endl;
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
