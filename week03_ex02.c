#include <stdio.h>

double slow_power(double x, int n) {
	if (n == 1) return x;
	else return x * slow_power(x, n - 1);
}

int main() {
	double x;
	int n;
	printf("x�� n���� ���, x�� n�� �Է��Ͻÿ� : ");
	scanf_s("%lf %d", &x, &n);
	printf("%.6lf", slow_power(x, n));
	return 0;
}