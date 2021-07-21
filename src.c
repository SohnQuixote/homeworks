#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <setjmp.h>
#include <signal.h>
#include <pwd.h>
#include <termios.h>
#include <sys/wait.h>
#define LEN 100
#define BUF 10
#define STR_LEN 1024 // 최대 명령 입력 길이
#define MAX_TOKENS 128 // 공백으로 분리되는 명령어 문자열 최대 수

struct CMD { // 명령에 대한 정보를 담는 구조체
    char *name; // 명령 이름
    char *desc; // 명령 설명
    int (*cmd)(int argc, char *argv[]); // 명령 실행 함수에 대한 포인터
};
struct HISTORY{
        struct CMD cmd_buffer;
        int argc;
        char **argv;
};
struct HISTORY cmd_buff[BUF];
int prev =-1;
/*struct EXT{
    char *name;   
    char *desc;
    int (*cmd)(int argc, char*argv[]);   
};*/
int cmd_cd (int argc, char *argv[]);
int cmd_pwd (int argc, char *argv[]);
int cmd_exit (int argc, char *argv[]);
int cmd_help (int argc, char *argv[]);
int process_exe (int argc, char *argv[]);
int pipe_exe (int argc, char *argv[]);
int history_exe(int argc, char *argv[]);
int prev_exe(int argc,char *argv[]);
int num_exe(int argc, char * argv[]);
struct HISTORY* cmd_save (struct CMD , int i , char **n);
int cmdProcessing(void);
struct CMD builtin[] = { // 내장 명령 정보
{"cd", "작업디렉터리바꾸기" ,cmd_cd},
{"pwd" , "위치보여주기" , cmd_pwd},
{"exit" , "나가기" , cmd_exit},
{"help" , "도움말" , cmd_help},
{"history" , "명령어 역사" ,history_exe},
{"exec" , "프로세스실행" ,process_exe},
{"!!" , "이전명령어" , prev_exe},
{"!" , "특정 번호 명령어(! n)" , num_exe}
};
struct CMD built[] =
{   
{"|" , "파이프" , pipe_exe},

};
const int builts = 3; //외장명령의 수
const int builtins = 8; // 내장 명령의 수
int main (void)
{
int isExit = 0;
while (!isExit)
isExit = cmdProcessing(); // 명령 처리 루틴 호출
fputs("myShell을 종료합니다" ,stdout);
return 0;
}

