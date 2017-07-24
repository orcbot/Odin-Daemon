#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/document.h"
#include "daemonReader.cpp"
#include "daemonWriter.cpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
 
using namespace rapidjson;
using namespace std;
 
//File used to test functionality of JSON Parser. Is run without arguments as ./daemonTest
 
int main() {
	char json[] = " { \"name\" : \"x\", \"save\" : true , \"rank\" : 1, \"dimensions\":[4, 7], \"values\":[15, 23, 48, 29, 101, 103.5123] } ";
	printf("Original JSON:\n %s\n", json);
	size_t jsonSize = sizeof(json);
	daemonReader dR;
	dR.readJSON(json, jsonSize);
	string test;
	test = dR.getName(json, jsonSize);
	printf("name = %s\n", test.c_str());
    daemonWriter dW;
    double testDoubles[5];
    for(int i = 0; i < 5; i++){
    	testDoubles[i] = 2*3.13*i;
    }
    size_t doubleSize = sizeof(testDoubles);
	dW.setAll(testDoubles, doubleSize);
	
}