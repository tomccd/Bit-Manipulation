#include <stdio.h>

int main()
{
    float a = 7.5;
    int i;
    int * p;

    p = &a;
    for (i = sizeof(int) * 8 - 1; i >= 0; i--)
    {   
        printf("%d\n", (*p) >> i & 1); 
    }   

    return 0;
}