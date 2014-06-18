// array55.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <string.h>

bool move_mmatrix(int originalMatrix[][5], int newMatrix[][5], char inputSequence[]);
bool check_matrix_equal(int originalMatrix[][5], int newMatrix[][5]);

void calculateTheRightSequence(int originalMatrix[][5], int newMatrix[][5], 
                               char inputSequence[], char outputSequence[]);

int Getnput( char operation[], int originalMatrix[][5], int newMatrix[][5]);
int main()
{
    int original[5][5]={{20, 18, 7, 19, 10},{24, 4, 15, 11, 9}, {12, 0, 22, 12,14}, {23, 16, 1, 2, 5}, {21, 17, 8, 3, 6}};
    int newMatrix[5][5]={{20, 18, 7, 19, 10},{24, 15, 11, 12, 9}, {13, 4, 22, 2,14}, {23, 16, 0, 1, 5}, {21, 17, 8, 3, 6}};
    char inputOperation[100]={0};
    char outputOperation[100]= {0};
    //while( Getnput(inputOperation, original, newMatrix) )
    {
        calculateTheRightSequence(original, newMatrix, inputOperation, outputOperation);
        printf("%s\n", outputOperation);
    }
    return 0;
}

const int SIZE_M = 5;
int n = 0;  

void swap(char *a, char *b) 
{     
    char m;     
    m = *a;     
    *a = *b;     
    *b = m; 
}
void perm(char list[], int k, int m, int originalMatrix[][5], int newMatrix[][5]) 
{     
    int i;     
    if(k > m)     
    {          
        for(i = 0; i <= m; i++)             
            printf("%c ", list[i]);         
        printf("\n");         
        n++;
        int tempMatrix[5][5];

        if(move_mmatrix(originalMatrix, tempMatrix, list))
        {
            if(check_matrix_equal(tempMatrix, newMatrix))
                printf("Good sequence: %s\n", list);
        }
    }     
    else     
    {         
        for(i = k; i <= m; i++)         
        {             
            swap(&list[k], &list[i]);             
            perm(list, k + 1, m, originalMatrix, newMatrix);             
            swap(&list[k], &list[i]);         
        }     
    } 
} 

bool check_matrix_equal(int originalMatrix[][5], int newMatrix[][5])
{
    for (int i=0; i<SIZE_M; i++)
    {
        for(int j=0; j<SIZE_M; j++)
        {
            if( originalMatrix[i][j]!=newMatrix[i][j])
                return false;
        }
    }
    return true;
}

bool move_mmatrix(int originalMatrix[][5], int newMatrix[][5], char inputSequence[])
{
    bool l_ret = false;
    for(int i = 0; i< strlen(inputSequence); i++)
    {

    }
    return l_ret;
}

bool find_zero(int originalMatrix[][5], int& a_x, int& a_y)
{
    bool l_ret = false;

    for (int i=0; i<SIZE_M; i++)
    {
        for(int j=0; j<SIZE_M; j++)
        {
            if( originalMatrix[i][j] == 0)
            {
                a_x = i; 
                a_y = j;
                return true;
            }
        }
    }

    return true;
};

//your code is here
void calculateTheRightSequence(int originalMatrix[][5], int newMatrix[][5], 
                               char inputSequence[], char outputSequence[])
{
    int orig_x=0, orig_y=0, new_x=0, new_y=0;
    if(!find_zero(originalMatrix, orig_x, orig_y) ||
        find_zero(newMatrix, new_x, new_y))
    {
        printf("Input Matrix Error!\n");
        return;
    }

    strcpy(outputSequence, inputSequence);
    int l_len = strlen(outputSequence);
    perm(outputSequence, 0, l_len-1, originalMatrix, newMatrix);

    if(n<=0)
        printf("NONE\n");

}

int Getnput( char operation[], int originalMatrix[][5], int newMatrix[][5])
{
    int i = 0, j = 0;
    for( i = 0; i < 5; ++i )
        for(j = 0; j < 5; ++j)
    {
        if( scanf(" %d ", &originalMatrix[i][j]) != 1 )
            break;
    }
    if( j < 5 ) return 0;
    for( i = 0; i < 5; ++i )
        for(j = 0; j < 5; ++j)
    {
        scanf(" %d ", &newMatrix[i][j]);
    }
    
    scanf( "%s ", operation );  
    return 1;
}
