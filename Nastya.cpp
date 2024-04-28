//Кидай все сюда потом разберемся

//////////////////////main///////////////
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
  cout << endl;
  Queue B(A);
  B.print();
  cout << endl;
  Queue C;
  C=B;
  C.print();

  return 0;
}

////////////////////////////////////Man.h///////////////////////////////
#pragma once
#include <iostream>

class Man {
private:
  float value;
  Man* next;
public:
  void set_value(float new_value);
  float get_value();
  Man* get_next();
  void set_next(Man* new_next);

  Man();
  Man(int new_value);
  Man(int new_value, Man *new_next);
  
  Man(const Man &m);
  Man operator=(Man& right);
  
  ~Man();
};
//////////////////////////////////////Man.cpp//////////////////////////
#include "Man.h"

void Man::set_value(float new_value)
{
  value = new_value;
}

float Man::get_value()
{
  return value;
}

Man* Man::get_next()
{
  return next;
}

void Man::set_next(Man* new_next)
{
  next = new_next;
}

Man::Man()
{
  set_value(10);
  next = NULL;
}

Man::Man(int new_value)
{
  set_value(new_value);
  next = NULL;
}

Man::Man(int new_value, Man *new_next)
{
  set_value(new_value);
  next = new_next;
}

Man::Man(const Man &m)
{
    this->value=m.value;
    this->next=m.next;
}

Man::~Man() {}

Man Man::operator=(Man& right)
{
    this->value=right.value;
    this->next=right.next;
    return *this;
}
/////////////////////////////////////////////////Queue.h////////////////////////////////
#pragma once
#include <iostream>
#include "Man.h"

class Queue {
private:
  Man* head;
  Man* tail;
  int count;
public:

  void set_count(int new_count);
  int get_count();
  void set_head(Man *new_head);
  void set_tail(Man *new_tail);

  Man* get_head();
  Man* get_tail();

  void add_con(float value);

  void print();
  bool isEmpty();
  Queue();
  Queue(int count);
  Queue(const Queue &q);
  Queue operator=(Queue& right);
};
////////////////////////////////////////////Queue.cpp///////////////////////////////////
#include "Queue.h"
using namespace std;
Queue::Queue()
{
  set_count(0);
  head = NULL;
  tail = NULL;
}

Queue::Queue(const Queue &q)
{
    this->count=q.count;
    this->head=q.head;
    this->tail=q.tail;
}

void Queue::set_count(int new_count)
{
  count = new_count;
}

int Queue::get_count()
{
  return count;
}

void Queue::set_head(Man* new_head)
{
  head = new_head;
}

void Queue::set_tail(Man* new_tail)
{
  tail = new_tail;
}

Man* Queue::get_head()
{
  return head;
}

Man* Queue::get_tail()
{
  return tail;
}

void Queue::add_con(float value)
{
  Man* new_man = new Man(value);
  if (get_head() == NULL)
  {
    set_head(new_man);
  }
  else
  {
    get_tail()->set_next(new_man);
  }
  set_tail(new_man);
  count++;
}

void Queue::print()
{
  if (isEmpty())
  {
    cout << "очередь пуста";
  }
  else 
  {
    Man* temp = head;
    for (int i = 0; i < get_count(); i++)
    {
      cout << temp->get_value() << endl;
      temp = temp->get_next();
    }
  }
}

bool Queue::isEmpty()
{
  return (head==NULL);
}


Queue::Queue(int count)
{
  set_count(count);
}

Queue Queue::operator=(Queue& right)
{
    this->count=right.count;
    this->head=right.head;
    this->tail=right.tail;
    return *this;
}
