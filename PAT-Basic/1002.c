 /*
  * 1002. 写出这个数 (20)
  * Created on： 2016.7.15
  * Author: Lrtwjhs
  */

#include <stdio.h>
#include <string.h>
int main(){
    //输入
    char c[100];
    int a[5];
    char pinyin[][9] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    int i,n,t;
    n = 0;
    t = 0;
    gets(c);
    //计算
    for(i=0;i<strlen(c);i++)
        n = n + c[i] - 48;
    while (n!=0)
    {
        a[t] = n%10;
        n = n/10;
        t++;
    }
    //输出
    printf("%s",pinyin[a[t-1]]);
    for(i=t-2;i>=0;i--)
        printf(" %s",pinyin[a[i]]);
}
