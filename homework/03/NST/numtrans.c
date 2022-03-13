// numtrans i k ddddddddddddd
// Transfer an i-based number string to a k-based number string
// i and k in [2..36]
// @ Max, 2020, 2021
#include <stdio.h>
#include <stdlib.h>

int ctoi(char c) {     // helper function
    if ('0' <= c && c <= '9') return c - '0';
    if ('A' <= c && c <= 'Z')return c - 'A' + 10; // TODO ... ;
    if ('a' <= c && c <= 'z') return c-'Z'+3;// TODO ... ;
    return 0;
}

long atol_with_radix(char *s, int radix) {//转换成int类型的十进制
    // TODO ...
    long result = 0;
    if (radix == 2) {
        int i = 0;
        while (s[i] != 0) {
            result = result * 2 + ctoi(s[i]);
            i++;
        }
        return result;
    } else if (radix == 10) {
        return atoi(s);
    } else if (radix == 16 || radix == 32) {
        int len = 0;
        while (s[len] != 0) {
            len++;
        }
        int j, sum = 0, temp = 0;
        for (j = 0; j < len; j++) {
            if (s[j] <= '9')
                temp = ctoi(s[j]);
            else
                temp = ctoi(s[j]);
            sum = sum * radix + temp;//16 or 32
        }
        return sum;
    }
}


void main(int argc, char **argv) {
//    argv[1] = "32";
//    argv[2] = "10";
//    argv[3] = "1UME"; //64206
    int i = atoi(argv[1]);    // call atoi in stdlib
    int k = atoi(argv[2]); //finish
    long n = atol_with_radix(argv[3], i);

    char s[65];                 // long has 64 bits

    ltoa(n, s, k);            // call ltoa in stdlib
    printf("%s\n", s);
}
