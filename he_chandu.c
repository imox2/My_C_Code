#include <stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	char arrayOfWords[T][30];
	int i,j,len=0;
    for (i=0; i< T; i++) {
    scanf ("%s" , arrayOfWords[i]);
    }
    for(i=0;i<T;++i){
    	for(j=0;arrayOfWords[i][j]!='\0';++j){
    		len++;
    	}
    	for(j=len-1;j>=0;--j)    		
    		printf ("%c" , arrayOfWords[i][j]);
    	len = 0;
    	printf("\n");
    }
	return 0;
}

