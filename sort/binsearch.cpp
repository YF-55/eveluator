
#include "Binsearch.h"

void TestBinSearch_sort_1_numbers()
{
    int input[]={10};
    int target = 3;
    unsigned int start = 0, end = 0;
    int expect = -1;
    int pos = BinSearchAlgorithmRecursion(input, start, end, target);
    
    printf("TestBinSearch_sort_1_numbers_Recursion(1)--Target %d pos=-1 | Finding pos=%d | Case Result=%s \n", target, pos, (pos==expect)? "Pass":"Failed" );
    int pos2 = BinSearchAlgorithm(input, lengthof(input), target);
    printf("TestBinSearch_sort_1_numbers(1) Case Result=%s \n", (pos==pos2)? "Pass":"Failed" );
    
    target = 10;
    expect = 0;
    pos = BinSearchAlgorithmRecursion(input, start, end, target);
    printf("TestBinSearch_sort_1_numbers_Recursion(2)--Target %d pos=1 | Finding pos=%d | Case Result=%s \n", target, pos, (pos==expect)? "Pass":"Failed" );
    pos2 = BinSearchAlgorithm(input, lengthof(input), target);
    printf("TestBinSearch_sort_1_numbers(2) Case Result=%s \n", (pos==pos2)? "Pass":"Failed" );
    
}



void TestBinSearch_sort_4_numbers()
{
    int input[]={1, 2, 3, 4};
    int target = 3;
    unsigned int start = 0, end = 3;
    int expect = 2;
    int pos = BinSearchAlgorithmRecursion(input, start, end, target);
    printf("TestBinSearch_sort_4_numbers_Recursion--Target %d pos=-1 | Finding pos=%d | Case Result=%s \n", target, pos, (pos==expect)? "Pass":"Failed" );
    int pos2 = BinSearchAlgorithm(input, lengthof(input), target);
    printf("TestBinSearch_sort_4_numbers Case Result=%s \n", (pos==pos2)? "Pass":"Failed" );
    
}

void TestBinSearch_sort_3_numbers()
{
    int input[]={1, 2, 3};
    int target = 3;
    unsigned int start = 0, end = 2;
    int expect = 2;
    int pos = BinSearchAlgorithmRecursion(input, start, end, target);
    printf("TestBinSearch_sort_3_numbers_Recursion[1]--Target %d pos=2 | Finding pos=%d | Case Result=%s \n", target, pos, (pos==expect)? "Pass":"Failed" );
    int pos2 = BinSearchAlgorithm(input, lengthof(input), target);
    printf("TestBinSearch_sort_3_numbers[1] Case Result=%s \n", (pos==pos2)? "Pass":"Failed" );
    
    target = 2;
    expect = 1;
    pos = BinSearchAlgorithmRecursion(input, start, end, target);
    printf("TestBinSearch_sort_3_numbers_Recursion[2]--Target %d pos=1 | Finding pos=%d | Case Result=%s \n", target, pos, (pos==expect)? "Pass":"Failed" );
    pos2 = BinSearchAlgorithm(input, lengthof(input), target);
    printf("TestBinSearch_sort_3_numbers[2] Case Result=%s \n", (pos==pos2)? "Pass":"Failed" );
    
}

void TestBinSearch_sort_2_numbers()
{
    int input[]={1, 3};
    int target = 1;
    unsigned int start = 0, end = 1;
    int expect = 0;
    int pos = BinSearchAlgorithmRecursion(input, start, end, target);
    printf("TestBinSearch_sort_2_numbers_Recursion--Target %d pos=-1 | Finding pos=%d | Case Result=%s \n", target, pos, (pos==expect)? "Pass":"Failed" );
    
    int pos2 = BinSearchAlgorithm(input, lengthof(input), target);
    printf("TestBinSearch_sort_3_numbers Case Result=%s \n", (pos==pos2)? "Pass":"Failed" );
    
}


int BinSearchAlgorithmRecursion(int * a_input, int a_start, int a_end, int a_target)
{
    int start = a_start, end = a_end;
    int midle = (a_start + a_end)/2;
    
    if(start == end)
    {
        if(a_input[start] == a_target)
            return start;
        else
            return -1;
    }
    
    if(a_input[midle]==a_target)
        return midle;
    
    else if(a_input[midle]> a_target)
    {
        end = midle-1;
        return BinSearchAlgorithmRecursion(a_input, start, end, a_target);
    }
    else if(a_input[midle]< a_target)
    {
        start = midle+1;
        return BinSearchAlgorithmRecursion(a_input, start, end, a_target);
    }    
    return -1;
}

int BinSearchAlgorithm(int * a_input, int a_size, int a_target)
{
    int start = 0, end = a_size-1, midle;

    do 
    {
        midle=(start+end)/2;
        if(a_input[midle]==a_target)
            return midle;
        else if(a_input[midle]>a_target)
        {
            end = midle - 1;
        }
        else if(a_input[midle]<a_target)
        {
            start = midle + 1;
        }
    }while(start < end);
    if(start == end && a_input[start] == a_target)
    {
        return start;
    }

    return -1;
}
