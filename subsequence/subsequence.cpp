// subsequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Subsequence （POJ No.3061）
//给定长度为n 的数列整数a0,a1,…,an-1 以及整数S。求出总和不小于S 的连续子序列的长度的
//最小值。如果解不存在，则输出0。

#define MIN(a, b, c) if(a<b) c = a; 
const int MAX=100;

int solve(int *a, int n, int S)
{
    int sum[MAX];
    sum[0] = a[0];
    for(int i=1; i<n; i++)
    {
        sum[i] = sum[i-1] + a[i];
    }

    if(sum[n-1] < S)
        return 0;

    int min_len=n;
    int pos = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(sum[j]>=S+sum[i])
            {
                //MIN(j-i, min_len, min_len)
                if(j-i < min_len)
                {
                    min_len = j-i;
                    pos = i+1;
                }
            }
        }
    }
    printf("%d(", min_len);
    for(int k=pos; k<pos+min_len-1;k++)
    printf("%d+", a[k]);
    printf("%d)\n", a[pos+min_len-1]);
    return min_len;
}

template <typename a, typename b>
class base
{
};
template <typename a, typename b>
class child: base<a, b>
{
};


int _tmain(int argc, _TCHAR* argv[])
{
    int n = 10;
    int S = 15;
    int a[] = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};

    solve(a, n, S);

    n = 5;
    S = 11;
    int a2[] = {1,2 ,3,4,5};
    solve(a2, n, S);

	return 0;
}

