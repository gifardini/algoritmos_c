#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int a, int b){

	if(a < b){
		return a;
	}else{
		return b;
	}
}

int findOverlappingPair(char *str1, char *str2){
     
    int max = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
	char *str = (char *)malloc(sizeof(char)*30);


    free(str);
    return max;
}


int main(){

    int n;
    scanf("%d", &n);

    char **v = (char **)malloc(sizeof(char*)*n);

    for(int i = 0; i < n; i++){
       v[i] =(char *)malloc(sizeof(char)*20);
       scanf("%s", v[i]); 
    }

    char *prim, *seg;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                prim = v[i];
                seg = v[j];             
                
				printf("overlap = %d\n", findOverlappingPair(prim, seg));
            }
        }
    }
    

    for(int i = 0; i < n; i++){
        free(v[i]);
    }
    free(v);
    return 0;
}