#include <stdio.h>

void merge(long long int arr[], int l, int r){
	if(l == r) return;
	int m = (l+r)/2;
	merge(arr, l, m);
	merge(arr, m+1, r);
	
	long long int temp[r-l+1];
	int left = l, leftm = m, right = m+1, rightm = r, idx = 0;
	
	while(left <= leftm && right <= rightm){
		if(arr[left] > arr[right]){
			temp[idx++] = arr[right++];
		}
		else{
			temp[idx++] = arr[left++];
		}
	}
	while(left <= leftm){
		temp[idx++] = arr[left++];
	}
	while(right <= rightm){
		temp[idx++] = arr[right++];
	}
	idx = 0;
	for(int i=l; i<=r; i++){
		arr[i] = temp[idx++];
	}
}

int main(){
	int n, count = 0;
	scanf("%d", &n);
	long long int arr[n];
	for(int i=0; i<n; i++){
		scanf("%lld", &arr[i]);
	}
	merge(arr, 0, n-1);
	long long int power;
	scanf("%lld", &power);
	for(int i=0; i<n; i++){
		if(power - arr[i] >= 0){
			power -= arr[i];
			count++;
		}
		else{
			break;
		}
	}
	printf("%d\n", count);

	return 0;
}
