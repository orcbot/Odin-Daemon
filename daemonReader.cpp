
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/document.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace rapidjson;
using namespace std;

/*
	Main usage: call on a object to assign values to it of parts of the json string.
	@TODO: Needs to be split into seperate getters. Need to resolve issue of Document object permanance.
*/

class daemonReader {
public:
	Document jsonDoc;
	string test;
	daemonReader(){

	};
	void readJSON(char json[], int size){
		//Document jsonDoc;
		
        //#if 0
		    // "normal" parsing, decode strings to new buffers. Can use other input stream via ParseStream().
		    //if (document.Parse(json).HasParseError())
		        //return 1;
		//#else
		    // In-situ parsing, decode strings directly in the source string. Source must be string.
		    char buffer[size];
			memcpy(buffer, json, size);
			jsonDoc.ParseInsitu(buffer).HasParseError();
        		
		//#endif

        printf("\nParsing to jsonDoc succeeded.\n");
        printf("\nAccess values in jsonDoc:\n");
        //Assert is used to ensure that the object has such a member or that a member is of a certain datatype. Returns an error if assertion fails.
	    assert(jsonDoc.IsObject());    // jsonDoc is a JSON value represents the root of DOM. Root can be either an object or array.

	    assert(jsonDoc.HasMember("name"));
	    assert(jsonDoc["name"].IsString());
	    printf("name = %s\n", jsonDoc["name"].GetString());


	    assert(jsonDoc["save"].IsBool());     // JSON true/false are bool. Can also uses more specific function IsTrue().
    	printf("save = %s\n", jsonDoc["save"].GetBool() ? "true" : "false");

    	assert(jsonDoc["rank"].IsNumber());   // Number is a JSON type, but C++ needs more specific type.			<-Use this first.
	    assert(jsonDoc["rank"].IsInt());      // In this case, IsUint()/IsInt64()/IsUInt64() also return true.		<-Then use this.
	    printf("rank = %d\n", jsonDoc["rank"].GetInt()); // Alternative (int)document["rank"]

	    {
	        const Value& dimensionsArray = jsonDoc["dimensions"]; // Using a reference for consecutive access is handy and faster.
	        assert(dimensionsArray.IsArray());
	        for (SizeType i = 0; i < dimensionsArray.Size(); i++) // rapidjson uses SizeType instead of size_t.
	            printf("dimensionsArray[%d] = %d\n", i, dimensionsArray[i].GetInt());
	        
	        int y = dimensionsArray[0].GetInt();
	        (void)y;

	        // Iterating array with iterators
	        /*printf("array = ");
	        for (Value::ConstValueIterator itr = array.Begin(); itr != array.End(); ++itr)
	            printf("%d ", itr->GetInt());
	        printf("\n");*/
    	}
    	{
	        const Value& valuesArray = jsonDoc["values"]; // Using a reference for consecutive access is handy and faster.
	        assert(valuesArray.IsArray());
	        for (SizeType i = 0; i < valuesArray.Size(); i++) // rapidjson uses SizeType instead of size_t.
	            printf("valuesArray[%d] = %f\n", i, valuesArray[i].GetDouble());
	        
	        int y = valuesArray[0].GetInt();
	        (void)y;

	        // Iterating array with iterators
	        /*printf("array = ");
	        for (Value::ConstValueIterator itr = array.Begin(); itr != array.End(); ++itr)
	            printf("%d ", itr->GetInt());
	        printf("\n");*/
    	}
    	return;





	};
	const char *getName(char json[], int size){
		char buffer[size];
		memcpy(buffer, json, size);
		jsonDoc.ParseInsitu(buffer).HasParseError();
		assert(jsonDoc.IsObject());
		assert(jsonDoc.HasMember("name"));
		//printf("name = %s\n", jsonDoc["name"].GetString());
		test = jsonDoc["name"].GetString();
		printf("%s\n", test.c_str());
		return test.c_str();
	}


private:
};