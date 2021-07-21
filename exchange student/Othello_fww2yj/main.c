#include <stdio.h>
#include <stdlib.h>
//player1 is 1 and player 2 is 2 this value can be changed by changing the array type
struct player
{
    int p_1;
    int p_2;
};
typedef struct player player;
void init(int a[][8]);
void print_game_board(int a[][8]);
int check_field_before(int a[][8], int x,int y,int player);//check that coordinate is good
void check_field_after(int a[][8],int *player);// check whether p can put the stone if not 2->1 ,1->2
void change_field(int a[][8], int x, int y,int player);//change the field by the rule
void input_field(int a[][8], int *player);//scan the coordinate from the player
int game_finish(int a[][8]);// check if game finished
player calculate_result(int a[][8]);

int main()
{
    player result;
    int player=1;
    int game_board[8][8];
    init(game_board);
    print_game_board(game_board);
    while(game_finish(game_board) == 1)
    {
        input_field(game_board,&player);
    }
    else
    {
        result = calcuate_result(a);
        if(result.p_1>result.p_2)
            printf("\n player 1 win!");
        else if(result.p_1<result.p_2)
            printf("\n player 2 win!");
        else
            printf("\n draw!");
    }
    return 0;
}
void init (int a[][8])
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
           a[i][j] = 0;
    }
    a[3][3] = 1;
    a[4][4] = 1;
    a[4][3] = 2;
    a[3][4] = 2;
}
void print_game_board (int a[][8])
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            printf("%d " , a[i][j]);
        }

        printf("\n");
    }
}
void input_field(int a[][8], int *player)
{
    int x,y;
    scanf("%d %d", &x,&y);
    while(check_field_before(a,x,y,player)!= 1)
    {
        scanf("%d %d", &x,&y);
    }
    change_field(a,x,y,player);
    check_field_after(a,&player);
    if((*player) ==1)
        *player =2
    else
        *player =1;
}
int game_finish(int a[][8])
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(i=0;i<8;i++)
        if(a[i][j] == 0)
                return 1;

    }
    return 0;
}
player calcuate_result(int a[][8])
{
    player d;
    d.p_1 =0;
    d.p_2 =0;
    int i,j;
    for(i=0;i<8;i++)
    {
        for(i=0;i<8;i++)
        {
            if(a[i][j] == 1)
                d.p_1 ++;
            else if(a[i][j] ==2)
                d.p_2 ++;
        }

    }
    return d;
}
int check_field_before(int a[][8],int x, int y, int player)
{
    return 1;
}
void change_field(int a[][8], int x, int y, int player)
{

}
void check_field_after(int a[][8] , int *player)
{

}
