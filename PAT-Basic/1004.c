 /*
  * 1004. 成绩排名 (20)
  * Created on： 2016.7.19
  * Author: Lrtwjhs
  */

 #include <stdio.h>
 #include <stdlib.h>

  int main(int argc, char *argv[]){
  	int n,i;
  	char studentName[1000][11];
  	char studentId[1000][11];
  	int grade[1000];
  	//nMax,nMin为最大最小的成绩，iMax,iMin为下标号
  	int nMax = 0, nMin = 100, iMax = 0, iMin = 0;
  	scanf("%d",&n);
  	for(i = 0; i < n; i++){
  		scanf("%s %s %d",studentName[i],studentId[i],&grade[i]);
  		if(grade[i] > nMax){
  			nMax = grade[i];
            iMax = i;
  		}
  		if(grade[i] < nMin){
  			nMin = grade[i];
  			iMin = i;
  		}
  	}
  	printf("%s %s\n", studentName[iMax],studentId[iMax]);
  	printf("%s %s\n", studentName[iMin],studentId[iMin]);
  	return 0;
  }
