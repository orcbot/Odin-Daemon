//@todo add better comments
#include "lib/calculations/add.h"
#include "lib/calculations/dot.h"
#include "lib/calculations/sub.h"
#include "lib/calculations/mult.h"
#include "lib/helper/config.h"
#include "lib/variables/variable.h"
#include "lib/varList/varlist.h"
#include "lib/errors/error.h"
#include "lib/errors/variable_error.h"
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

void processRequests(int);
void output(string, string, bool);
void errorHandler(error*, int);
bool debug = false;

int main(int argc, char const *argv[])
{
	//Will wait for a concention, then fork off and call new function to handle requests
	//Calls to function to read the requests and respond
    output("Init", "Odin-daemon starting up...", false);

    config settings;

    for (int i = 1; i < argc; ++i)
    {
        /**
        *Current options
        *   p <int> (Change the default port)
        *   d (Run in detached mode)
        *   s (Silent mode, won't print updates)
        *   help (Get help)
        **/
        if (strcmp(argv[i], "p") == 0) {
            if (argc > i + 1)
            {
                int port = atoi(argv[i+1]);
                settings.setPort(port);
                if (port == 0)
                {
                    cout << "Ussage: Odin p <int>" << endl;
                    exit(1);
                }
            } else {
                cout << "Ussage: Odin p <int>" << endl;
                exit(1);
            }
        } else if (strcmp(argv[i], "d") == 0) {
            cout << "Running in detached mode" << endl;
        }  else if (strcmp(argv[i], "s") == 0) {
            settings.setSilent(true);
        } else if (strcmp(argv[i], "debug") == 0) {
            debug = true;
        } else if (strcmp(argv[i], "help") == 0) {
            cout << "Printing out help screen" << endl;
        }
    }

    output("Init", "Configuration set up", settings.getSilent());
    output("Init", "Port is set to " + to_string(settings.getPort()), settings.getSilent());
    //This whole section could be redone to make it better but for now it will do
    int sockfd;
    int newsockfd;
    int portno;

    socklen_t clilen;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;

    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        output("FATAL ERROR", "Error opening socket", false);
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(settings.getPort());

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        output("FATAL ERROR", "Error on binding socket, please make sure the socket is free", false);
        exit(1);
    }

    output("Init", "Binded port successfully...", settings.getSilent());
    output("Listen", "Waiting connections...", settings.getSilent());

    while (true) {
	    listen(sockfd, 5);
	    clilen = sizeof(cli_addr);
	    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	    string addressMessage = inet_ntoa(cli_addr.sin_addr);
	    if (newsockfd < 0) {
	        output("FATAL ERROR", "Error on accept", false);
	    }
	    output("Listen", "Connection recieved from " + addressMessage, settings.getSilent());

	    output("Listen", "Splitting processes...", settings.getSilent());
	    int pid = fork();

	    if (pid == 0) {
	    	//Child process
	    	processRequests(newsockfd);
	    } else if (pid > 0) {
	    	//Parent Process
	    	//Does nothing just goes back to listening
	    } else {
	    	//fork failed fr some reason
	    	output("Listen", "fork() has failed for some reason....", settings.getSilent());
	    }

	}

    close(sockfd);

	return 0;
}

/**
*   Method which will be called for each new connection. This
*   method will keep reading instructions, processing the instructions
*   and returning a result, until such time as it is told to close
*   the connection.
**/

