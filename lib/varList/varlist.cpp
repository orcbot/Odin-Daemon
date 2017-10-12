#include "varlist.h"
#include "../variables/variable.h"
#include "../errors/varlist_error.h"
#include <iostream>
#include <string.h>
using namespace std;

varlist::varlist() {
	head = NULL;
}

varlist::~varlist() {
  if (head == NULL) {
    return;
  }

	var *nodePtr;
	var *nextNode;
	nodePtr = head;

	while (nodePtr == NULL) {
		nextNode = nodePtr->next;

		delete nodePtr;

		nodePtr = nextNode;
	}
}

void varlist::add(variable* _store) {
  if (_store == NULL) {
    throw VariableNotDefinedError();
  }

	var* temp = new var;
	temp->next = NULL;
	temp->obj = _store;

	if (head == NULL) {
		head = temp;
		return;
	} else if (head->obj->getName().compare(_store->getName()) == 0) {
    throw VariableAlreadyExistsError();
  }

	var* trans = head;
	while (trans->next != NULL) {
		trans = trans->next;
    if (trans->obj->getName().compare(_store->getName()) == 0) {
      throw VariableAlreadyExistsError();
    }
	}

  trans->next = temp;
}

variable* varlist::find(string _name) {
	if (head == NULL) {
		throw VariableNotFoundError();
	}

	var* trans = head;
	while (trans != NULL) {
		if (trans->obj->getName().compare(_name) == 0) {
			return trans->obj;
		}
		trans = trans->next;
	}

	throw VariableNotFoundError();
}

int varlist::count() {
  int count = 0;

  if (head == NULL) {
    return count;
  }

  var* trans = head;

  while (trans != NULL) {
    ++count;
    trans = trans->next;
  }

  return count;
}

void varlist::reset() {
  if (head == NULL) {
    return;
  }

  var *prev;
  var *curr;
  curr = head;

  while (curr != NULL) {
    if (curr->obj->getSave() == true) {
      prev = curr;
      curr = curr->next;
    } else {
      if (curr == head) {
        prev = curr;
        curr = curr->next;
        head = curr;
        delete prev;
        prev = NULL;
      } else {
        var *deleteNode = curr;
        prev->next = curr->next;

        curr = curr->next;
        delete deleteNode;
      }
    }
  }
}

void varlist::fullReset() {
  if (head == NULL) {
    return;
  }

  var *nodePtr;
  var *nextNode;
  nodePtr = head;

  while (nodePtr == NULL) {
    nextNode = nodePtr->next;

    delete nodePtr;

    nodePtr = nextNode;
  }

  head = NULL;
}
