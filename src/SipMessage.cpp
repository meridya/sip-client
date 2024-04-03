#include "SipMessage.h"

SipMessage::SipMessage(string local_Ip,string sip_Port,string sip_Server) {
    localIp = local_Ip;
    sipPort = sip_Port;
    sipServer = sip_Server;
    setVia();

   
}


SipMessage::~SipMessage(){
 
}


void SipMessage::setMethod(string type, string calleeURI){
    sipMessage.method= type+" "+ calleeURI+ " " + SIP_VERSION;
    sipMessage.cSeq = "1 " + type;
     
}
void SipMessage::setVia(){
    string protocol=TRANSPORT_PROTOCOL;
    sipMessage.via = protocol + " " + localIp+":"+sipPort;

}
void SipMessage::setFrom(string callerUri){
    sipMessage.from= "<"+callerUri+">";
}
void SipMessage::setTo(string calleeUri){
    sipMessage.to = "<"+calleeUri+">";
}

void SipMessage::setContact(string callerUri){
    sipMessage.contact = "<"+callerUri+":" + sipPort +";ob>";
}

void SipMessage::setCallId(string callId){
    sipMessage.callId = callId;
}

string SipMessage::getSipString(){
    string sipString = sipMessage.method + CRLF 
                    + "Via: " + sipMessage.via + CRLF
                    + "From: " + sipMessage.from + CRLF
                    + "To: " + sipMessage.to + CRLF
                    + "CSeq: " + sipMessage.cSeq + CRLF
                    + "Call-ID: " + sipMessage.callId + CRLF
                    + "Contact: "+ sipMessage.contact +CRLF
                    + "Expires: 3600" + CRLF
                    + "Content-length: 0" + CRLF + CRLF;

    return sipString;

}

void SipMessage::setSipFromString(string sipString){
    istringstream stream(sipString);
    string line;
    getline(stream,line);
    parseStartLine(line);

    while(std::getline(stream,line) && line != "\r"){
        auto colonPos =line.find(':');
        if(colonPos!=string::npos){
            string headerName=line.substr(0,colonPos);
            string headerValue=line.substr(colonPos+2,line.length()-colonPos -3);


            // For simplicity we just control CallId and removing content with the contentlength parameter.
            if(headerName == CALLID_HEADER){
                sipMessage.callId = headerValue;
            }else if(headerName == CONTENT_LENGTH_HEADER){
                sipMessage.contentLength = stoi(headerValue);
            }

        }
    }
}
void SipMessage::parseStartLine(string line){
    istringstream lineStream(line);
    string method;
    string version;
    lineStream >> method >> sipMessage.statusCode >> version;
}


string SipMessage::getCallId(){
    return sipMessage.callId;
}
string SipMessage::getStatus(){
    return sipMessage.statusCode;
}
int SipMessage::getContentLength(){
    return sipMessage.contentLength;
}