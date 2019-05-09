#include "info.h"
#define LENGTH 1024
#define DEBUG
double decode_tach(double *samples, int length, double fsamp);

void test_tach();

int main()

{

 

               test_tach();

}

 

 



 

void test_tach()

{

               double samples[LENGTH] = {0};
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
			   //double a = 1;
			   //double *p = NULL;
			   int j = 0;
			   int countP = 0;
			   
			  // p = samples;
			   //debug
			   #ifdef DEBUG
			   for(j=0;j<65;j++)
				{
					printf("%lf ", samples[j]);
				}	
				#endif
			   for(j=0;j<1025;j++)
			   {
				    if((samples[j]<0.98 && samples[j]>0) || (samples[j]>-0.98 && samples[j]<0))
					//if(!(samples[j]==1 || samples[j]==-1) )
				    {
					   samples[j] = 0;
				    }
				   
					 
			   
					else if(samples[j]>0.98)
					{
						
						countP++;  
			   
					}
			
					
				
			   }
			   //debug
			   #ifdef DEBUG
			   printf("seperate!\n");
			   
				for(j=0;j<65;j++)
				{
					printf("%lf ", samples[j]);
				}
				
				printf("countP is %d.\n", countP);
				
				#endif
				retval = (double)countP*fsamp*60/(double)length;
				
               return (retval);


}