 /*
  * 1005. 继续(3n+1)猜想 (25)
  * Created on： 2016.7.23
  * Author: Lrtwjhs
  */

#include <stdio.h>
#include <stdlib.h>
#define tMax 5000

int cmp(const void *a, const void *b){
    return -(*(int *)a - *(int *)b);
}
int main(int argc, char *argv[]){
	int Input[101];
	//测试过100以内最大的过程能达到4616，也可以通过判断减小数组大小，这里以空间换时间
	int Mark[tMax];
	int k,i,n,flag;
	flag = 1;//控制输出格式
	for(i = 0; i < tMax; i++)
		Mark[i] = 0;
	Mark[1] = 1;
	scanf("%d",&k);
	//代码核心部分，打表
	for(i = 0; i < k; i++){
		scanf("%d",&Input[i]);
	}
	//开始对输入的数据进行卡拉兹（Callatz）猜想打表
	for(i = 0; i < k; i++){
		n = Input[i];
		if(1 != Mark[n]){
			while(n != 1){
				n = n % 2 ? (3*n+1) / 2 : n / 2;
				//进行打表后除了自己本身其它的步骤数都置1
				Mark[n] = 1;
			}
		}
	}
	//将输入数据进行降序快排
	qsort(Input,k,sizeof(Input[1]),cmp);
	//格式输出部分
	for (i = 0; i < k; i++){
		if((0 == Mark[Input[i]]) && flag){
			printf("%d", Input[i]);
			flag = 0;
			continue;
		}
		if(0 == Mark[Input[i]]){
			printf(" %d",Input[i]);
		}
	}
	return 0;
}
