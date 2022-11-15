#include <stdio.h>
#include <string.h>

#define SIZE 512

int maxPeriod(char *s){
    int n = strlen(s);
    int r[n+1];
    memset(r, 0, (n + 1)*sizeof(int));
    for(int i = 1; i < n; i++){
        int z = r[i];
        while((s[z] != s[i]) && (z > 0)){
            z = r[z];
        }
        if(s[z] == s[i]){
            r[i + 1] = z + 1;
        }else{
            r[i + 1] = 0;
        }
    }
    return n - r[n];
}

int esercizio12(){
    char s[SIZE];
    scanf("%s", s);
    printf("%d", maxPeriod(s));
}
