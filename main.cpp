#include <iostream>
#include "Queue.h"
#include "Man.h"

using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	Queue A;
	int n;
	cout << "Количество: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		A.add_con(i+1);
	}

	A.print();

	return 0;
}
