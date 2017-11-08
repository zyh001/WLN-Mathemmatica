#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 1000000

int partition(int n);

int partitions[100000]={0};

int main(int argc, char **argv)
{

   clock_gettime(CLOCK_MONOTONIC, &start);

   i=0;

   while(partition(i++)!=0);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed=(end.tv_sec-start.tv_sec)+(double)(end.tv_nsec-start.tv_nsec)/1000000000;

   printf("%d\n", i-1);                                                      
   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int partition(int n)
{
   int i, pentag, res=0;

   if(n<0)
      return 0;

   if(n==0)
   {
      partitions[n]=1;
      return 1;
   }

   else if(n<N && partitions[n]!=0)
      return partitions[n];

   i=1;
   pentag=1;

   while(n-pentag>=0)
   {
      res+=partition(n-pentag);

      i=-i;
      pentag=(3*i*i-i)/2;
      res+=partition(n-pentag);

      i=-i;
      i++;
      pentag=(3*i*i-i)/2;
      res-=partition(n-pentag);

      i=-i;
      pentag=(3*i*i-i)/2;
      res-=partition(n-pentag);

      i=-i;
      i++;
      pentag=(3*i*i-i)/2;
   }

   partitions[n]=res%N;

   return res%N;
}
