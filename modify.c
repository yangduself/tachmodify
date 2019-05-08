#include "info.h"
#define LENGTH 1024
double decode_tach(double *samples, int length, double fsamp);

void test_tach();

int main()

{

 

               test_tach();

}

 

 



 

void test_tach()

{

               double samples[LENGTH];
			   int i = 0;

               for(i =0;i<LENGTH;i++) {

                              samples[i] = cos(2. * 3.141569*((double)i) / 16.);

               }

               double freq = decode_tach(samples, LENGTH, 1.);

               printf("freq: %lf\n", freq);

}

 

double decode_tach(double *samples, int length, double fsamp)

{

               double retval=-1;

               /* YOUR CODE GOES HERE */
			   double a = 1;
			   double *p = NULL;
			   int j = 0;
			   int count = 0;
			   p = samples;
			   //debug
			   for(j=0;j<65;j++)
				{
					printf("%lf ", samples[j]);
				}	
			   for(j=0;j<1025;j++)
			   {
				    //if((samples[j]<1 || samples[j]>0) || (samples[j]>-1 || samples[j]<0))
					if(samples[j]=1 && )
				    {
					   samples[j] = 0;
				    }
				   
					 
			   
					else if(samples[j]=a)
					{
						
						count++;  
			   
					}
					
				j++;
			   }
			   //debug
			   j = 0;
			   printf("seperate!\n");
				for(j=0;j<65;j++)
				{
					printf("%lf ", samples[j]);
				}	
				printf("count is %d.\n", count);
				retval = (double)count*fsamp*60/(double)length;
               return (retval);


}