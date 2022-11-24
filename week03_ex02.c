#include <stdio.h>

double slow_power(double x, int n) {
	if (n == 1) return x;
	else return x * slow_power(x, n - 1);
}

int main() {
	double x;
	int n;
	printf("x의 n제곱 계산, x와 n을 입력하시오 : ");
	scanf_s("%lf %d", &x, &n);
	printf("%.6lf", slow_power(x, n));
	return 0;
}