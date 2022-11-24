#include <stdio.h>

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}
int main(){
    int a , b;
    printf("두 개의 수를 입력하시오 (a b) : ");
    scanf_s("%d %d",&a, &b);
    printf("gcd : %d", gcd(a,b));
}
