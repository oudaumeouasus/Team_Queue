#include "Queue.h"
#include "Man.h"
using namespace std;
Queue::Queue()
{
    set_count(0);
    head = NULL;
    tail = NULL;
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

void Queue::add_con(float value)
{
    Man* new_man = new Man(value);
    if (get_head() == NULL)
    {
        set_head(new_man);
        tail = head;
    }
    else
    {
        get_tail()->set_next(new_man);
        tail = new_man;
    }
    set_tail(new_man);
    count++;
}

void Queue::add_nach(float value)
{
    head = new Man(value, head);
    count++;
}

void Queue::del_head()
{
    Man* temp = head;
    head = head->get_next();
    delete temp;
    count--;
}

void Queue::del_all()
{
    while (count!=0)
    {
        del_head();
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
    int a = count;
    Man* temp = this->head;
    int delcount = 0;
    for (int i = 0; i < a; i++)
    {
        if (temp->get_value() == znach)
        {
            cout << "Удалено" <<temp->get_value()<<endl;
            temp = temp->get_next();
            this->del_index(i - delcount);
            delcount++;
            a--;
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
    //cout << endl<<proverka<<endl;
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

void Queue::tek_znach()
{
    cout << "Размер " << count << " Значение головы " << head->get_value() << " Значенние хвоста " << tail->get_value()<<endl;
}

bool Queue::isEmpty() const
{
    return (head == NULL);
}



Queue::Queue(int count)
{
    set_count(count);
}

Queue::~Queue()
{
    cout << endl << "del" << endl;
    del_all();
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
        float current_value = current_ptr->get_value();
        Man* temp_ptr = current_ptr->get_next();
        Man* prev_ptr = current_ptr;
        cout<< current_value << endl;
        cout<< prev_ptr->get_value() << endl;
        cout<< temp_ptr->get_value() << endl;
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
                prev_ptr = temp_ptr;
                temp_ptr = temp_ptr->get_next();
            }
        }

        current_ptr = current_ptr->get_next();
    }
}


void Queue::inversion()
{
    Man* prev_ptr = nullptr;
    Man* current_ptr = this->get_head();
    Man* next_ptr = nullptr;

    while (current_ptr != nullptr)
    {
        next_ptr = current_ptr->get_next();
        current_ptr->set_next(prev_ptr);
        prev_ptr = current_ptr;
        current_ptr = next_ptr;
    }

    this->set_head(prev_ptr);
}
