/*
 * 1011. A+B和C (15)
 * Created on： 2016.8.6
 * Author: Lrtwjhs
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
  int i,n;
  long a,b,c;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%ld%ld%ld",&a,&b,&c);
    if(a+b>c)
        printf("Case #%d: true\n",i+1);
    else
        printf("Case #%d: false\n",i+1);
  }
  return 0;
}
