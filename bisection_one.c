#include<stdio.h>
  float f(float x)
  {
     float z;
     z=10-x*x;
     return z;
  }
  
  int main()
  {
     int count=1,n;
     float a,b,m;
     printf("ENTER THE INTERVALS A and B :- ");
     scanf("%f%f",&a,&b); 
     printf("No.of Iteration : ");
     scanf("%d",&n);
     printf("\n\n The value of f(%f) = %f",a,f(a));
     printf("\n\n The value of f(%f) = %f",b,f(b));
     if(f(a)*f(b)<0)
     {
      m=(a+b)/2;
      while(count<n)
       {
       if(f(a)*f(m)<0){
           b=m;
        }else{
          a=m;
        }
       printf("\n The value of A = %f And B= %f\n",a,b);
       printf("\n\n The Root After %d Iteration is = %f",count,m);
       count++;
       m=(a+b)/2;
     }
     printf("\n Answer is : %f\n\n",m);
    }
    return 0;
   }
   