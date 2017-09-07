 /*
  * 1009. 说反话 (20)
  * Created on： 2016.7.29
  * Author: Lrtwjhs
  */

  #include <stdio.h>
  #include <string.h>
  #define MAXN 80+10
  #define HALFAMXN 40+5

  char input[MAXN];
  char output[HALFAMXN][MAXN];

  int main(){
    int i = 0, j = 0, num = 0;
    memset(input, 0, sizeof(input));
    memset(output, 0, sizeof(output));
    gets(input);
    for(; i < sizeof(input); i++){
    	if(input[i] == ' '){
    		j = 0;
    		num++;
    		continue;
    	}
    	output[num][j++] = input[i];
    }
    for(; num > 0; num--){
    	printf("%s ", output[num]);
    }
    printf("%s\n", output[num]);
  	return 0;
  }
