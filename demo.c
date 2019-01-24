#include <stdio.h>

int super_complex_function() {
	int k = 0;
	int j = 1;
	int g = 2;
	for (int i = 0; i < 1000; ++i) {
		k *= g + j;
		k++;
		j--;
		g *= 2;
		int p = k % 976;
	}
	return k;
}

void fail() {
	printf("Wrong!\n");
}

void success() {
	printf("Correct!\n");
}

int main() {
	int i = 0;
	printf("Guess the secret number: ");
	scanf("%d", &i);
	if (i != super_complex_function()) {
		fail();
	}
	else {
		success();
	}
}
