/*
 * 1010. 一元多项式求导 (25)
 * Created on： 2016.8.6
 * Author: Lrtwjhs
 */

 #include <stdio.h>
 #include <string.h>

 int main(){
   int n, e, flag = 0;
   while (scanf("%d%d", &n, &e) != EOF) {
     if(n*e){
       if(flag)
          printf(" ");
       else
          flag = 1;
       printf("%d %d", n*e, e-1);
     }
   }
   if(!flag)
      printf("0 0");
   return 0;
 }
