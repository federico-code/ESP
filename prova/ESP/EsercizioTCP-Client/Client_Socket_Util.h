/*
 * Client_Socket_Util.h
 *
 *  Created on: 01 nov 2016
 *      Author: Federico
 */

#ifndef CLIENT_SOCKET_UTIL_H_
#define CLIENT_SOCKET_UTIL_H_



#endif /* CLIENT_SOCKET_UTIL_H_ */

#if defined WIN32
#include <winsock.h>
#else
#define closesocket close
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFFERSIZE 512
#define PROTOPORT 5193 // Numero di porta di default



void ErrorHandler(char *errorMessage);
void MyCloseSocket(int Csocket);
void operation(int Csocket );
void ClearWinSock();
void MyRecieve(int , char* , int  , int  );
void MySend(int ,char* , int  , int );
void MyErrorHandler(char *, int  );
