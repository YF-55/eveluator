// stack.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include <cstring>

#include <cstdio>

#include <cstdlib>

#include <stack>



using namespace std;



char* calculateOperationSequence(int *originalArray, int *resultArray, int length);



inline bool isSpace(char x){

    return x == ' ' || x == '\r' || x == '\n' || x == '\r' || x == '\b' || x == '\t';

}



char * rightTrim(char *str){

    int len = strlen(str);

    while(--len>=0){

        if(isSpace(str[len])){

            str[len] = '\0';
        }else{

            break;

        }

    }

    return str;

}



char * getInputLine(char *buffer, int length){

    if(fgets(buffer,length, stdin)==NULL){
        return NULL;

    }

    rightTrim(buffer);

    if(strlen(buffer)<=0){

        return NULL;

    }

    return buffer;

}


int splitAndConvert(char* strings,int *array){
    char*tokenPtr = strtok(strings,",");

    int i=0;

    while(tokenPtr!=NULL){

        array[i] = atoi(tokenPtr);
        i++;

        tokenPtr=strtok(NULL,",");

    }

    return i;

}


int main(){

    char line[1000] = {0} ;

    while(getInputLine(line,1000)){

        int originalArray[30] = {0};

        int originalArrayLength = splitAndConvert(line,originalArray);

        if(originalArrayLength==0){

            break;

        }



        getInputLine(line, 1000);
        int resultArray[30] = {0};

        int resultArrayLength = splitAndConvert(line,resultArray);

        if(resultArrayLength==0){

            break;

        }

        char *operationSequence = calculateOperationSequence(originalArray, resultArray, resultArrayLength);



        if (NULL != operationSequence)

        {   // 原来系统提供的代码。这里没有NULL判断
            cout<< operationSequence <<endl;
            free(operationSequence); // 自己加的
        }

        else

            cout<< "None" <<endl; // 自己加的

    }

    return 0; 
} 



//your code is here  
char* calculateOperationSequence(int * originalArray, int * resultArray, int length)
{
    stack<int> stack1;
    char * l_ret = (char*)malloc(1000);
    memset(l_ret, '\0', 1000);
    int j=0;
    //sprintf(l_ret, "push%d|", originalArray[0]);

    for(int i=0; i< length; i++) // result Array
    {
        int target = resultArray[i];

        if(!stack1.empty() && stack1.top() == target)
        {
            // Move data to target and move to next target
            char temp[100];
            sprintf(temp, "pop%d|", stack1.top());
            strcat(l_ret, temp);
            stack1.pop();
        }
        else
        {
           while( j<length)
            {
                stack1.push(originalArray[j]);
                char temp[100];
                sprintf(temp, "push%d|", stack1.top());
                strcat(l_ret, temp);
                if(originalArray[j]==target)
                {
                    char temp[100];
                    sprintf(temp, "pop%d|", stack1.top());
                    strcat(l_ret, temp);
                    stack1.pop();
                    j++;
                    break;
                }
                j++;
            }
        }
    }
    if(!stack1.empty() || j!=length)
        sprintf(l_ret, "Invalid\n");
    else
    {
        int len = strlen(l_ret);
        if(len>2)
            l_ret[len-1] = '\0';
    }
    return l_ret;
}
