#include "main.h"

#include "stdio.h"
#include <stdlib.h>
#include <string>

/*
Question 1:
    There are array a1, a2,... an, please just if there are some nums can be picked up and the sum of them is a given value K.
*/
bool find_sub_array(int* a_input, int a_len, int a_target, int a_start, int a_sum);


bool find_sub_array(int* a_input, int a_len, int a_target, int a_start, int a_sum)
{
    if(a_start == a_len)
    {
        if( a_sum == a_target)
        {
            return true;
        }
        else
            return false;
    }
    if( find_sub_array(a_input, a_len, a_target, a_start+1, a_sum)) 
    {
        return true;
    }

    if( find_sub_array(a_input, a_len, a_target, a_start+1, a_sum+a_input[a_start]))
    {
        printf(" %d ", a_start);
        return true;
    }
    return false;
}
/* End of Question 1 */

/*Question 2:
There is garden after raining. Please count out how many small warter pools there are. 
*/

#define MAX_N 10
#define  MAX_M   11
int N=MAX_N, M=MAX_M;
char field[MAX_N][MAX_M+1]; // 园子
int f[][2] = {{1,2}, {2,3}};
// 现在位置(x,y)
void dfs(int x, int y) {
    // 将现在所在位置替换为.
    field[x][y] = '.';
    // 循环遍历移动的8个方向
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            // 向x方向移动dx，向y方向移动dy，移动的结果为（nx,ny）
            int nx = x + dx, ny = y + dy;
            // 判断(nx,ny)是不是在园子内，以及是否有积水
            if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W') dfs(nx, ny);
        }
    }
    return ;
}
void solve() {
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] == 'W') {
                // 从有W的地方开始dfs
                dfs(i, j);
                res++;
            }
        }
    }
    printf("%d\n", res);
}
/*End of question 2 */

int main()
{
    int input[]={1,2,4,7};
    int input_len = 4;
    int target = 13;

    bool l_ret = find_sub_array(input, input_len, target, 0, 0 );
    if(l_ret)
        printf("Case 1: Find it\n");
    else
        printf("Case 1: Not Found!\n");



    strcpy(field[1], "W........WW.");
    strcpy(field[2], ".WWW.....WWW");
    strcpy(field[3], "....WW...WW.");
    strcpy(field[4], ".........WW.");
    strcpy(field[5], ".........W..");
    strcpy(field[6], "..W......W..");
    strcpy(field[7], ".W.W.....WW.");
    strcpy(field[8], "W.W.W.....W.");
    strcpy(field[9], ".W.W......W.");
    strcpy(field[10], "..W.......W." );
    solve();
    return 0;
}


