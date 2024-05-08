#include <iostream>
#include "Man.h"
using namespace std;
#pragma once
class Queue {
  friend std::ostream& operator<<(std::ostream& output, Queue& q);//перегрузка вывода

private:
  Man* head;//голова
  Man* tail;//хвост
  int count;//количество в очереди
public:
  void set_count(int new_count);//изменение количества
  void set_head(Man *new_head);//изменение головы
  void set_tail(Man *new_tail);//изменение хвоста

  int get_count() const;//получение значения количества
  Man* get_head() const;//получение значения головы
  Man* get_tail() const;//получение значения хвоста

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
  void del_copy();//удаление дубликатов
  Queue& operator=(const Queue& right);//перегрузка приравнивания
  bool isEmpty() const;//проверка на пустоту
  Queue();//конструктор без параметров
  Queue(int count);//конструктор с параметром количества
  Queue(const Queue& init);//конструктор копии
  ~Queue();//деструктор
  void print();//функция вывода

  float& operator[](const int index);//перегрузка индексации
};
