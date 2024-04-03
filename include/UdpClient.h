#ifndef UDPCLIENT_H_
#define UDPCLIENT_H_
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <mutex>
#include <thread>
#include <atomic>
#include <unistd.h>
#include <netdb.h>


using namespace std;
class UdpClient {
    private:
    public:
        //Constructor
        UdpClient(string serverAddress,int port);
        //Deconstructor
        virtual ~UdpClient();
        //Send message To udp client.
        void pushMessageToSendQ(string message);
        //Get message from udp Client.
        string popMessageFromRecvQ();
    private:
        int sockfd;
        struct sockaddr_in serverAddr;
        queue<string> sendQueue,recvQueue;
        mutex sendMutex,recvMutex;
        thread sendThread,recvThread;
        void processSendQueue();
        atomic_bool running;
        void processReceiveQueue();

        void pushMessageToRecvQ(string message);

};

#endif /* UDPCLIENT_H_ */