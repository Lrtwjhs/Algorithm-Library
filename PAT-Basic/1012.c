/*
 * 1012. 数字分类 (20)
 * Created on： 2016.8.6
 * Author: Lrtwjhs
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #define N 1000

 int main(int argc, char const *argv[]) {
   //按题目要求，求余判断是哪种情况
   int n,reminder;
   int input[N];
   int i;
   int A1 = 0,A2 = 0,A3 = 0,A5 = 0;
   int average = 0,t = 0;//(-1)^t交错和幂
   float A4 = 0.0;

   scanf("%d",&n);
   //输入数据
   for(i = 0; i < n; i++)
       scanf("%d",&input[i]);
   i = 0;
   //数字分类
   while(i < n){
     reminder = input[i] % 5;
     switch (reminder) {
       case 0:
       //A1 = 能被5整除的数字中所有偶数的和
          if(!(input[i]%2))
             A1 = A1 + input[i];
             break;
       case 1:
       //A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...
          A2 = A2 + pow(-1,t)*input[i];
          t++;
             break;
       case 2:
       //A3 = 被5除后余2的数字的个数
          A3++;
             break;
       case 3:
       //A4 = 被5除后余3的数字的平均数，精确到小数点后1位
          A4 = A4 + input[i];
          average++;
             break;
       case 4:
       // A5 = 被5除后余4的数字中最大数字
           if(A5 < input[i])
              A5 =  input[i];
             break;
     }
     i++;
   }
   //输入控制
   if(A1 > 0){
     printf("%d ",A1);
   }else{
     printf("N ");
   }
   //这里的判断条件不能使用A2>2,因为交错和有可能为0
   if(t > 0){
     printf("%d ",A2);
   }else{
     printf("N ");
   }
   if(A3 > 0){
     printf("%d ",A3);
   }else{
     printf("N ");
   }
   if(A4 > 0){
     printf("%.1lf ",A4/average);
   }else{
     printf("N ");
   }
   if(A5 > 0){
     printf("%d",A5);
   }else{
     printf("N");
   }
   return 0;
 }
