#include "Queue.h"
#include "Man.h"
using namespace std;
Queue::Queue()
{
    set_count(0);
    head = NULL;
    tail = NULL;
}

Queue::Queue(const Queue& init)//конструктор копии
{
    Man* temp = init.head;//в temp присваиваем голову init
    while (temp != NULL)//идём по всей очереди(из которой копируем), пока не доходи до конца (temp!=NULL)
    {
        add_con(temp->get_value());//в очередь, с которой работаем добавляем в конец значение из текущего элемента(temp)
        temp = temp->get_next();//переходим к следующему элементу очереди из которой копируем
    }
}

Queue& Queue::operator=(const Queue& right)
{
    del_all();//удаляем всё из очереди с которой работаем
    Man* temp = right.get_head();//присваиваем в temp голову из очереди right(мы из неё копируем)
    for (int i = 0; i < right.get_count(); i++)//идём по всему количеству элементов 
    {
        add_con(temp->get_value());//в очередь, с которой работаем добавляем в конец значение из текущего элемента(temp)
        temp = temp->get_next();////переходим к следующему элементу очереди из которой копируем
    }
    return *this;//возвращаем заполненную очередь
}

void Queue::set_count(int new_count)
{
    count = new_count;
}

int Queue::get_count() const
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

Man* Queue::get_head() const
{
    return head;
}

Man* Queue::get_tail() const
{
    return tail;
}

void Queue::add_con(float value)//добавление в конец значение, которое передали
{
    Man* new_man = new Man(value);//создаем новый элемент очереди с переданным значением(в next присваивается NULL) 
    if (get_head() == NULL)//если очередь, с которой работаем пуста
    {
        set_head(new_man);//делаем новый элемент головой
    }
    else
    {
        get_tail()->set_next(new_man);//у последнего элемента меняем NULL на новый элемент
    }
    set_tail(new_man);//теперь новый элемент - хвост
    count++;//количество элементов увеличилось на 1
}

void Queue::add_nach(float value)//добавление в начало
{
    if (count == 1)//если в очереди был только один элемент
    {
        tail = head;//хвост равен глолове
    }
    head = new Man(value, head);//голове присваиваем новый элемент, который создается с параметрами(новое значение и следующий элемент голова очереди, с которой работаем)
    count++;//количество увеличивается на 1
    if (count == 1)//если в очереди был только один элемент
    {
        tail = head;//хвост равен глолове
    }

}

void Queue::del_head()//удаление головы
{
    Man* temp = head;//указатель temp указывает туда же, куда и голова
    head = head->get_next();//меняем голову на следующий после головы элемент
    delete temp;//удаляем значения (то что хранится по указателю temp(head))
    count--;//уменьшение количества
}

void Queue::del_all()//удаление всего
{
    while (count != 0)//пока количество элементов в очереди с которой работает не равно 0
    {
        del_head();//удаляем головы
    }
}

void Queue::del_index(int index)
{

    if (index >= count)
    {
        return;
    }

    if (index == 0)
    {
        if (head->get_next() == NULL)
            tail = head;
        del_head();
    }

    else
    {
        Man* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->get_next();
        }
        Man* toDel = previous->get_next();
        previous->set_next(toDel->get_next());


        if (index == count - 1)
        {
            Man* new_tail = this->head;
            for (int i = 0; i < count - 2; i++)
            {
                new_tail = new_tail->get_next();
            }
            tail = new_tail;
        }
        delete toDel;

        count--;
    }

}

void Queue::del_znach(float znach)//удаление значения
{
    int temp_count = count;//запоминаем размер(нужно для индексации)
    Man* temp = this->head;//создаем указатель на глову
    int del_count = 0;//количесво удаленных элементов(нужно для индексации)
    for (int i = 0; i < temp_count; i++)//идём по всей очереди(доходя до каждого элемента)
    {
        if (temp->get_value() == znach)//если значение элемента совпало со значением удаления
        {
            cout << "Удалено" << znach << endl;//вывод на экран удаления
            temp = temp->get_next();//переход к следующему
            this->del_index(i - del_count);//удаление по индексу
            del_count++;//количество удаленных +1
        }
        else//если значение не совпало
        {
            temp = temp->get_next();//переходим к следующему
        }

    }
}

float Queue::del_info(float znach)//удаление с выводом
{
    Man* temp = head;//указатель на голову
    bool proverka = false;//для проверки, есть ли значение в очереди
    for (int i = 0; i < count; i++)//по всей очереди
    {
        if (temp->get_value() == znach)//если значения совпали
        {
            proverka = true;//увеличиваем
            break;//выход из for
        }
        temp = temp->get_next();//переход к следующему элементу

    }

    if (proverka)//если стало true
    {
        del_znach(znach);//удаляем
        return znach;//возвращение удаленного значения
    }
    else
    {
        return 0;//возвращение 0
    }
}

void Queue::change(float old_value, float new_value)//замена(получение чего менять на что менять)
{
    Man* temp = this->head;//указатель на голову
    for (int i = 0; i < count; i++)//по всей очереди
    {
        if (temp->get_value() == old_value)//если значение того, что нужно поменять совпало со значнием элемента очереди
        {
            temp->set_value(new_value);//меняем значение элемента на новое
        }
        temp = temp->get_next();//переходим к следующему
    }
}

