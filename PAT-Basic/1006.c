 /*
  * 1006. 换个格式输出整数 (15)
  * Created on：2016.7.29
  * Author: Lrtwjhs
  */

  #include <stdio.h>
  #include <stdlib.h>

  int main(int argc, char *argv[]){
          int input;
          int b,s,g,i;
          scanf("%d",&input);
          g = input % 10;
          s = input / 10 % 10;
          b = input /100;
          for(i = 0; i < b; i++)
            printf("B");
          for(i = 0; i < s; i++)
            printf("S");
          for(i = 1; i <= g; i++)
            printf("%d", i);

          return 0;
  }
