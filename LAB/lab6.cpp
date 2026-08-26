#include<stdio.h>
int main () {
int n = 0 ;

printf( "Enter number : " ) ;
scanf( "%d" ,&n ) ;

if( n%2 == 0 ) { //คู่
for (int j = 0; j < n; j++)
{
for (int c = 0; c < n; c++) {
    if(c==j){
        printf("1");
    }else{
        printf("0");
    }
}//for
printf("\n");
}//for
} else if( n%2 == 1 ) { //คี่
    for (int j = 0; j <= n; j++)
    {
    for (int c = 0; c <= n; c++) {
    if(c == n-j-1 ){
        printf("1");
    }else{
        printf("0");
    }
}//for
printf("\n");
}//for
}//if else
return 0 ;
}//end main
