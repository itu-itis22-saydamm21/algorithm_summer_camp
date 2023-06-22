#include <stdio.h>

int main() {
    int n;
	scanf("%d", &n);
	
	int arr[n];
	
	for(int i = 0; i < n; i++)
	    scanf("%d", &arr[i]);
	
	int len = (n*(n+1))/2;
	
	int res[n][len];
	
	for(int i = 0; i < n; i++){
	    res[n - 1][i] = arr[i];
	}
	
	for(int i = n - 2; i >= 0; i--){
	    for(int j = 0; j < i + 1; j++){
	        res[i][j] = res[i + 1][j] + res[i + 1][j + 1];
	    }
	}
    
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < i + 1; j++){
            
            printf("%d", res[i][j]);
            
            if(j != i)
                printf(" ");
            
            else
                printf("\n");
        }
    }
	return 0;
}