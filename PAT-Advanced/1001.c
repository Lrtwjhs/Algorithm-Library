 /*
  * 1001. A+B Format (20)
  * Created on： 2016.7.29
  * Author: Lrtwjhs
  */

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int main(int argc, char const *argv[]) {
  int a = 0, b = 0, c = 0;
  scanf("%d %d",&a,&b);
  c = a + b;
  if(c < 0){
    c = -c;
    printf("-");
  }
  if (c >= MAX) {
    printf("%d,%03d,%03d\n",c/MAX,c/1000%1000,c%1000);
  }else if(c >= 1000){
    printf("%d,%03d\n",c/1000,c%1000);
  }else{
    printf("%d\n",c);
  }
  return 0;
}
