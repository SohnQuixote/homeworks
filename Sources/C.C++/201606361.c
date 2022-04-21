#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
struct CMD { // 명령에 대한 정보를 담는 구조체
char *name; // 명령 이름
char *desc; // 명령 설명
int (*cmd)(int argc, char *argv[]); // 명령 실행 함수에 대한 포인터
};
int cmd_cd (int argc, char *argv[]);
int cmd_pwd (int argc, char *argv[]);
int cmd_exit (int argc, char *argv[]);
int cmd_help (int argc, char *argv[]);
int cmdProcessing(void);
struct CMD builtin[] = { // 내장 명령 정보
{ “cd”, “작업 디렉터리 바꾸기”, cmd_cd },
{ “pwd”, “현재 작업 디렉터리는?”, cmd_pwd },
{ “exit”, “셸 실행을 종료합니다”, cmd_exit },
{ “help”, “도움말 보여 주기”, cmd_help }
};
const int builtins = 4; // 내장 명령의 수
int main (void)
{
int isExit = 0;
while (!isExit)
isExit = cmdProcessing(); // 명령 처리 루틴 호출
fputs (“My Shell을 종료합니다…\n”, stdout);
return 0;
}
#define STR_LEN 1024 // 최대 명령 입력 길이
#define MAX_TOKENS 128 // 공백으로 분리되는 명령어 문자열 최대 수
int cmdProcessing (void)
{
char cmdLine[STR_LEN]; // 입력 명령 전체를 저장하는 배열
char *cmdTokens[MAX_TOKENS]; // 입력 명령을 공백으로 분리하여 저장하는 배열
char delim[] = “ \t\n\r”; // 토큰 구분자 - strtok에서 사용
char *token; // 하나의 토큰을 분리하는데 사용
int tokenNum; // 입력 명령에 저장된 토큰 수
int exitCode = 0; // 종료 코드 (default = 0)
fputs (“[mysh v0.1] $ “, stdout); // 프롬프트 출력
fgets (cmdLine, STR_LEN, stdin); // 한 줄의 명령 입력
/* /* /* 추가로 필요한 필요한 헤더 파일들을 파일들을 파일들을 명시한다 명시한다 */
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
for (int i = 0; i < builtins; ++i) { // 내장 명령인지 검사하여
// 명령이 있으면 해당 함수 호출
if (strcmp(cmdTokens[0], builtin[i].name) == 0)
return builtin[i].cmd(tokenNum, cmdTokens);
}
return exitCode;
}
int cmd_cd (int argc, char *argv[])
{
	char *str;
	if(argc ==1)
	{
		str = getenv("HOME");
		if(chdir(str) != 0)
		{
			perror(
		}	
	}
	else
	{
		if (chdir(cmdTokens[1]) != 0) //0번 명령어 1번 위치
		{
			perror("오류");
		}

	}
return 0;
}
int cmd_pwd (int argc, char *argv[])
{
	char *string;
	if(getcwd(string, LEN) ==-1)
	{
		perror("오류");
	}
	printf("\n 현재 위치: %s" ,string);
	return 0;
}
int cmd_exit (int argc, char *argv[])
{
	return 1;
}