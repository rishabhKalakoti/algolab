#include<stdio.h>
void greedKnap(int n, float wt[], float val[], int W) 
{
   float x[n], tp = 0, temp, ratio[n];
   int i, j, u;
   u = W;
 
   for (i = 0; i < n; i++)
      x[i] = 0.0;
 //sorting weigths and values acoording to the ratio
	 for (i = 0; i < n; i++) {
      ratio[i] = val[i] / wt[i];
   }
 
   for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
 
            temp = wt[j];
            wt[j] = wt[i];
            wt[i] = temp;
 
            temp = val[j];
            val[j] = val[i];
            val[i] = temp;
         }
      }
   }
   for (i = 0; i < n; i++) {
      if (wt[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp = tp + val[i];
         u = u - wt[i];
      }
   }
 
   if (i < n)
      x[i] = u / wt[i];
 
   tp = tp + (x[i] * val[i]);
 
   printf("\nThe result vector(greedy) is:- ");
   for (i = 0; i < n; i++)
      printf("%f\t", x[i]);
 
   printf("\nMaximum val(greedy) is:- %f\n", tp);
 
}
