#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Shift_Table(char *text,char* pattern,int n,int m,int *table)
{
    for(int i=0;i<n-1;i++)
    {
        table[text[i]] = m;      //initialize all elements of table with m
    }
    for(int i=0;i<m-1;i++)
    {
        table[pattern[i]] = m-i-1;   //reassign the bad symbol shift table elements value or make bad symbol shift table
    }

}

int Horspool(char *text,char*pattern,int n,int m,int *table)
{

    int i,k;
    i = m - 1;                 //position of the patterns right end
    while(i <= n-1)
    {
        k = 0;                 //no. of matched characters
        while( (k <= m-1) && (pattern[m-k-1] == text[i-k]))
        {
            k = k + 1;
        }
        if(k == m)
            return i-m+1;
        else
            i = i + table[text[i]];
    }
    return -1;

}

int main()
{
    char *text = (char*)malloc(20*sizeof(char));
    char *pattern = (char*)malloc(20*sizeof(char));
    int* table = (int*)malloc(100*sizeof(int));

    printf("enter the string:");
    gets(text);
    printf("\nenter the pattern:");
    gets(pattern);
    Shift_Table(text,pattern,strlen(text),strlen(pattern),table);
    printf("%d ",Horspool(text,pattern,strlen(text),strlen(pattern),table));
}