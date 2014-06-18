// ruleparse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ISSPACE(x) ((x)==' '||(x)=='\r'||(x)=='\n'||(x)=='\f'||(x)=='\b'||(x)=='\t')

char * rightTrim(char *str)
{
    int len = strlen(str);
    while(--len>=0) {
        if(ISSPACE(str[len])) {
            str[len] = '\0';
        } else {
            break;
        }
    }
    return str;
}

char * getInputLine(char *buffer, int length)
{
    if(fgets(buffer,length, stdin)==NULL) {
        return NULL;
    }
    rightTrim(buffer);
    if(strlen(buffer)<=0) {
        return NULL;
    }
    return buffer;
}

int extractNumbersToArray(char *str, int *numbers)
{
    const char *split = ",";
    char *p = strtok (str,split);
    int index = 0;
    while(p!=NULL) {
        numbers[index++] = atoi(p);
        p = strtok(NULL,split);
    }
    return index;
}

void determineRuleAndOutput(int *numbers, int numberCount, char ** rules, int ruleCount)
{
    //your code here
    int curr_num = 0;
    char * curr_rule = NULL;
    for(int i=0; i<numberCount; i++)
    {
        curr_num = numbers[i];

        for(int j=0; j<ruleCount; j++)
        {
            curr_rule = rules[j];

            for(int k=0; k<strlen(curr_rule); k++)
            {

            }
        }
    }
}

int main(int argc, char ** argv)
{
    int numbers[1024];
    char numberBuffer[1024];
    getInputLine(numberBuffer, 1024);
    int numberCount = extractNumbersToArray(numberBuffer, numbers);
    char buffers[1024][1024];
    char *rules[1024];
    int ruleCount = 0;
    while(getInputLine(buffers[ruleCount], 1024) != NULL) {
        rules[ruleCount++] = buffers[ruleCount];
    }
    determineRuleAndOutput(numbers, numberCount, rules, ruleCount);
    return 0;
}
