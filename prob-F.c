#include <stdio.h>

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
	int N, opinion[120];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &opinion[i]);
	}
	int result = search(opinion, N, 1);
	if(result == -1) printf("easy\n");
	else printf("not easy\n");
	
	return 0;
}
