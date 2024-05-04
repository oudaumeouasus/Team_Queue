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
		A.add_con(i + 1);
	}
	for (int i = 0; i < n; i++)
	{
		A.add_con(i + 1);
	}
	cout << A;
	cout << endl;
	A.del_index(2);
	A.add_con(8);
	cout << A;
	A.tek_znach();
	cout<< A.del_info(4)<<endl;
	cout << A;
	A.tek_znach();
	A.inversion();
	cout << A;
	return 0;
}
