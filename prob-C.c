#include <stdio.h>
#include <string.h>

int main(){
	int N, M, max = -1, trace[1000];
	scanf("%d %d", &N, &M);
	int A1[N], A2[M];
	for(int i=0; i<N; i++){
		scanf("%d", &A1[i]);
	}
	memset(trace, 0, sizeof(trace));
	for(int i=0; i<M; i++){
		scanf("%d", &A2[i]);
		trace[A2[i]]++;
	}
	for(int i=0; i<N; i++){
		if(A1[i] > max && !(trace[A1[i]])){
			max = A1[i];
		}
	}
	printf("Maximum number is %d\n", max);
	
	return 0;
}
