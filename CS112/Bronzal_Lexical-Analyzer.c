#include<stdio.h>
#include<stdlib.h>

#define ll long long int
#define inf 100000

typedef short sho;

struct node {
    int data;
    struct node *next;
} ;

void func ( ) ;

int main ( ) {
    int num = 5;
    char zed = 'z';
    char name[5] = "lance";
    printf ("%s", name);
	
    printf ( "Hello World" ) ;
    int c = num + 12;
    int d = c == 17 ? 50 : 1;
    c += 6;

    return 0;
}

void func ( ) {
    float a = 4.5;
    a *= 2;
    if ( a == 9 ) a = 121;
}
