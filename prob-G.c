#include <stdio.h>

int main(){
	int T;
	scanf("%d", &T); getchar();
	for(int i=1; i<=T; i++){
		int N, K, A[10001], count = 0;
		scanf("%d %d", &N, &K); getchar();
		for(int j=0; j<N; j++){
			scanf("%d", &A[j]); getchar();
		}
		for(int j=0; j<N; j++){
			if(A[j] >= K){
				count++;
			}
		}
		printf("Case #%d: %d\n", i, count);
		count = 0;
	}
}
