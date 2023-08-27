#include<stdio.h>

int nth_fib(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    return nth_fib(n-1)+nth_fib(n-2);
}

int main()
{
    printf("nth fib: %d ",nth_fib(10));
}
 
// 1 1 2 3 5