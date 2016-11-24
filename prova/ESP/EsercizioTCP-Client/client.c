/*
 * client.c
 *
 *  Created on: 22 ott 2016
 *      Author: Federico
 */


#include "Client_socket_util.h"


int main(void) {

   #if defined WIN32
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2 ,2), &wsaData);
	if (iResult != 0) {
	 printf ("error at WSASturtup\n");
	 return 0;
	}

	#endif

	// CREAZIONE DELLA SOCKET

	 printf ("creazione socket ...\n");


	int Csocket;
	Csocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (Csocket < 0) {

		ErrorHandler("socket creation failed.\n");
		closesocket(Csocket);
		ClearWinSock();
		return 0;

	}

	// COSTRUZIONE DELL’INDIRIZZO DEL SERVER
	 printf ("creazione indirizzo server ...\n");
	 fflush(stdout);

	struct sockaddr_in sad;
	memset(&sad, 0, sizeof(sad));
	sad.sin_family = AF_INET;
	sad.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP del server
	sad.sin_port = htons(27017); // Server port

	// CONNESSIONE AL SERVER

	 printf ("connessione server ...\n");
	 fflush(stdout);


	if (connect(Csocket, (struct sockaddr *)&sad, sizeof(sad)) < 0)
	{
		ErrorHandler( "Failed to connect.\n" );
		closesocket(Csocket);
		ClearWinSock();
		return 0;
	}


	// operazioni richieste al server
	 operation( Csocket );



	// CHIUSURA DELLA CONNESSIONE
	 printf ("chiusura connessione ...\n");
	 fflush(stdout);


	 MyCloseSocket(Csocket);

	printf("\n"); // Print a final linefeed

	system("pause");
	return(0);


}// main()




