/*
 * Client_Socket_Util.c
 *
 *  Created on: 01 nov 2016
 *      Author: Federico
 */


#include "Client_socket_util.h"



	void MyCloseSocket(int Csocket)
	{

	#if defined WIN32
		closesocket(Csocket);
		ClearWinSock();
	#else
		close(Csocket);
	#endif



	}


	void ErrorHandler(char *errorMessage) {

		printf(errorMessage);
		system("pause");


	}
	void ClearWinSock() {

		#if defined WIN32
		WSACleanup();
		#endif

	}


	void operation(int Csocket )
	{

		char buf[BUFFERSIZE];

		//messaggio server
		MyRecieve(  Csocket, buf, BUFFERSIZE , 0 );
		printf(" %s\n",buf);


		printf(" Inizio acquisizione valori\n");
		fflush(stdout);
        char numero[50];
        char messaggioServer[50];

		while(1){
			printf(" inserire numero :");
			fflush(stdout);

			scanf("%s",numero);
			MySend(Csocket,numero,BUFFERSIZE,0);

			MyRecieve(Csocket,messaggioServer,BUFFERSIZE,0);
			 printf(" %s \n",messaggioServer);

			if(strcmp(messaggioServer,"QUIT")==0)
			  MyErrorHandler(" numero non valido , chiudo...\n",Csocket);




		}


	}






	void MySend(int socket,char* messaggio, int size , int flag)
	{
		if(send( socket , messaggio , size , flag ) <=0)
		{

			ErrorHandler( "errore invio.\n" );
					closesocket(socket);
					ClearWinSock();
					system("pause");
					exit('0');
		}



	}


	void MyRecieve(int socket, char* messaggio, int size , int flag )
	{
		int L=0;
		if((L=recv(  socket, messaggio, size , flag ))<=0)
		{
			ErrorHandler( "errore ricezione.\n" );
					closesocket(socket);
					ClearWinSock();
					system("pause");
					exit('0');
		}

		messaggio[L]='\0';

	}

	void MyErrorHandler(char *errorMessage, int MySocket ) {

	       printf(errorMessage);
	       fflush(stdout);
		// CHIUSURA DELLA CONNESSIONE
			closesocket(MySocket);
			ClearWinSock();
			system("pause");
			exit(0);


	}


