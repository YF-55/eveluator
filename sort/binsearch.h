#include <stdio.h>

#define lengthof(a) (sizeof(a) / sizeof((a)[0]))

void TestBinSearch_sort_4_numbers();
void TestBinSearch_sort_1_numbers();
void TestBinSearch_sort_3_numbers();
void TestBinSearch_sort_2_numbers();

int BinSearchAlgorithmRecursion(int * a_input, int a_start, int a_end, int a_target);
int BinSearchAlgorithm(int * a_input, int a_size, int a_target);
