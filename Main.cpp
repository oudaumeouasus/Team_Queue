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
  A.tek_znach();
  cout << A << endl;
  //A.del_znach(2);
  A.add_con(8);
  cout << A;
  A.tek_znach();
  
  //if(A.del_info(4))
  //  {}
  //else
  //  cout << "Такого элемента нет"<<endl;
    
  //cout << A;
  //A.tek_znach();
  
  Queue B(A);
  cout << "B" << B;
  B.tek_znach();
  cout << B;
  Queue C=B;
  A.del_all();
  C.tek_znach();
  cout<<C;
  return 0;
}