void processRequests(int id) {
	//Will read the requests
	//handle them
	//responds
    char buffer[2048];

    while (strcmp("QUIT", buffer) != 0) {
        output("DEBUG", "Start of while loop", !debug);
        varlist list;
        bzero(buffer,2048);
        int n = read(id,buffer,2047);
        bool noErrors = true;
        if (n < 0) {
            output("ERROR", "ERROR reading from socket", false);
            output("ProcessRequest", "Closing Connection", false);
            close(id);
            exit(0);
        }

        string message(buffer);
        cout << message;

        // get the variables out
        int pos = message.find('}');
        while(pos > 0 && noErrors) {
            string object = message.substr(0, pos+1);
            variable *temp;
            try {
              temp = new variable(object);
            } catch (NotObjectError e) {
                errorHandler(&e, id);
                noErrors = false;
            } catch (NoNameError e) {
                errorHandler(&e, id);
                noErrors = false;
            } catch (NoSaveError e) {
                errorHandler(&e, id);
                noErrors = false;
            } catch (NoValuesError e) {
                errorHandler(&e, id);
                noErrors = false;
            } catch (NoRankError e) {
                errorHandler(&e, id);
                noErrors = false;
            } catch (NoDimensionsError e) {
                errorHandler(&e, id);
                noErrors = false;
            } catch (NameNotStringError e) {
                errorHandler(&e, id);
                noErrors = false;
            } catch (SaveNotBoolError e) {
                errorHandler(&e, id);
                noErrors = false;
            } catch (RankNotInt e) {
                errorHandler(&e, id);
                noErrors = false;
            } catch (DimensionsNotArray e) {
                errorHandler(&e, id);
                noErrors = false;
            } catch (ValuesNotArray e) {
                errorHandler(&e, id);
                noErrors = false;
            } catch (DimensionsWrongSizeError e) {
                errorHandler(&e, id);
                noErrors = false;
            } catch (ValuessWrongSizeError e) {
                errorHandler(&e, id);
                noErrors = false;
            } catch (Rank0Error e) {
                errorHandler(&e, id);
                noErrors = false;
            } catch (OutOfBounds e) {
                errorHandler(&e, id);
                noErrors = false;
            }

            list.add(temp);

            message = message.substr(pos+2, message.length());
            pos = message.find('}');
        }

        //get the calucaltions out
        pos = message.find(';');
        while(pos > 0 && noErrors) {
            cout << "Instructions" << endl;
            string object = message.substr(0, pos);
            cout << object << endl;
            int space = message.find(' ');
            string op = object.substr(0, space);

            if (op.compare("SUM") == 0) {
                //Will pull out the variable names
                space = message.find(' ');
            	object = object.substr(space+1, object.length());

                space = object.find(' ');
                string o1 = object.substr(0, space);
                object = object.substr(space+1, object.length());

                space = object.find(' ');
                string o2 = object.substr(0, space);
                object = object.substr(space+1, object.length());
                string result = object;

                ostringstream convert;
                convert << "Variable(" << o1 << ":" << o2 << ":" << result << ")";
                output("DEBUG", convert.str(), !debug);

                variable* op1 = list.find(o1);
                variable* op2 = list.find(o2);
                variable* res = list.find(result);
                add temp(op1, op2, res);
                temp.execute();
                cout << res->toJSON() << endl;
            } else if (op.compare("SUB") == 0) {
                space = message.find(' ');
                object = object.substr(space+1, object.length());

                space = object.find(' ');
                string o1 = object.substr(0, space);
                object = object.substr(space+1, object.length());

                space = object.find(' ');
                string o2 = object.substr(0, space);
                object = object.substr(space+1, object.length());
                string result = object;

                ostringstream convert;
                convert << "Variable(" << o1 << ":" << o2 << ":" << result << ")";
                output("DEBUG", convert.str(), !debug);

                variable* op1 = list.find(o1);
                variable* op2 = list.find(o2);
                variable* res = list.find(result);
                sub temp(op1, op2, res);
                temp.execute();
                cout << res->toJSON() << endl;
            } else if (op.compare("DOT") == 0) {
                space = message.find(' ');
                object = object.substr(space+1, object.length());

                space = object.find(' ');
                string o1 = object.substr(0, space);
                object = object.substr(space+1, object.length());

                space = object.find(' ');
                string o2 = object.substr(0, space);
                object = object.substr(space+1, object.length());
                string result = object;

                ostringstream convert;
                convert << "Variable(" << o1 << ":" << o2 << ":" << result << ")";
                output("DEBUG", convert.str(), !debug);

                variable* op1 = list.find(o1);
                variable* op2 = list.find(o2);
                variable* res = list.find(result);
                dot temp(op1, op2, res);
                temp.execute();
                cout << res->toJSON() << endl;
            } else if (op.compare("MUL") == 0) {
                space = message.find(' ');
                object = object.substr(space+1, object.length());

                space = object.find(' ');
                string o1 = object.substr(0, space);
                object = object.substr(space+1, object.length());

                space = object.find(' ');
                string o2 = object.substr(0, space);
                object = object.substr(space+1, object.length());
                string result = object;

                ostringstream convert;
                convert << "Variable(" << o1 << ":" << o2 << ":" << result << ")";
                output("DEBUG", convert.str(), !debug);

                variable* op1 = list.find(o1);
                variable* op2 = list.find(o2);
                variable* res = list.find(result);
                mult temp(op1, op2, res);
                temp.execute();
                cout << res->toJSON() << endl;
            }

            message = message.substr(pos+1, message.length());
            pos = message.find(';');
        }

        //Sends the result back
        if (noErrors) {
          string returnVal = list.find("result")->toJSON();

          int result = write(id, returnVal.c_str(), returnVal.length());
          if (n < 0) output("ERROR", "ERROR writing socket", false);
          output("DEBUG", "End of while loop", !debug);
          message = "VODDO";
        }
    }

    output("DEBUG", "Out of while loop", !debug);


    output("ProcessRequest", "Closing Connection", false);
    close(id);
    exit(0);
}

/**
*   Simple message dislayer which shows the current time,
*   a user defined location (location in the program),
*   and a message. If _silent is set to true, no message
*   will be displayed.
**/

void output(string _location, string _message, bool _silent) {
    if (!_silent)
    {
        time_t now = time(0);
        struct tm * timeinfo;
        char buffer [80];

        timeinfo = localtime(&now);

        strftime(buffer, 80, "%F %T", timeinfo);

        cout << buffer << " [" << _location << "] " << _message << flush << endl;
    }
}

void errorHandler(error* e, int id) {
  output("ERROR", e->getMessage(), false);

  int result = write(id, e->getResponse(), strlen(e->getResponse()));
  if (result < 0) output("ERROR", "ERROR writing socket", false);
}
