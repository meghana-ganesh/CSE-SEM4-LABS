#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int string_matching(char *arr,char *str,int n,int m)
{
    int i;
    for(i=0;i<=n-m;i++)
    {
        int j = 0;
        while(j<m && arr[i+j]==str[j])
        {
            j++;
            
        }
        if(j==m)
                return i;
        
    }
    return -1;
}

int main()
{
    int n,m;

    char *arr = (char*)malloc(20*sizeof(char));
    char *str = (char*)malloc(20*sizeof(char));


    printf("enter the text:");
    scanf("%s",arr);
    fflush(stdin);
    printf("\nenter the pattern:");
    scanf("%s",str);

    n = strlen(arr);
    m = strlen(str);

    printf("\nans:%d",string_matching(arr,str,n,m));
    
}