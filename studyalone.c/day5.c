#include <stdio.h>
int main(){       
    int i;
    int subjet,score;
    double sum_score=0;

    printf("몇 개의 과목 점수를 입력 받을 건가요?");
    scanf("%d",&subjet);

    printf("\n 각 과목의 점수를 입력하세요:\n");
    for(i=1;i<=subjet;i++){
        printf("과목%d",i);
        scanf("%d",&score);
        sum_score=sum_score+score;
    }
     printf("전체 과목의 평균은: %.2f\n",sum_score/subjet);
    return 0;
}
