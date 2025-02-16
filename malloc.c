#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main(){
    int *ptr;
    ptr=(int*)malloc(sizeof(int));
    *ptr=20;
    printf("%u\n",ptr);
    printf("%d\n",*ptr);
    getch();
}