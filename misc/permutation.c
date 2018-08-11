#include<stdio.h>
#include<string.h>

void print_permute(char str[] , long long int len)
{
    char temp;
    long long int i,j,k;

    if(len==1)
    {
        printf("%s\n",str);
//        return 0;
return;
    }

for(i=len-1;i>=0;i--)
{
    temp = str[len-1];
    str[len-1] = str[i];
    str[i] = temp;

    print_permute(str,len-1);

    temp = str[len-1];
    str[len-1] = str[i];
    str[i] = temp;
}
return ;
//return 0;
}


int main()
{
    long long int i,j,k;
    long long int t;
    char str[100];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%s",str);

        i = strlen(str);

        print_permute(str,i);
    }

    return 0;
}

