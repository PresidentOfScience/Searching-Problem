#include <stdio.h>
#include <string.h>

struct kamus{
	char pendek[100];
	char asli[100];
};

int main(){
	FILE *fp = fopen("testdata.in", "r");
	
	int T, TC;
	fscanf(fp, "%d\n", &T);
	struct kamus data[T];
	
	for(int i=0; i<T; i++){
		fscanf(fp, "%[^#]#%s\n", &data[i].pendek, &data[i].asli);
	}
	fscanf(fp, "%d\n", &TC);
	char tc[200];
	for(int i=0; i<TC; i++){
		fscanf(fp, "%[^\n]\n", &tc);
		char *akhir = &tc[0];
		char isi[200];
		int checker;
		printf("Case #%d:\n", i+1);
		for(int j=0; j<strlen(tc); j++){
			checker = 0;
			if(tc[j] == ' '){
				strncpy(isi, akhir, &tc[j] - akhir);
				isi[&tc[j] - akhir] = '\0';
				for(int k=0; k<T; k++){
					if(strcmp(isi, data[k].pendek) == 0){
						printf("%s ", data[k].asli);
						checker = 1;
						break;
					}
				}
				if(checker == 0){
					printf("%s ", isi);
				}
				akhir = &tc[j+1];
			}
		}
		for(int k=0; k<T; k++){
			if(strcmp(akhir, data[k].pendek) == 0){
				printf("%s\n", data[k].asli);
				checker = 1;
				break;
			}
		}
		if(checker == 0){
			printf("%s\n", akhir);
		}
	}
	
	return 0;
}
