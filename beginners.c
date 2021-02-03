#include <stdio.h> //header file ---> single line comment

// DATA TYPES IN C
/*
1) int -%d- integer e.g. 1,2,3,9999,300012223 etc.  
2) char -%c- character e.g. a,b,c,d,.... 
3) float -%f- decimal value e.g. 1.22333, 3.15445454....
4) double -%lf- long integer... 
*/


// main function
// int main(){
//     int a,b,c; //variable declaration
//     // printf("%d",a); -->garbage value
//     printf("Enter three numbers:\n");
//     scanf("%d %d %d",&a,&b,&c); //take input from user

//     int sum=0;//initialise sum=0 (else it will store garbage value)
//     sum=a+b+c;//do the operation
//     printf("Sum of %d %d and %d is %d",a,b,c,sum);//print the final value


//     return 0;
// }


// int main(){
//     int a,b;
//     scanf("%d %d",&a,&b);
//     int sub=a-b;
//     printf("difference of %d ,%d is %d ",a,b ,sub);
//     return 0;
// }

// int main (){
//     int a ,b;
//     scanf("%d %d" , &a,&b );
//     // int mul=a*b ;
//     printf("multiplication of %d %d is %d " , a,b,a*b);
//     return 0;
// }
// int main(){
//     int a;
//     scanf("%d",&a);
//     int volume = a*a*a;
//     printf("Volume of a cube having side %d is %d",a,volume);
// }
//data_type functionName (data_type argument1,data_type argument2,...)

// int main(){
//     float a=11.0,b=5.0;
//     printf("%f",a/b);
//     return 0;
// }


/*
    a/b quotient 
    a%b remainder
    11/4 = 2 ----> quotient
    11%4 = 3 -------> remainder

    int/int = int
    float/int = float  (11.0/4=2.30000000)
    float/float = float
*/
// int main(){
//     int b;
//     float a;
//     scanf("%f%d",&a,&b);
//     printf("Quo=%f",a/b);
//     return 0;
// }


// to print n numbers 
// We use loops
// for loop, while loop, do while loop

// for(initialize a variable, condition, increment or decrement){}
//  for(int i=0;i<n;i++) ------>time complexity = O(n)    


/* for (int i=1;i<11;i=i+1){
    printf("%d\n",i);
}*/

// int main(){
//     int j=0;
//     for(int i=0;i<6;i++){ 
//         printf("%d\n",j++);
//     }
//     return 0;
// } 

/*
    increments  and decrements
    post increment - i = i+1; ----> i++;
    pre increment - ++i;
    post decrement - i = i-1; ---->i--;
    pre decrement - --i;
*/

// while loop
/*
        while(condition){
            increment or decrement;
        }
*/
// int main(){
    // int i=0;
    // while(i<5){
    //     printf("%d\n",i);
    //     i++;
    // }
    // int i=5;
    // while (i>0){
    //     printf("%d\n",i);
    //     --i;
    // }
//     return 0;
// }


// If ,else if, else conditions
/*
    if(condition--->true){
        statement;
    } else if(condition){
        statement;
    } else if(conditoin){
        
    } else{
        statement;
    }

*/
// int main(){
//     int i=10;
//     if(i<5){
//         printf("i is less than 5");
//     } else if(i<10){
//         printf("i is less than 10");
//     } else if(i>10){
//         printf("i is greater than 10");
//     } else {
//         printf("i is equal to 10");
//     }
//     return 0;
// }
// "5", 5
// iqbal === gay
// conditional operator 
/*
    >,<,==,===,etc.
*/