int cmdProcessing (void)
{
    char cmdLine[STR_LEN]; // 입력 명령 전체를 저장하는 배열
    char *cmdTokens[MAX_TOKENS]; // 입력 명령을 공백으로 분리하여 저장하는 배열
    char delim[] = "\t\n\r"; // 토큰 구분자 - strtok에서 사용
    char *token; // 하나의 토큰을 분리하는데 사용
    int tokenNum; // 입력 명령에 저장된 토큰 수
    int exitCode = 0; // 종료 코드 (default = 0)
    fputs ("[sumin v0.0.1] $ ", stdout); // 프롬프트 출력
    fgets (cmdLine, STR_LEN, stdin); // 한 줄의 명령 입력

/* 기타 필요한 변수 선언 */
    tokenNum = 0;
    token = strtok (cmdLine, delim); // 입력 명령의 문자열 하나 분리
while (token) { // 문자열이 있을 동안 반복
    cmdTokens[tokenNum++] = token; // 분리된 문자열을 배열에 저장
    token = strtok(NULL, delim); // 연속하여 입력 명령의 문자열 하나 분리
}
cmdTokens[tokenNum] = NULL;

if (tokenNum == 0)
    return exitCode;
for (int i = 0; i < builtins; ++i)
{ // 내장 명령인지 검사
if (strcmp(cmdTokens[0], builtin[i].name) == 0)
return builtin[i].cmd(tokenNum, cmdTokens);

}
if(tokenNum ==3 && strcmp(cmdTokens[1] , "|") == 0)
pipe_exe(tokenNum , cmdTokens);
return exitCode;
}
int cmd_cd (int argc, char *argv[])
{
    cmd_save(builtin[0],argc,argv);
    if(argc ==1)
    {
        if(chdir(getenv("HOME")) != 0)
        {
            perror("오류");
        }
    }
    else if(argc ==2)
    {
        if(chdir(argv[1])!=0)
            perror("오류");               
    }
    else
    {
            perror("오류");
    }
return 0;
}
int cmd_pwd (int argc, char *argv[])
{
    cmd_save(builtin[1],argc,argv);
    char string[LEN];
    getcwd(string,LEN);
    printf("\n 현재 위치: %s\n" ,string);
    return 0;
}
int cmd_exit (int argc, char *argv[])
{
    return 1;
}
int cmd_help (int argc , char*argv[])
{
    cmd_save(builtin[3],argc,argv);
    for(int i =0; i<builtins ;i++)
    {
            printf("\n %s : %s \n" , builtin[i].name ,builtin[i].desc);
    }
    return 0;
}
int process_exe (int argc, char* argv[])
{
    cmd_save(builtin[5],argc,argv);
    if(argc != 2)
        perror("오류");
    int pid;
    pid = fork();
    if(pid<0)
    {
        perror("오류");
    }
    else if(pid == 0)/*자식 프로세스 받은 이름 바탕으로 탐색후 실행*/
    {
        execl(argv[1],argv[1],NULL);
    }
    else
    {
            wait(NULL);
            printf("\n작업완료\n");
    }
    return 0;
}
int pipe_exe(int argc, char* argv[])
{
    //cmd_save();
    int pd[2]; // 0은 읽기 전용 1은 쓰기 전용
    char read_buffer[STR_LEN];
    char write_buffer[STR_LEN];
    if (pipe (pd)<0) perror ("오류");
    if(argc !=3)
        perror("오류");
    int pid_1,pid_2;
    pid_1 = fork(); pid_2 = fork();
    if(pid_1<0 || pid_2 <0)
    {
        perror("오류");
    }
    else if(pid_2 == 0) //읽기 대기
    {
        close(pd[1]);
        while(read(pd[0] , read_buffer, STR_LEN)==-1){} //있을때 까지 계속 읽음
        execlp( argv[2] , read_buffer,NULL); // 두번째 프로그램을 실행하고 파이프로부터 입력받은 값을 매개변수로 전달함
    }
    else if(pid_1 == 0)//쓰기
    {
        close(pd[0]);
       // write_buffer = (char*)execlp(argv[0] , argv[0],NULL);//실행후 버퍼에 저장 , 파이프 쓰기부분에 저장
        write(pd[1], write_buffer,STR_LEN);
    }
    else //부모 프로세스
    {
            wait(NULL);
            printf("\n작업완료\n");
    }
    return 0;
}
int history_exe(int argc, char* argv[])
{
    //최대갯수를 넘기면 넘길때마다 상태를 저장해 history를 표현할때 1-10까지가 아닌 11-20까지로 할수 있으나
    //불필요해보이는 관계로 구현 안함
    cmd_save(builtin[4],argc,argv);
    //char *cmdLine;
    for(int i=0;i<BUF;i++)
    {
        printf("\n %d : %s \n" , i+1 ,cmd_buff[i].cmd_buffer.name);
    }
    /*printf("\n 히스토리 명령선택 \n");
    fgets (cmdLine, STR_LEN, stdin);
    if(cmdLine[0] == "!")))
    {
        if(strcmp(cmdLine[1] =="!")))
            return cmd_buff[9].cmd_buffer.cmd(cmd_buff.argc,cmd_buff.argv);
        else //문자열 번호로 변형 후 함수 실행
        {
               
        }
    }*/
    return 0;
}
struct HISTORY* cmd_save(struct CMD temp, int i, char** n)
{
    if(prev ==9)
    {
        for(int i=1;i<BUF;i++)
            cmd_buff[i-1] = cmd_buff[i];
        prev =8;
       
    }
    cmd_buff[++prev].cmd_buffer = temp;
    cmd_buff[prev].argc = i;
    cmd_buff[prev].argv = n;
    return cmd_buff;
}
int prev_exe( int argc, char * argv[])
{
    return cmd_buff[prev].cmd_buffer.cmd(cmd_buff[prev].argc,cmd_buff[prev].argv);
}
int num_exe (int argc , char * argv[])
{ //왜 안되는지 모르겠음 
    int i = atoi(argv[1]);
    printf("%d " , i);
    return cmd_buff[i-1].cmd_buffer.cmd(cmd_buff[i-1].argc,cmd_buff[i-1].argv);
}


