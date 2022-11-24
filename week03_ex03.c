#include <stdio.h>

int fiv(int n){
    if(n==1 || n==2) return 1;
    return fiv(n-1)+fiv(n-2);
}
int main(void){
	int x;
	printf("양의 정수를 입력하시오 : ");
	scanf_s("%d", &x);
	printf("%d",fiv(x));
	return 0;
}