#include <stdio.h>

int sub(int n) {
	int result = 0;
	for (int i = n; i > 0; i -= 3) {
		result += i;
	}
	return result;
}

int main(){
    printf("%d", sub(10));
    return 0;
}