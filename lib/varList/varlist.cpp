#include "varlist.h"
#include "../variables/variable.h"
#include <iostream>
#include <string.h>
using namespace std;

varlist::varlist() {
	head = NULL;
}

varlist::~varlist() {
	cout << "Starting DELETING" << endl;
	while (head != NULL) {
		cout << "A" << flush;
		var* temp = head;
		cout << "B" << flush;
		head = head->next;
		cout << "C" << flush;
		//delete temp;
		cout << "D" << flush << endl;
	}
	cout << "DONE DELETING" << endl;
}

void varlist::add(variable* _store) {
	var* temp = new var;
	temp->next = NULL;
	temp->obj = _store;

	if (head == NULL) {
		head = temp;
		return;
	}

	var* trans = head;
	while (trans->next != NULL) {
		trans = trans->next;
	}

	trans->next = temp;
}

variable* varlist::find(string _name) {
	if (head == NULL) {
		return NULL;
	}

	var* trans = head;
	while (trans != NULL) {
		//cout << "A" << endl << flush;
		if (trans->obj->getName().compare(_name) == 0) {
			return trans->obj;
		}
		trans = trans->next;
	}

	return NULL;
}