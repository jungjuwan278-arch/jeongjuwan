#include <stdio.h>
int main() {
float ave_score;
float math, english, science, programming;
printf("수학, 영어, 과학, 컴퓨터프로그래밍점수를각각입력해주세요! : ");
scanf("%f %f %f %f", &math, &english, &science, &programming);
ave_score =
(math + english + science + programming) / 4; // 4 과목의평균을구한다.
printf("당신의평균점수는%f 입니다\n", ave_score);
if (ave_score >= 90) {
printf("당신은우등생입니다. ");
} else if (ave_score >= 30) {
printf("조금만노력하세요!. \n");
} else {
printf("공부를발로합니까? \n");
}
return 0;
}