#pragma once
#include <iostream>

class Man {
private:
	float value;
	Man* next;
public:
	
	float get_value();
	Man* get_next();

	void set_next(Man* new_next);
	void set_value(float new_value);

	Man();
	Man(float new_value, Man* new_next = NULL);
	~Man();

};
