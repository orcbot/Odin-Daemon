//@todo add better comments
#include "lib/helper/config.h"
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

void processRequests(int);
void output(string, string, bool);

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
        } else if (strcmp(argv[i], "s") == 0) {
            settings.setSilent(true); 
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

    while (strcmp("quit\n", buffer) != 0) {
        bzero(buffer,256);
        int n = read(id,buffer,255);
        if (n < 0) output("ERROR", "ERROR reading from socket", false);
        printf("Here is the message: %s\n",buffer);

        //Does some processing
        int result = write(id, "RECIEVED", 8);
        if (n < 0) output("ERROR", "ERROR writing socket", false);
    }

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

        cout << buffer << " [" << _location << "] " << _message << endl; 
    }
}
