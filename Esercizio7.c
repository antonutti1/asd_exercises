#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 10000
#define MAX 1000

char peek();
int scanArray2(int *a);
int sommaIntervallo(int *n, int i, int j);
int prodottoIntervallo(int *n, int i, int j);
int maxIntervallo(int *n, int i, int j);

/**
 * input=5 0 3 1 13 7 5
   0 6 2 4 3 6
 * output=34 17 26
 */

int esercizio7() {
    int n[MAX];
    int size;

    int a[MAX];
    int size2;

    size = scanArray2(n);
    size2 = scanArray2(a);

    for(int i=0; i<size2; i+=2){
        printf("%d", sommaIntervallo(n, a[i], a[i+1]));

        if(i<(size2-2))
            printf("%c", ' ');
    }

    printf("%c", '|');

    for(int i=0; i<size2; i+=2){
        printf("%d", prodottoIntervallo(n, a[i], a[i+1]));

        if(i<(size2-2))
            printf("%c", ' ');
    }

    printf("%c", '|');

    for(int i=0; i<size2; i+=2){
        printf("%d", maxIntervallo(n, a[i], a[i+1]));

        if(i<(size2-2))
            printf("%c", ' ');
    }

    return 0;
}

int scanArray2(int *a){
    int n;
    int size = 0;
    while(peek() != '\n'){
        scanf("%d", &n);
        a[size] = n;
        size++;
    }

    fgetc(stdin);
    return size;
}

char peek(){
    char next = fgetc(stdin);
    ungetc(next, stdin);
    return next;
}

int sommaIntervallo(int *n, int i, int j){
    int res = 0;
    for(; i<=j; i++){
        res += n[i];
    }
    return res;
}

int prodottoIntervallo(int *n, int i, int j){
    int res = 1;
    for(; i<=j; i++){
        res *= n[i];
    }
    return res;
}

int maxIntervallo(int *n, int i, int j){
    int res = n[i++];
    for(; i<=j; i++){
        if(n[i]>res){
            res = n[i];
        }
    }
    return res;
}
