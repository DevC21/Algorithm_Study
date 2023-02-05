#include<stdio.h>

int func1(int N) {
	int total = 0;
	for (int i = 0; i <= N; i++) {
		if (i % 3 == 0 || i % 5 == 0)
			total += i;
	}

	return total;
}

int func2(int arr[], int N) {

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if ( (arr[i] + arr[j]) == 100)
				return 1;
		}
	}
	return 0;
}

// O(N) 풀이법 (최초 풀이)
//int func3(int N) {
//	for (int i = 0; i <= N; i++) {
//		if ( i * i == N)
//			return 1;
//	}
//	return 0;
//}

// O(√N) 풀이법
int func3(int N) {
	for (int i = 0; i * i <= N; i++) {
		if (i * i == N)
			return 1;
	}
	return 0;
}

int func4(int N) {
	int num = 1;
	for (int i = 1; i <= N; i *= 2) {
		num = i;
	}
	return num;
}

int main(void) {
	printf("%d \n", func1(16));
	printf("%d \n", func1(34567));
	printf("%d \n", func1(27639));

	int arr[3][4] = { {1, 52, 48},{50, 42}, {4, 13, 63, 87} };
	printf("%d \n", func2(arr[0], 3));
	printf("%d \n", func2(arr[1], 2));
	printf("%d \n", func2(arr[2], 4));

	printf("%d \n", func3(9));
	printf("%d \n", func3(693953651));
	printf("%d \n", func3(756580036));

	printf("%d \n", func4(5));
	printf("%d \n", func4(97615282));
	printf("%d \n", func4(1024));
}