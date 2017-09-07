 /*
  * 1008. 数组元素循环右移问题 (20)
  * Created on： 2016.7.29
  * Author: Lrtwjhs
  */

 #include <stdio.h>
 #include <stdlib.h>

  int main(int argc, char const *argv[]){

  	int n,m,count,i;
  	int Input[100];
  	count = 0;
  	scanf("%d %d", &n,&m);
  	m = n - m % n;
  	//输入数据
  	for(i = 0; i < n; i++){
  		scanf("%d",&Input[i]);
  	}
  	//按要求输出数据
  	for(i = m; i < n; i++){
  		printf("%d", Input[i]);
  		count++;
  		if(count != n){
  			printf(" ");
  		}
  	}
  	for(i = 0; i < m; i++){
  		printf("%d", Input[i]);
  		count++;
  		if(count != n){
  			printf(" ");
  		}
  	}
  	printf("\n");
  	return 0;
  }

//解法二
 #include <stdio.h>
int main()
{
    int M,N,i;
    int A[200]={0};
    scanf("%d %d",&N,&M);//输入数组长度及要要移动元素的个数
    M=M%N;
    for(i=0;i<N;i++)//为数组输入元素
    {
        scanf("%d",&A[i]);

        A[N+i]=A[i];//数组备份


    }
    for(i=0;i<N;i++)
    {
        A[i]=A[N-M+i];//数组元素替换
    }
for(i=0;i<N;i++)
    {
        printf("%d",A[i]);//输出
        if(i!=N-1){//判段是否为最后一个，若是则不输出空格
            printf(" ");
        }

    }
    return 0;
}
