#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 10000   // maximum size of a line of input
#define MAX_INT_ARRAY_SIZE 10000
#define NULLNODE (-1)

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

void buildTree (int *a, int is, int fs, struct Node *n);

int isABR(struct Node *n);
int leftExists(struct Node *n);
int rightExists(struct Node *n);

int isABRX(int *a, int is, int fs, int *tmp, int st);

int isABRNode(int parent, int left, int right);

int checkDuplicates (int *a, int size);

int esercizio18(){
    char s[100];
    int a[MAX_INT_ARRAY_SIZE];
    int size = 0;
    char next = fgetc(stdin);
    do{
        ungetc(next, stdin);

        scanf("%s", s);

        if(strlen(s) == 4 && strncmp(s, "NULL", 4) == 0){
            a[size] = -1;
        } else {
            a[size] = atoi(s);
        }

        size++;

        next = fgetc(stdin);
    }while(next != '\n');

    if(size == 0) {
        printf("%d", 0);
        return 0;
    }
    if(size == 1 && a[0] == -1) {
        printf("%d", 1);
        return 0;
    }

    int duplicates = checkDuplicates(a, size);
    if(duplicates){
        printf("%d", 0);
        return 0;
    }



    int tmp[size];
    tmp[0] = a[0];
    printf("%d", isABRX(a, 1, 2, tmp, 1));

    /*
    struct Node *node = malloc(size * sizeof(struct Node));
    struct Node *n[size];
    n[0] = node;
    buildTree(a, 0, 0, n);
    printf("%d", isABR(node));
    */

    return 0;
}

/*
input=1 2 3 NULL NULL 4 NULL 5 NULL NULL 6 NULL NULL
output=0

input=1 NULL 2 NULL 3 NULL 4 NULL NULL
output=1
*/

int isABRX(int *a, int is, int fs, int *tmp, int st) {
    for (int i=0; i<st; i++){
        if(!isABRNode(tmp[i], a[is+(i*2)], a[is+(i*2)+1])){
            return 0;
        }
    }

    int k = 0;
    for (int i = is; i <= fs; i++) {
        if(a[i] != NULLNODE){
            tmp[k] = a[i];
            k++;
        }
    }

    if(k==0)
        return 1;
    else
        return isABRX(a, fs+1, fs+(k*2), tmp, k);
}


void buildTree(int *a, int is, int fs, struct Node *n){
    int j = 0;
    for(int i=is; i<=fs; i++){
        if(a[i] != -1){
            n[i].value = a[i];
            struct Node *left = n+(fs+1+(j*2))*sizeof(struct Node);
            struct Node *right = n+(fs+2+(j*2))*sizeof(struct Node);
            left = n[i].left;
            right = n[i].right;
            j++;
        } else {
            n[i].value = NULLNODE;
        }
    }

    //calculate next level dimension
    int nextLevel = j*2;
    is = fs+1;
    fs = fs + nextLevel;

    if(j != 0)
        buildTree(a, is, fs, n);
}

int isABR(struct Node *n){
    if(rightExists(n) && leftExists(n)){
        if(n->left->value < n->value && n->right->value > n->value)
            return isABR(n->left) && isABR(n->right);
        else
            return 0;
    }

    if(leftExists(n) && !rightExists(n)){
        if(n->left->value < n->value){
            return isABR(n->left);
        } else {
            return 0;
        }
    }

    if(rightExists(n) && !leftExists(n)){
        if(n->right->value > n->value){
            return isABR(n->right);
        } else {
            return 0;
        };
    }

    return 1;
}

int leftExists(struct Node *n){
    if(n->left->value != NULLNODE)
        return 1;
    else
        return 0;
}

int rightExists(struct Node *n){
    if(n->right->value != NULLNODE)
        return 1;
    else
        return 0;
}


int isABRNode(int parent, int left, int right){
    if(left == NULLNODE && right == NULLNODE)
        return 1;

    if(left == NULLNODE)
        return parent<right;

    if(right == NULLNODE)
        return parent>left;

    return parent>left && parent<right;
}

int checkDuplicates (int *a, int size){
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(a[i] != NULLNODE && a[i] == a[j]){
                return 1;
            }
        }
    }

    return 0;
}