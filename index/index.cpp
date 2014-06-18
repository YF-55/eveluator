// index.cpp : Defines the entry point for the console application.
//
#include <iostream>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int input;
    cin >> input;
    scanf("%d", &input);
    if(input<=0)
    {
        return -1;
    }
    int i = input;
    int j = 0;
    int k = 0;
    char result[100];
    char select[]="ABCDEFGHIGKLMNOPQRSTUVWXYZ";
    do
    {
       i = input/26;
       k = input - i*26;
       result[j] = select[k-1];
       j++;
       //cout<< select[k-1];
       input = i;
    }while (input>26);
    if(j==1 && i ==0)
    {
        printf("%c", result[0]);
        return 0;
    }
    if(i>1)
        result[j] = select[i-1];
    for(int l=j; l>=0; l--)
        printf("%c", result[l]);

    return 0;
}