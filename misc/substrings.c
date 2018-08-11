#include<stdio.h>
#include<string.h>
int min(int a, int b)
{
    if(a<b)
        return a;
    else return b;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else return b;
}

int main()
{
    char s1[100];
    char s2[100];

    scanf("%s %s",s1,s2);

    int minlen;
    int maxlen;
    int i,j,l1,l2;
    int flag=0;
    l1 = strlen(s1);

    l2 = strlen(s2);
    minlen = min(l1,l2);
    maxlen = max(l1,l2);

    for(i=0;i<=(maxlen-minlen);i++)
    {
        for(j=0;j<minlen;j++)
        {
            if(minlen==l1)
            {


                if(s1[j]!=s2[i+j])
                    break;
            }


            else
            {
                if(s2[j]!=s1[i+j])
                    break;
            }
        }
        if(j==minlen)
        {
            flag=1;
            if(j==l1)
            {
                printf("string 1 is substring of string 2\n");
                break;
            }

            else if(j==l2){

                printf("string 2 is substring of string 1\n");
                break;
            }
        }

    }

    if(flag==0)
        printf("strings are not substring of each other\n");

    return 0;
}
