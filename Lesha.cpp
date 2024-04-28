#include "Queue.h"
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
