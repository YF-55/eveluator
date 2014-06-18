// peek.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ISSPACE(x) ((x)==' '||(x)=='\r'||(x)=='\n'||(x)=='\f'||(x)=='\b'||(x)=='\t')

char * rightTrim(char *str){
    int len = strlen(str);
    while(--len>=0){
        if(ISSPACE(str[len])){
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

/*
For example, A={2, 3, 6, 5, 7, 9}, the elements 2, 5 could be regarded as the valley while 6 and 9 are the peaks. 
The difference of each neighboring peak-valley pair could be enumerated as below:
D[2, 6]=4, D[6,5]=1, D=[5,9]=4.
Thus, MaxD(A)=4.
*/

void maxNeighboringPeak(char ** data, int count){
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	bool first_line = true;
	for(int index=0; index<count; index++)
	{
		int value[20];
		
		char* line= data[index];
		int start=0, end=0;
		char word[100];
		
		int num = 0;
		for(int i=0, j=0; i<strlen(line) && num <20; i++)
		{
			if(line[i] != ' ')
			{
				word[j] = line[i];
				j++;
			}
			if( line[i] ==' ' || i==strlen(line)-1)
			{
				if(j>0)
				{
					word[j] = 0;
					value[num] = atoi(word);
					num ++;
					j=0;
				}
			}
		}
		if(num<2)
			continue;

		//printf("Line %d-%d:", index, num);
		//for(int i =0; i< num; i++)
		//{
		//	printf("%d,", value[i]);
		//}
		// Find Max valley-peek value[]
		int peak[20];
		int pv_num = 1;
		peak[0] = value[0];
		for(int i = 1; i<num-1; i++)
		{
			if(value[i]>value[i-1] && value[i]>value[i+1]
			|| value[i]<value[i-1] && value[i]<value[i+1])
			{
				peak[pv_num] = value[i];
				pv_num++;
			}
		}
		peak[pv_num]=value[num-1];
		pv_num++;
		//printf("peak %d-%d:", num, pv_num);
		//for(int i =0; i< pv_num; i++)
		//{
		//	printf("%d,\n", peak[i]);
		//}

		int max=0;
		// find max_peak value diff
		for(int i=0; i< pv_num-1; i++)
		{
			if(abs(peak[i]-peak[i+1])> max)
				max = abs(peak[i]-peak[i+1]);
		}
		if(!first_line)
			printf(",");
		else
			first_line = false;
		printf("%d", max);

	}
	getchar();
}


int main(int argc, char ** argv){
    char buffers[512][512];
    char *input[512];
    int inputCount = 0;

    while(getInputLine(buffers[inputCount], 512) != NULL){
        input[inputCount++] = buffers[inputCount];
    }

    maxNeighboringPeak(input, inputCount);
    return 0;
}


