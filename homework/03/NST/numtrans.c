// numtrans i k ddddddddddddd
// Transfer an i-based number string to a k-based number string
// i and k in [2..36]
// @ Max, 2020, 2021
#include <stdio.h>
#include <stdlib.h>

int ctoi (char c) {     // helper function
   if ('0' <= c && c <= '9') return c - '0';
   if ('A' <= c && c <= 'Z') return 0; // TODO ... ;
   if ('a' <= c && c <= 'z') return 0;// TODO ... ;
   return 0;   
}

long atol_with_radix (char* s, int radix) {
   // TODO ...
}

void main (int argc, char** argv) {
   int i = atoi( argv[1] );    // call atoi in stdlib
   int k = atoi( argv[2] );
   long n = atol_with_radix( argv[3], i );

   char s[65];                 // long has 64 bits 
   ltoa( n, s, k );            // call ltoa in stdlib
   printf( "%s\n", s );
}

