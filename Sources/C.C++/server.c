#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <process.h> 

#define NAME_SIZE 20
#define BUF_SIZE 100
#define MAX_CLNT 256

unsigned WINAPI HandleClnt(void * arg);
void SendMsg(char * msg, int len);
void ErrorHandling(char * msg);

struct ClientInfo
{
	char nickName[NAME_SIZE];
	char* IP;
};
int clntCnt = 0;
struct ClientInfo clientinfo[MAX_CLNT];						// 각 소켓 마다 그에 해당하는 닉네임과 IP 주소를 추가로 저장하기 위한 배열
SOCKET clntSocks[MAX_CLNT];
HANDLE hMutex;
HANDLE hFileThread;
char * str_;
int main(int argc, char *argv[])
{
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAdr, clntAdr;
	int clntAdrSz;
	HANDLE  hThread;
	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error!");
	hMutex = CreateMutex(NULL, FALSE, NULL);
	hServSock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi(argv[1]));

	if (bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		ErrorHandling("bind() error");
	if (listen(hServSock, 5) == SOCKET_ERROR)
		ErrorHandling("listen() error");

	while (1) {
		clntAdrSz = sizeof(clntAdr);
		hClntSock = accept(hServSock, (SOCKADDR*)&clntAdr, &clntAdrSz);
		WaitForSingleObject(hMutex, INFINITE);
		clientinfo[clntCnt].IP = inet_ntoa(clntAdr.sin_addr);				// 해당 소켓의 IP 를 저장해둠
		clntSocks[clntCnt++] = hClntSock;
		ReleaseMutex(hMutex);

		hThread = (HANDLE)_beginthreadex(NULL, 0, HandleClnt,
			(void*)&hClntSock, 0, NULL);
		printf("Connected client IP: %s \n",
			inet_ntoa(clntAdr.sin_addr));
	}
	closesocket(hServSock);
	WSACleanup();
	return 0;
}

unsigned WINAPI HandleClnt(void * arg)
{
	SOCKET hClntSock = *((SOCKET*)arg);
	int strLen = 0, i;
	char msg[BUF_SIZE];
	boolean isFirstMsg = TRUE;

	int socket_idx;

	char msg_copy[NAME_SIZE + BUF_SIZE];
	char* str;

	while ((strLen = recv(hClntSock, msg, sizeof(msg), 0)) != 0)
	{
		// 우선 msg 의 첫번째 토큰 구하기
		strcpy(msg_copy, msg);
		str = strtok(msg_copy, " ");

		// 해당 소켓으로부터 처음 메세지를 받는 것이라면 닉네임을 저장
		if (isFirstMsg)
		{
			for (i = 0; i<clntCnt; i++)
				if (hClntSock == clntSocks[i])
				{
					strcpy(clientinfo[i].nickName, str);
					socket_idx = i;
				}

			isFirstMsg = FALSE;
		}

		// msg 의 두번째 토큰 구하기 (없으면 다시 처음으로)
		str = strtok(NULL, " ");
		strcpy(str_, str);
		if (str == NULL)
			continue;

		if (str[0] == '/')
		{
			if (!strcmp(str, "/list\n"))
			{
				for (i = 0; i < clntCnt; i++)
				{
					sprintf(msg_copy, "nickName : %s , IP : %s \n", clientinfo[i].nickName, clientinfo[i].IP);
					send(hClntSock, msg_copy, strlen(msg_copy), 0);
				}
			}
			else if (!strcmp(str, "/to"))
			{
				// 세번째 토큰 구하기(귓말 보낼 닉네임)
				str = strtok(NULL, " ");
				for (i = 0; i < clntCnt; i++)
				{
					if (!strcmp(str, clientinfo[i].nickName))
					{
						// 네번째 토큰 구하기
						str = strtok(NULL, "");
						sprintf(msg, "%s %s", clientinfo[socket_idx].nickName, str);
						send(clntSocks[i], msg, strlen(msg), 0);
						break;
					}
				}
				if (i == clntCnt)
				{
					sprintf(msg, "해당 닉네임 사용자 없음 \n");
					send(hClntSock, msg, strlen(msg), 0);
				}
			}
			else if (!strcmp(str, "/fileto"))
			{
				str = strtok(NULL, " ");
				for (i = 0; i < clntCnt; i++)
				{
					//sprintf(msg_copy, "nickName : %s , IP : %s \n", clientinfo[i].nickName, clientinfo[i].IP);
					hFileThread =
						(HANDLE)_beginthreadex(NULL, 0, HandleFile, (void*)&hClntSock, 0, NULL);
					WaitForSingleObject(hFileThread, INFINITE);
				}


			}

		}
		else
			SendMsg(msg, strLen);


	}

	WaitForSingleObject(hMutex, INFINITE);
	for (i = 0; i<clntCnt; i++)   // remove disconnected client
	{
		if (hClntSock == clntSocks[i])
		{
			while (i++<clntCnt - 1)
				clntSocks[i] = clntSocks[i + 1];
			break;
		}
	}
	clntCnt--;
	ReleaseMutex(hMutex);
	closesocket(hClntSock);
	return 0;
}

void SendMsg(char * msg, int len)   // send to all
{
	int i;
	WaitForSingleObject(hMutex, INFINITE);
	for (i = 0; i<clntCnt; i++)
		send(clntSocks[i], msg, len, 0);

	ReleaseMutex(hMutex);
}

void HandleFile(void *arg)
{
	SOCKET hClntSock = *((SOCKET*)arg);
	str_ = strtok(NULL, " ");
	for (int i = 0; i < clntCnt; i++)
	{
		if (!strcmp(str_, clientinfo[i].nickName))
			send(hClntSock, clientinfo[i].IP, strlen(clientinfo[i].IP), 0);
	}

}
void ErrorHandling(char * msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}
