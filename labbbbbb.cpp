#include<stdio.h>

int main() {
int n ;
printf( "Enter number : " ) ;
scanf( "%d" , &n ) ;
if ( n%2 == 1 ) {
    for ( int i = 1 ; i < n + 1 ; i++ ) {
        printf( "%d\n" , i ) ;
        i += 1 ;
    }//for
} else if( n%2 == 0 ) {
    for ( int i = 2 ; i < n + 1 ; i++ ) {
        printf( "%d\n" , i ) ;
        i += 1 ;
    }//for
} //end if 

return 0 ;

}//end main