void Queue::tek_znach()//текущее значение
{
    if (!isEmpty())//если не пустая
        cout << "Размер " << count << " Значение головы " << head->get_value() << " Значенние хвоста " << tail->get_value() << endl;//вывод 

    else//если пустая
        cout << "Очередь пуста";
}

bool Queue::isEmpty() const//проверка, пуста ли очередь
{
    return (head == NULL);//если указатель головы ни на что не ууказывает - очердь пуста
}



Queue::Queue(int count)
{
    set_count(count);
}

Queue::~Queue()//перегруженный деструктор
{
    cout << endl << "del" << endl;//вывод del
    del_all();//очищение всей очереди
}

float& Queue::operator[](const int index)
{
    Man* current = this->head;
    int counter = 0;

    while (current != NULL)
    {
        if (counter == index)
        {
            float* b = new float(current->get_value());
            float& result = *b;
            delete b;

            return result;
        }
        current = current->get_next();
        counter++;
    }
    // В случае, если индекс не найден, можно вернуть ссылку на статическую переменную или бросить исключение
    static float error_value = 0.0f;
    return error_value;
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

void Queue::sort()//сортировка
{
    int a = count;//запоминаем значение count
    float* list = new float[a];//создаем массив, выделяя место под наши элементы очереди
    Man* temp = head;//указатель на голову

    for (int i=0; i < a; i++)//проходим по всем элементам
    {
        list[i] = temp->get_value();//записываем значение элемента в список
        temp = temp->get_next();//переходим к следующему элементу
    }

    del_all();//чистим очередь с которой работаем

    //сортировка вставками
    for (int i = 1; i < a; i++) {//идем со второго элемента до конца
        float key = list[i];//записываем текущий элемент в key
        int j = i - 1;//индекс для предыдущего элемента
        while (j >= 0 && list[j] > key) {//пока не доши до начала и текущий(key) элемент меньше того, до которого дошли с помощью индекса
            list[j + 1] = list[j];//двигаем предыдущий элемент вперед
            j = j - 1;//уменьшаем индекс чтобы перейти к следующему элементу
        }
        list[j + 1] = key;//ставим key(текущий элемент) на своё место
    }

    for(int i = 0; i < a; i++) 
    {
        this->add_con(list[i]);//все элементы списка добавляем в очередь
    }
    delete[] list;//очищение памяти, выделенной под массив
}

ostream& operator<<(ostream& output, Queue& q)
{
    if (q.isEmpty())
    {
        cout << "очередь пуста ";
        return output;
    }
    else
    {
        Man* temp = q.head;
        for (int i = 0; i < q.count; i++)
        {
            cout << temp->get_value() << "->";
            temp = temp->get_next();
        }
        cout << "NULL" << endl;
        return output;
    }
}
istream& operator>>(istream& input, Queue& q)//перегрузка ввода
{
    float value; //переменная для вводимого значения
    cout << "Введите, какое значение вы хотите добавить: ";
    input >> value; //вводим это значение
    Man* newPtr = new Man(value); //выделяем память на новую ячейку списка, вызываем конструктор с параметрами, чтобы положить значение value в value класса Man
        if (newPtr != NULL) //проверяем выделилась ли память
        {
            if (q.isEmpty()) //проверка «пустая ли очередь»
            {
                q.head = newPtr; //присваивание указателю на голову очереди указателя на созданную ячейку
            }
            else // если очередь не пустая 
            {
                q.tail->set_next(newPtr);//последний элемент очереди указывает на созданный 
            }
            q.tail = newPtr; //созданный элемент теперь новый последний
        }
        else //если память не выделилась 
        {
            cout << value << "не добавлен. Память не выделилась." << endl;
        }
    return input; //возвращаем input чтобы можно было вводить подряд cin >> q >> t >> … >> … ;
}

void Queue::del_copy()
{
    Man* current_ptr = this->get_head();

    while (current_ptr != nullptr)
    {
        float current_value = current_ptr->get_value();//текущее значение
        Man* temp_ptr = current_ptr->get_next();//следующая
        Man* prev_ptr = current_ptr;//теккущее
        cout << current_value << endl;//текущее значение
        cout << prev_ptr->get_value() << endl;//текущее значение
        cout << temp_ptr->get_value() << endl;//следующее значение
        while (temp_ptr != nullptr)
        {
            if (temp_ptr->get_value() == current_value)
            {
                Man* duplicate_node = temp_ptr;
                temp_ptr = temp_ptr->get_next();
                prev_ptr->set_next(temp_ptr);
                cout << "Съебавшись" << (duplicate_node->get_value()) << endl;
                delete duplicate_node;
            }
            else
            {
                temp_ptr = temp_ptr->get_next();
            }
        }
        current_ptr = current_ptr->get_next();
    }
}


void Queue::inversion()//инвертирование
{
    Man* tmp_tail = this->get_head();//создаем указатель на голову
    Man* prev_ptr = NULL;//указатель на предыдущий элемент
    Man* current_ptr = this->get_head();//создаем указатель на текущий элемент, который равен голове
    Man* next_ptr = NULL;//указатель на следующий элемент(он равен NULL)

    while (current_ptr != NULL)//пока текущий не равен NULL, идйм по всей очереди
    {
        next_ptr = current_ptr->get_next();
        current_ptr->set_next(prev_ptr);
        prev_ptr = current_ptr;
        current_ptr = next_ptr;
    }

    this->set_head(prev_ptr);
    this->set_tail(tmp_tail);

}
