 /*
  * 1001. 害死人不偿命的(3n+1)猜想 (15)
  * Created on： 2016.7.15
  * Author: Lrtwjhs
  */

#include <stdio.h>

 int main(void){

     int n;//题目中n
     int count=0;//计数

     scanf("%d",&n);

     while(n!=1){
         if(n%2==0){
             n/=2;
         } else{
             n=(3*n+1)/2;
         }
         count++;
     }

     printf("%d\n",count);

     return 0;
 }
