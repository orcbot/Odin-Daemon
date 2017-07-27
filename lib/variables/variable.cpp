#include "variable.h"
#include "../rapidjson/stringbuffer.h"
#include "../rapidjson/prettywriter.h"
#include "../rapidjson/document.h"
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

variable::variable() {
	rank = 0;
	dimensions = NULL;
	values = NULL;
	save = false;
}

variable::variable(string _json) {
	//cout << "String " << _json << " Length " << _json.length() << endl;

	//_json.append('\0');
	rapidjson::Document jsonDoc;
	char buffer[_json.length()];
    bzero(buffer,_json.length());

	_json.copy(buffer, _json.length());
	buffer[_json.length()] = '\0';
	//cout << buffer << endl;

	jsonDoc.ParseInsitu(buffer).HasParseError();


	assert(jsonDoc.IsObject());
	assert(jsonDoc.HasMember("name"));
	assert(jsonDoc.HasMember("save"));
	assert(jsonDoc.HasMember("values"));
	assert(jsonDoc.HasMember("rank"));
	assert(jsonDoc.HasMember("dimensions"));

	name = jsonDoc["name"].GetString();
	rank = jsonDoc["rank"].GetInt();
	//save = jsonDoc["save"].GetBool() ? "true" : "false";
	save = 0;

	rapidjson::Value& dimensionsArray = jsonDoc["dimensions"];
	assert(dimensionsArray.IsArray());
	dimensions = new int[rank];
	//calculatiung length of values array up here to avoid using two loops
	int length = 1;

	for (int i = 0; i < rank; ++i) {
		dimensions[i] = dimensionsArray[i].GetInt();
		length *= dimensions[i];
	}

	cout << "Length " << length << endl;

	rapidjson::Value& valueArray = jsonDoc["values"];
	assert(valueArray.IsArray());
	values = new double[length];

	for (int i = 0; i < length; ++i) {
		values[i] = valueArray[i].GetDouble();
	}
}

variable::~variable() {
	delete dimensions;
	delete values;
}

string variable::getName() {
	return name;
}

int variable::getRank() {
	return rank;
}

int variable::getDimension(int _pos) {
	if (_pos >= rank) {
		return -1;
	}

	return dimensions[_pos];
}

double variable::getValue(int _pos) {
	int size = 1;
	for (int i = 0; i < rank; ++i) {
		size = size * dimensions[i];
	}

	if (_pos >= size) {
		throw string("Oh shit this was a mistake");
	}

	return values[_pos];
}

bool variable::getSave() {
	return save;
}

void variable::setName(string _name) {
	name = _name;
}

void variable::setRank(int _rank) {
	rank = _rank;
}

void variable::setDimensions(int _dimensions[]) {
	if (dimensions != NULL) {
		delete dimensions;
	}

	dimensions = new int[rank];
	for (int i = 0; i < rank; ++i) {
		dimensions[i] = _dimensions[i];
	}
}

void variable::setValues(double _values[]) {
	if (values != NULL) {
		delete values;
	}

	int length = 1;
	for (int i = 0; i < rank; ++i) {
		length *= dimensions[i];
	}

	values = new double[length];
	
	for (int i = 0; i < length; ++i) {
		//cout << "CREATING " << i << " " << _values[i] << endl;
		values[i] = _values[i];
	}
}

void variable::setSave(bool _save) {
	save = _save;
}

void variable::printVar() {
	cout << name << " " << rank << endl;
}

string variable::toJSON() {
	ostringstream convert;

	convert << "{'name':'" << name << "', 'rank':" << rank << ", 'save':" << save << ", 'dimensions': [";

	int length = 1;

	for (int i = 0; i < rank; ++i) {
		convert << dimensions[i];

		if (i < rank - 1) {
			convert << ", ";
		}

		length *= dimensions[i];
	}

	convert << "], 'values': [";

	for (int i = 0; i < length; ++i) {
		convert << values[i];

		if (i < length - 1) {
			convert << ", ";
		}
	}

	convert << "]}";

	return convert.str();
}