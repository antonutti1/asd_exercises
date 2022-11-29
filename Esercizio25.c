#include <stdio.h>
#include <string.h>

#define MAX 10000

int distanza_di_editing(char *parola1, char *parola2, int length1, int length2);
int min (int x, int y, int z);

int esercizio25() {
    char parola1[MAX];
    char parola2[MAX];
    int length1;
    int length2;

    scanf("%s", parola1);
    scanf("%s", parola2);
    length1 = strlen(parola1);
    length2 = strlen(parola2);

    printf("%d", distanza_di_editing(parola1, parola2, length1, length2));

    return 0;
}

int distanza_di_editing(char *parola1, char *parola2, int length1, int length2) {
    int matrix[length1+1][length2+1];
    for(int i=0; i<length1; i++)
        for(int j=0; j<length2; j++)
            matrix[i][j] = 0;
    for (int i = 0; i <= length1; i++)
        matrix[i][0] = i;
    for (int i = 0; i <= length2; i++)
        matrix[0][i] = i;

    char c1, c2;
    for (int i = 0; i < length1; i++) {
        c1 = parola1[i];
        for (int j = 0; j < length2; j++) {
            c2 = parola2[j];

            if(c1 == c2)
                matrix[i+1][j+1] = matrix[i][j];
            else
                matrix[i+1][j+1] = 1+min(matrix[i+1][j], matrix[i][j+1], matrix[i][j]);
        }
    }

    return matrix[length1][length2];
}

int min(int x, int y, int z){
    if(x < y && x < z)
        return x;
    else if(y < z && y < x)
        return y;
    else
        return z;
}