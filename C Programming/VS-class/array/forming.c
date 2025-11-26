#include<stdio.h>
int main(){
    int arr[4];

    printf("enter the elements of array\n");
    for(int i=0;i<4;i++){
        scanf("%d", &arr[i]);

    }
    for( int i=0;i<4;i++){
        printf("%d\n", arr[i]);
    }
}