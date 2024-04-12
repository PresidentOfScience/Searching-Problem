#include <stdio.h>
#include <string.h>

struct study{
	int nilai;
	char nama[20];
};

void merge(struct study result[], int left, int right){
	if(left == right) return;
	int mid = (left + right)/2;
	merge(result, left, mid);
	merge(result, mid+1, right);
	
	struct study temp[right-left+1];
	int leftcurr = left, leftmerge = mid, rightcurr = mid+1, rightmerge = right, idx = 0;
	while(leftcurr <= leftmerge && rightcurr <= rightmerge){
		if(result[leftcurr].nilai < result[rightcurr].nilai){
			temp[idx++] = result[rightcurr++];
		}
		else if(result[leftcurr].nilai == result[rightcurr].nilai){
			if(strcmp(result[leftcurr].nama, result[rightcurr].nama) > 0){
				temp[idx++] = result[rightcurr++];
			}
			else{
				temp[idx++] = result[leftcurr++];
			}
		}
		else{
			temp[idx++] = result[leftcurr++];
		}
	}
	while(leftcurr <= leftmerge){
		temp[idx++] = result[leftcurr++];
	}
	while(rightcurr <= rightmerge){
		temp[idx++] = result[rightcurr++];
	}
	idx = 0;
	
	for(int i=left; i<=right; i++){
		result[i] = temp[idx++];
	}
}

int solve(){
	int N;
	char name[20];
	scanf("%d", &N);
	struct study result[N];
	for(int i=0; i<N; i++){
		getchar();
		scanf("%[^#]#%d", result[i].nama, &result[i].nilai);
	}
	getchar();
	scanf("%s", name);
	merge(result, 0, N-1);
	for(int i=0; i<N; i++){
		if(!strcmp(result[i].nama, name)){
			return i+1;
		}
	}
}
int main(){
	int T;
	scanf("%d", &T);
	for(int i=1; i<=T; i++){
		printf("Case #%d: %d\n", i, solve());
	}
	return 0;
}
