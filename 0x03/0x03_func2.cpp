#include<bits/stdc++.h>
using namespace std;

int idx[101];

int func2(int arr[], int N) {
    fill(idx, idx+101, 0);
	for (int i = 0; i < N; i++) {
        if(idx[100 - arr[i]] == 1)
            return 1;
        idx[arr[i]] = 1;
	}
	return 0;
}

int main(void){
    int arr[3][4] = { {1, 52, 48},{50, 42}, {4, 13, 63, 87} };
	printf("%d \n", func2(arr[0], 3));
	printf("%d \n", func2(arr[1], 2));
	printf("%d \n", func2(arr[2], 4));
}