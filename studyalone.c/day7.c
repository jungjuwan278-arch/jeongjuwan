//배열의 평균출력하기//
#include <stdio.h>
 int main(){
     int arr[5]; // 성적 저장 베열
     int i, ave=0;
     for (i=0; i<5;i++)           //학생들의 성적 입력받는 부분
     
     {printf("%d 번째 학생의 성적은?", i+1);
        scanf("%d", &arr[i]);
        }
     for (i=0; i<5;i++)    //전체학생들의 성적 합 구하는 부분
     { ave= ave+arr[i];
        }
        //평균이므로 5로 나눠준다.
        
             printf("전체 학생들의 평균 점수는 %d입니다.\n", ave/5);
             return 0;
 }
        