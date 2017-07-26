#ifndef VARLIST_H
#define VARLIST_H

#include "../variables/variable.h"
#include <iostream>
#include <string.h>
using namespace std;

class varlist {
public:
	varlist();
	~varlist();
	void add(variable*);
	variable* find(string);
private:
	class var {
	public:
		var() { next = NULL; obj = NULL; }
		~var() { 
			if (next != NULL) {
				delete next;
			}
			if (obj != NULL) {
				delete obj;
			}
		}
		var* next;
		variable* obj;
	};

	var* head;
};

#endif