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
			cout << "[VAR(A)]" << flush;
			if (next != NULL) {
				cout << "[VAR(B)]" << flush;	
				delete next;
			}
			if (obj != NULL) {
				cout << "[VAR(C)]" << flush;	
				delete obj;
			}
			cout << "[VAR(D)]" << flush;	
		}
		var* next;
		variable* obj;
	};

	var* head;
};

#endif