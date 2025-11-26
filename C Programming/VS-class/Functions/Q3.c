 #include <stdio.h> 

int Add(int output1, int output2) 
{ 
    printf("First number = %d\n", output1); 
    printf("Second number = %d\n", output2); 
    return output1 + output2; 
} 

int main() 
{
    int answer, input1, input2; 
    
    printf("Enter two numbers: ");
    scanf("%d %d", &input1, &input2); 
    
    answer = Add(input1, input2); 
    
    printf("Answer = %d\n", answer); 
    
    return 0; 

}