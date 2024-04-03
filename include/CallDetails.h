#ifndef CALLDETAILS_H_
#define CALLDETAILS_H_

#include <string>
#include <mutex>
enum callStates
{
    REGISTERED,  // State when the client registered to server.
    REGISTERING, // State when the client tries to register.
    CONNECTED,   // State when the call initiated.
    CONNECTING,  // State when the call tries to connect.
    TERMINATED,  // State when the call terminated.
    TERMINATING, // State when the call tries to terminating.
};
using namespace std;
class CallDetails
{

    typedef struct
    {
        string callerURI;
        string calleeURI;
        string callId;
        callStates callState;
    } CallStruct;

public:
    CallDetails(string callId,string callerURI,string calleURI);
    virtual ~CallDetails();
    void setCallId(string callId);
    void setCallerURI(string callerUri);
    void setCalleeURI(string calleeUri);
    void setCallState(callStates state);
    callStates getCallState();
    string getCallId();
    string getCallerURI();
    string getCalleeURI();

private:
    CallStruct callStruct;
    mutex readCallStructMutex;
};

#endif /* CALLDETAILS_H_ */