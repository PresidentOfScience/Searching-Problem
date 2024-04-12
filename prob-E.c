#include <stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int sort(int arr[], int arrSize){
    for(int i = 0;i<arrSize;i++){
        for(int j = 0;j<arrSize-1-i;j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int search(int arr[], int size, int find){
	int left = 0, right = size-1, mid;
	while(left <= right){
		mid = (left+right)/2;
		if(find == arr[mid]) return mid;
		else if(find < arr[mid]) right = mid-1;
		else left = mid+1;
	}
	return -1;
}

int main(){
	int K, N, F, MMR[1200];
	scanf("%d", &K);
	for(int i=0; i<K; i++){
		scanf("%d", &N);
		for(int j=0; j<N; j++){
			scanf("%d", &MMR[j]);
		}
		scanf("%d", &F);
		sort(MMR, N);
		int result = search(MMR, N, F);
		if(result == -1) printf("CASE #%d: %d %d\n", i+1, result, result);
		else if(result == N-1) printf("CASE #%d: %d %d\n", i+1, MMR[result-1], MMR[result]);
		else printf("CASE #%d: %d %d\n", i+1, MMR[result], MMR[result+1]);
	}
	
	return 0;
}
