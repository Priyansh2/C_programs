 #include <stdio.h>

     #include <stdlib.h>

     #define MAX_LENGTH 9999

     void print_array(const int a[],int size)

     {

         int i=0;

         for(i=0;i<size;i++)

         {

             printf("%d,",a[i]);

        }

        printf("\n");

    }

     

    /*

    assume a[i]>0

    */

    void counting_sort(const int a[],int b[],int size,int maxvalue)

    {

        int i=0;

        for(i=0;i<size;i++)

        {

            b[i]=0;

        }

     

        int temp[maxvalue+1];

        for(i=0;i<=maxvalue;i++)

        {

            temp[i]=0;

        }

     

        for(i=0;i<size;i++)

        {

            temp[a[i]]+=1;

        }

     

        for(i=1;i<=maxvalue;i++)

        {

            temp[i]=temp[i]+temp[i-1];

        }

     

        for(i=size-1;i>=0;i--)

        {

            b[temp[a[i]]-1]=a[i];

            temp[a[i]]=temp[a[i]]-1;

        }

    }

     

    /*

    handle a[i] <0

    */

    void counting_sort2(const int a[],int b[],int size,int maxvalue)

    {

        int i=0;

        int copyofa[size];

        int min=0;

        for(i=0;i<size;i++)

        {

            b[i]=0;

            if(min>a[i])

            {

                min=a[i];

            }

        }

     

        int newmaxvalue=maxvalue-min;

       for(i=0;i<size;i++)

        {

            copyofa[i]=a[i]-min;

        }

     

        int temp[newmaxvalue+1];

        for(i=0;i<=newmaxvalue;i++)

        {

            temp[i]=0;

        }

     

        for(i=0;i<size;i++)

        {

            temp[copyofa[i]]+=1;

        }

     

        for(i=1;i<=newmaxvalue;i++)

        {

            temp[i]=temp[i]+temp[i-1];

        }

     

        for(i=size-1;i>=0;i--)

        {

            b[temp[copyofa[i]]-1]=copyofa[i];

            temp[copyofa[i]]=temp[copyofa[i]]-1;

        }

     

        for(i=0;i<size;i++)

        {

            b[i]=b[i]+min;

        }

    }

     

    void bubble_sort(const int a[],int b[],int size)

   {

       int i=0;

       int j=0;

       int temp;

    

       for(i=0;i<size;i++)

       {

           b[i]=a[i];

       }

    

       for(i=0;i<size;i++)

       {

           for(j=i;j<size;j++)

           {

               if(b[j]<b[i])

               {

                   temp=b[i];

                   b[i]=b[j];

                   b[j]=temp;

               }

           }

       }

   }
