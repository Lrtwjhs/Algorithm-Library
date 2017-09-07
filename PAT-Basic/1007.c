 /*
  * 1007. 素数对猜想 (20)
  * Created on： 2016.7.29
  * Author: Lrtwjhs
  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Max 100000

  int main(int argc, char *argv[]){
  	int prime[Max];
  	int n,i,j;
  	int countPrime;
  	countPrime = 0;
  	scanf("%d", &n);
  	//素数简单打表
  	for (i = 0; i < Max; i++){
  		prime[i] = 1;
  	}
  	prime[0] = 0; prime[1] = 0;
  	for(i = 2; i <= sqrt(Max); i++){
  		if(1 == prime[i]){
  			for(j = i*2; j < Max; j += i)
  				prime[j] = 0;
  		}
  	}
  	//统计素数对
  	for(i = 2; i <= n; i++ ){
  		if(1 == prime[i] && i - j == 2){
  			countPrime++;
  			j = i;
  			continue;
  		}
  		if(1 == prime[i])
  			j = i;
  	}
  	//输出素数对个数
  	printf("%d\n", countPrime);
  	return 0;
  }




// 解法二：
#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
        if (n == 1)
                return 0;
        else if (n == 2 || n == 3)
                return 1;
        else if (n % 2 == 0)
                return 0;
        else {
                int i, end;
                end = (int)sqrt(n) + 1;
                for (i = 3; i < end; i += 2) {
                        if (n % i == 0)
                                return 0;
                }
                return 1;
        }
}

int main(void)
{
        int n;
        scanf("%d", &n);
        int pair_cnt = 0;
        int i;
        for (i = 2; i < n; i++) {
                if (isPrime(i) &&
                    isPrime(i + 2) &&
                    (i + 2) <= n){
                    //    printf("%d,%d  ",i,i+2);
                        pair_cnt++;
                    }

        }
        printf("%d\n", pair_cnt);

        return 0;
}
