#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct tree{
    int date;
    struct tree *left;
    struct tree *right;
}tree;

int main()
{
    tree *a,*b,*c,*d,*e,*f;
    a -> date = 15;
    a -> left = b;
    a -> right = c;

    b -> date = 8;
    b -> left = d;
    b -> right = NULL;

    c -> date = 20;
    c -> left = e;
    c -> right = f;

    d -> date = 4;
    d -> left = NULL;
    d -> right = NULL;

    e -> date = 17;
    e -> left = NULL;
    e -> right = NULL;

    f -> date = 20;
    f -> left = NULL;
    f -> right = NULL;
    
}