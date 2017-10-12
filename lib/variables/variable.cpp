#include "variable.h"
#include "../errors/variable_error.h"
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
	rapidjson::Document jsonDoc;
	char buffer[_json.length()];
    bzero(buffer,_json.length());

	_json.copy(buffer, _json.length());
	buffer[_json.length()] = '\0';

	jsonDoc.ParseInsitu(buffer).HasParseError();

  /*
    Ensures that JSON object has all the correct fields and
    ensures that all fields contain the correct data types.
    The rapidJSON will fail if we are expecting one data type
    and the JSON object holds another data.
  */

	if (!jsonDoc.IsObject()) {
    throw NotObjectError();
  }

	if (!jsonDoc.HasMember("name")) {
    throw NoNameError();
  }

	if (!jsonDoc.HasMember("save")) {
    throw NoSaveError();
  }

	if (!jsonDoc.HasMember("rank")) {
    throw NoRankError();
  }

	if (!jsonDoc.HasMember("dimensions")) {
    throw NoDimensionsError();
  }

  if (!jsonDoc.HasMember("values")) {
    throw NoValuesError();
  }

  if (!jsonDoc["name"].IsString()) {
    throw NameNotStringError();
  }

  if (!jsonDoc["save"].IsInt()) {
    throw SaveNotBoolError();
  }

  if (!jsonDoc["rank"].IsInt()) {
    throw RankNotInt();
  }

  if (!jsonDoc["dimensions"].IsArray()) {
    throw DimensionsNotArray();
  }

  if (!jsonDoc["values"].IsArray()) {
    throw ValuesNotArray();
  }

	name = jsonDoc["name"].GetString();
	rank = jsonDoc["rank"].GetInt();
	save = jsonDoc["save"].GetInt();
	rapidjson::Value& dimensionsArray = jsonDoc["dimensions"];
	rapidjson::Value& valueArray = jsonDoc["values"];

  if (rank <= 0) {
    throw Rank0Error();
  }

  if (rank != dimensionsArray.Size()) {
    throw DimensionsWrongSizeError();
  }

  dimensions = new int[rank];
   valuesLength = 1;

  for (int i = 0; i < rank; ++i) {
    dimensions[i] = dimensionsArray[i].GetInt();
    valuesLength *= dimensions[i];
  }

  if (valuesLength != valueArray.Size()) {
    throw ValuessWrongSizeError();
  }

	values = new double[valuesLength];

	for (int i = 0; i < valuesLength; ++i) {
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
	if (_pos >= rank || _pos < 0) {
		throw OutOfBounds();
	}

	return dimensions[_pos];
}

double variable::getValue(int _pos) {
	if (_pos >= valuesLength || _pos < 0) {
		throw OutOfBounds();
	}

	return values[_pos];
}

bool variable::getSave() {
	return save;
}

void variable::setName(string _name) {
  if (_name.length() == 0) {
    throw NoNameError();
  }

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

	convert << "{\"name\":\"" << name << "\", \"rank\":" << rank << ", \"save\":" << save << ", \"dimensions\": [";

	int length = 1;

	for (int i = 0; i < rank; ++i) {
		convert << dimensions[i];

		if (i < rank - 1) {
			convert << ", ";
		}

		length *= dimensions[i];
	}

	convert << "], \"values\": [";

	for (int i = 0; i < length; ++i) {
		convert << values[i];

		if (i < length - 1) {
			convert << ", ";
		}
	}

	convert << "]}";

	return convert.str();
}
