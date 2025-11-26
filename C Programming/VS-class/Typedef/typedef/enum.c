#include<stdio.h>
enum Level{
    LOW,
    MEDIUM,
    HIGH,

};
int main(){
    enum Level myVar = HIGH;
    printf("%d",myVar);
    return 0; 
}