#include <iostream>
#include "Man.h"
using namespace std;
#pragma once
class Queue {
	friend std::ostream& operator<<(std::ostream& output, Queue& q);
	
private:
	Man* head;
	Man* tail;
	int count;
public:
	void set_count(int new_count);
	void set_head(Man *new_head);
	void set_tail(Man *new_tail);

	int get_count() const;
	Man* get_head() const;
	Man* get_tail() const;

	void add_con(float value);//добавление в конец
	void add_nach(float value);//добавление в начало
	void del_head();//удаление первого элемента(головы)
	void del_all();//удаление всей очереди
	void del_index(int index);//удаление элемета по индексу
	void del_znach(float znach);//удаление значения по значению
	float del_info(float znach);//удаление с выводом значения
	void change(float old, float new_value);//замена элемента
	void tek_znach();//узнать текущее значение 
	void inversion();//инвертирование
	

	bool isEmpty() const;
	Queue();
	Queue(int count);
	~Queue();
	void print();

	float& operator[](const int index);
};
