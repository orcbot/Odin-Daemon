
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/document.h"
#include <iostream>
using namespace rapidjson;
using namespace std;

class daemonWriter{
public:

	// Current 'master' function used to write to all members of a JSON DOM at once. Will be broken up into seperate writers/setters
	// for better functionality and modularity. Other arguments have been disabled for testing.
	void setAll(/*string name, bool save, int rank, int dimensions[], int dimensionsSize,*/ double values[], int valuesSize){
		Document d;
		StringBuffer s;
    	Writer<StringBuffer> writer(s);
 		writer.StartObject();  // write "{"
		writer.Key("name"); // write string "hello"
		writer.String("y");
		writer.Key("save"); 
		writer.Bool(false);   // write boolean value true
		writer.Key("rank");
		writer.Uint(7);
		writer.Key("dimensions");
		writer.StartArray();  // write "["
		for (unsigned i = 0; i < 2; i++)
		writer.Uint(i+1);
		writer.EndArray();   // End Array "]"
		writer.Key("values");
		writer.StartArray();  // write "["
		for (unsigned i = 0; i < valuesSize; i++)
		writer.Double((i+1)*(i+1)*3.13);
		writer.EndArray();   // End Array "]"
		writer.EndObject();  // end Object "}"
		d.Parse(s.GetString());
		s.Clear();   // clear the buffer to prepare for a new json document
 		writer.Reset(s);  // resetting writer for a fresh json doc
 		d.Accept(writer); // writing parsed document to buffer
 		//cout << "After Manupulation\n" << s.GetString() << endl;
 		puts(s.GetString());		//formatting for this looks pretty ugly at the moment. Needs investigation.

	};


private:
	

};