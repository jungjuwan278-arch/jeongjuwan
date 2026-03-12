/* 소수프로그램*/
#include <stdio.h>
int main() {
              /* 우리가소수인지판별하고있는수*/
int guess = 5; /* 소수의배열*/
int prime[1000]; /*현재까지찾은(소수의개수- 1) 아래두개의소수를
                         미리찾았으므로 초기값은1 이된다. */
int index = 1; /* for 문변수*/
int i;        /* 소수인지판별위해쓰이는변수*/
int ok;/* 처음두소수는특별한경우로친다*/
prime[0] = 2;
prime[1] = 3;
for  (;;){
ok = 0;

  for (i = 0; i <= index; i++) {
   if (guess % prime[i] != 0) {
    ok++;
} else {
break;
}
}
if (ok == (index + 1)) {
index++;
prime[index] = guess;
printf("소수 : %d \n", prime[index]);
if (index == 999) break;
}
guess += 2;
}
return 0;
}