// eveluator.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;


#include <iostream>
#include <cstring>
using namespace std;


/************************************************************************/
/**
 Args:
 array[]: the inputted array
 final: the target value
 length: the element length
*/
bool is_bit_n_1(int a_input, int a_n)
{
    if(a_n>15)
        return false;
    int i=1;
    i = i << a_n-1;
    if(a_input & i)
        return true;
    else
        return false;
}
void createEquationAndPrint(int array[], int length, int final){
    //Your Code is here
    bool l_ok = false;
    int bit_flag = 0;

    if(length <0 || length>15)
    {
        l_ok = false;
    }
    else if(length == 0)
    {
        cout<<final<<"="<<final;
        return;
    }
    else if(length == 1)
    {
        if(array[0] == final)
        {
            cout<<final<<"="<<final;
            return;
        }
    }
    else
    {
        bit_flag = 0;
        int max_num = 1; max_num = max_num << (length-1);
        for(bit_flag = 0; bit_flag < max_num; bit_flag++)
        {
            int sum = array[0];
            for(int j=1; j<length; j++)
            {
                if(is_bit_n_1(bit_flag, j))
                    sum += array[j];
                else
                    sum -= array[j];
            }
            if(sum == final)
            {
                l_ok = true;
                break;
            }
        }
    }

    if(!l_ok)
        cout<<"Invalid";
    else
    {
        cout<<array[0];
        for(int i=1; i< length; i++)
        {
            if(is_bit_n_1(bit_flag, i))
                cout<<"+";
            else
                cout<<"-";
            cout << array[i];
        }
        cout<<"="<<final;
    }
    return;
}



int splitAndConvert(char* strings,int array[]){
  char*tokenPtr = strtok(strings," ");
  int i=0;
  while(tokenPtr!=NULL){
  array[i] = atoi(tokenPtr);
  i++;
  tokenPtr=strtok(NULL," ");
 }
 return i;
}

int main(){
 char line[1000] = {0} ;
 while(gets(line)){
  int array[30] = {0};
  int length = splitAndConvert(line,array);
  if(length==0){
   break;
  }
  createEquationAndPrint(array, length-1, array[length-1]);
  cout<<endl;
 }
 return 0; 
} 
