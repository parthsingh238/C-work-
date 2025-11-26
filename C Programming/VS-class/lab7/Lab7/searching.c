#include <stdio.h>
int main(){
    int n, search, found;
    printf("Enter the number of elements: ");
    scanf("%d", &n );

    int arr[n];

    printf("Enter the number of elements in array: ");
    for( int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &search);

    for( int i = 0; i < n; i++){
        if( arr[i] ==  search){
            printf("Element %d found at postion %d \n", search, i + 1);
            found  = 1;
            break;
        }
    }

    if(! found){
        printf("Elements %d not foundin the array \n", search);
    }

    return 0;

}