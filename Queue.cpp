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
    while(temp!=NULL)//идём по всей очереди(из которой копируем), пока не доходи до конца (temp!=NULL)
    {
        add_con(temp->get_value());//в очередь, с которой работаем добавляем в конец значение из текущего элемента(temp)
        temp = temp->get_next();//переходим к следующему элементу очереди из которой копируем
    }
}

Queue& Queue::operator=(const Queue& right)
{
    del_all();//удаляем всё из очереди с которой работаем
    Man* temp = right.get_head();//присваиваем в temp голову из очереди right(мы из неё копируем)
    for(int i=0; i<right.get_count(); i++)//идём по всему количеству элементов 
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
    head = new Man(value, head);//голове присваиваем новый элемент, который создается с параметрами(новое значение и следующий элемент голова очереди, с которой работаем)
    count++;//количество увеличивается на 1
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
    while (count!=0)//пока количество элементов в очереди с которой работает не равно 0
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


        if (index == count-1)
        {
            Man* new_tail = this->head;
            for (int i = 0; i < count-2; i++)
            {
                new_tail = new_tail->get_next();
            }
            tail = new_tail;
        }
        delete toDel;

        count--;
    }

}

void Queue::del_znach(float znach)
{
    Man* temp = this->head;
    int delcount = 0;
    for (int i = 0; i < count; i++)
    {
        if (temp->get_value() == znach)
        {
            cout << "Удалено" <<temp->get_value()<<endl;
            temp = temp->get_next();
            this->del_index(i - delcount);
            delcount++;
        }
        else
        {
            temp = temp->get_next();
        }

    }
}

float Queue::del_info(float znach)
{
    Man* temp = head;
    int proverka = 0;
    for (int i = 0; i < count; i++)
    {
        if(temp->get_value()==znach)
        {
            proverka++;
        }
        temp = temp->get_next();

    }

    if (proverka > 0)
    {
        del_znach(znach);
        return znach;
    }
    else
    {
        return 0;
    }
}

void Queue::change(float old_value, float new_value)
{
    Man* temp = this->head;
    for (int i = 0; i < count; i++)
    {
        if (temp->get_value() == old_value)
        {
            temp->set_value(new_value);
        }
        temp = temp->get_next();
    }
}

void Queue::tek_znach()//текущее значение
{
    cout << "Размер " << count << " Значение головы " << head->get_value() << " Значенние хвоста " << tail->get_value()<<endl;//вывод 
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

std::ostream& operator<<(std::ostream& output, Queue& q)
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
void Queue::del_copy()
{
    Man* current_ptr = this->get_head();

    while (current_ptr != nullptr)
    {
        float current_value = current_ptr->get_value();//текущее значение
        Man* temp_ptr = current_ptr->get_next();//следующая
        Man* prev_ptr = current_ptr;//теккущее
        cout<< current_value << endl;//текущее значение
        cout<< prev_ptr->get_value() << endl;//текущее значение
        cout<< temp_ptr->get_value() << endl;//следующее значение
        while (temp_ptr != nullptr)
        {
            if (temp_ptr->get_value() == current_value)
            {
                Man* duplicate_node = temp_ptr;
                temp_ptr = temp_ptr->get_next();
                prev_ptr->set_next(temp_ptr);
                cout << "Съебавшись" <<(duplicate_node->get_value()) << endl;
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
    Man* tmp_tail =  this->get_head();//создаем указатель на голову
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
