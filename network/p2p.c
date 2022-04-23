#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <winsock2.h>
#include <string.h>

#define nodefmax 10              /* Max number of files in a node */
#define FNameMax 32  /* Max length of File Data */
int message_id; // 처리할 메시지 유형 //뮤텍스 처리해야됨

#define BASE 1000
#define PPRQ BASE+1 
#define PPPS BASE+2
#define JIRQ BASE+3
#define JIRS BASE+4
#define MKRQ BASE+5
#define MKRS BASE+6
#define PIRQ BASE+7
#define PIRS BASE+8
#define PURQ BASE+9
#define PURS BASE+10
#define SIRQ BASE+11
#define SIRS BASE+12
#define SURQ BASE+13
#define SURS BASE +14
#define FPRQ BASE +15
#define FPRS BASE+16
#define LKRQ BASE +17
#define LKRS BASE+18
#define FRARQ BASE +19
#define FRARS BASE +20
#define FRDRQ BASE +21
#define FRDRS BASE+22
#define FDRQ BASE +23
#define FDRS BASE+24
#define FRIRQ BASE+25
#define FRIRS BASE +26
#define P_TRY 3
int pf_socket, req_socket, resp_socket;
int file_listen_socket , file_recv_socket , file_send_socket;

struct fileStru {				/* File Structure */
	char Name[FNameMax];		/* File Name */
	int  Key;					/* File Key */
	struct nodeInfo *owner;			/* file Owner */
	char *Data;                 /* File Data */
};

struct fileInfo {               /* Global Information of Current Files */
	int fileNum;				/* The Number of Current Files */
	struct fileStru file[nodefmax];	/* Information of Each File */
};//변경을 해야함
struct nodeInfo {				/* Node Structure */
	struct in_addr ipaddr;      /* Node's IPv4 Address */
	struct nodeData Data;		/* Node's Data */
	struct nodeInfo *nextNode;  /* Next node pointer */
};

struct fingerTable {			/* Finger Table Structure */
	struct nodeInfo *Pre;		/* Predecessor pointer */
	struct nodeInfo **finger;	/* Fingers (array of pointers) */
}; //자신만 갖고있음

struct chordInfo {              /* Chord Information Structure */
	struct fileInfo ownFRef;    /* File Ref Own Information */
	struct fingerTable fingerInfo;  /* Finger Table Information */
};

struct nodeData {
	int ID;						/* Node's ID */
	struct fileInfo ownFile;    /* File Own Information */
	struct chordInfo chordData; /* Chord Data Information */
};

typedef struct nodeInfo nodeType;
typedef struct fileStru fileType;

struct message_header
{
	int id; //메시지타입
	struct nodeData node_info; //자신의 모든 정보
	int more_info; //추가정보가 있는지
	int body_size; //바디의 크기
};
//소켓은 뮤텍스 처리할필요 없음
void proc_recv()
{
    //recv(char *mes =message );
    //switch(mes->id)
    //{
        case join : 
        //make thread 
        //dont have to give socket variable because it is global variable
        //must have function to make thread
        break;
        
        
        
        
        
        
    //}
}
MSE INIT(ID, SOCKINFO)
{
    //this initializes msg according to its id
}
void proc_pf()
{
    //mesg = INIT(id_pf , sockinfo);
    //for()sendto(mesg -> /*send to all its finger tables*/);
    //if there was error in ping pong must make thread and stabilize its finger table 
}
void proc_fl()
{
    //flsock is listening whether there is file requset msg
    //if reqmsg arrives, make fs thread and give host's fr sock
    //back to its own work
}
void proc_fs()
{
    //send file by its information
}
void proc_fr()
{
    //if user wants to download some kind of file
    //main thread make thread 
    //1)user want to download
    //2)main thread makes thread
    //3)main thread gets fileinfo
    //4)this ask flsock to send the file
    //5)fl sock give fr sockinfo to file sending thread
    //6)file sending thread send the file
}
struct nodeData test;
int main(void)
{
    //main is responsible for UI and UserInput processing
	int bsize = 0;
	int rn;
	rn = sizeof(int);
	HANDLE hThread[3];
	pf_socket = socket(AF_INET, SOCK_DGRAM, 0);
	req_socket = socket(AF_INET, SOCK_DGRAM, 0);
	resp_socket = socket(AF_INET, SOCK_DGRAM, 0);
	file_listen_socket = socket(AF_INET, SOCK_STREAM, 0);
	file_send_socket = socket(AF_INET, SOCK_STREAM, 0);
	file_recv_socket = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(pf_socket, SOL_SOCKET, SO_RCVTIMEO, &bsize, &rn); //될지모름
	hThread[1] = (HANDLE)_beginthreadex(NULL, 0, (void*)proc_recv, 0/*보내는 인자*/, 0, NULL);
	hThread[2] = (HANDLE)_beginthreadex(NULL, 0, (void*)proc_pf, 0/*보내는 인자*/, 0, NULL);
	hThread[3] = (HANDLE)_beginthreadex(NULL, 0, (void*)proc_fl, 0/*보내는 인자*/, 0, NULL);
	
	
	

}
//ㅁㄴㅇㅁㄴㅇㅁㅇㅁㅇㅁㄴㅇㅁ/
void pingpong()
{
	int p_try = P_TRY;
	for (int i = 1; i < test.chordData.fingerInfo.finger; i++)
	{
		while (p_try--)
		{
			sendto(pfsock->rpsock);
			if (recvfrom(rpsock->pfsock) != -1)
				break;
		}
	}
}
//must make atomic function and complex function that includes atomic function
