#ifndef SIPMESSAGE_H_
#define SIPMESSAGE_H_


#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <unistd.h>
#include <sstream>

#define CRLF "\r\n"

#define SIP_VERSION "SIP/2.0"
#define TRANSPORT_PROTOCOL "SIP/2.0/UDP" //Transport protocol that will be used in 'via' header.

#define REGISTER "REGISTER"
#define INVITE "INVITE"
#define BYE "BYE"

#define CONTENT_LENGTH_HEADER "Content-Length"
#define CALLID_HEADER "Call-ID"

using namespace std;

class SipMessage {
    typedef struct {
            string method; // Method of the request.
            string via; // Request
            string statusCode; //Response
            char reasonPhrace[10]; //Response
            //Headers

            string from;
            string to; 
            string callId; 
            string cSeq;
            string contact;
            string body;
            int contentLength;
            

        } Message;
    public:
        //Constructor
        SipMessage(string localIp,string sipPort,string sipServer);
        SipMessage();//Creates empty sip struct for responses.
        //Deconstructor
        virtual ~SipMessage();//Creates an empty sip message.
        void setMethod(string type, string calleeURI);
        void setVia();
        void setFrom(string callerUri);//Display name can be added.
        void setTo(string calleeUri);//
        void setCallId(string callId);
        void setCseq(int seq);
        void setContact(string callerUri);

        string getCallerUri();
        string getCalleeUri();
        string getCseq();
        string getCallId();
        string getStatus();
        int getContentLength();

        string getSipString();
        void setSipFromString(string sipString);
        
    private:
        
        Message sipMessage;
        string localIp;
        string sipPort;
        string sipServer;
        void parseStartLine(string line);


};

#endif /* SIPMESSAGE_H_ */