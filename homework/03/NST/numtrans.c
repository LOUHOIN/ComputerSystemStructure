// numtrans i k ddddddddddddd
// Transfer an i-based number string to a k-based number string
// i and k in [2..36]
// @ Max, 2020, 2021
#include <stdio.h>
#include <stdlib.h>

int ctoi(char c) {     // helper function
    if ('0' <= c && c <= '9') return c - '0';
    if ('A' <= c && c <= 'Z') {
        return c; // TODO ... ;
    }
    if ('a' <= c && c <= 'z') return 0;// TODO ... ;
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
    } else if(radix == 10){
        return 0;
    }
}

void main(int argc, char **argv) {
//    argv[1] = "2";
//    argv[2] = "10";
//    argv[3] = "1101101"; //109
    argv[1] = "16";
    argv[2] = "10";
    argv[3] = "FACE"; //64206
    int i = atoi(argv[1]);    // call atoi in stdlib
    int k = atoi(argv[2]); //finish
    long n = atol_with_radix(argv[3], i);

    char s[65];                 // long has 64 bits

    ltoa(n, s, k);            // call ltoa in stdlib
    printf("%s\n", s);
}







//int main() {
////    int i;
////    char buffer[33];
////    printf("Enter a number: ");
////    i = 12;
////    itoa(i, buffer, 10);    //将i转化为10进制数，存到buffer中
////    printf("decimal: %s\n", buffer);    //输出打印buffer
////    itoa(i, buffer, 16);    //将i转化为16进制数，存到buffer中
////    printf("hexadecimal: %s\n", buffer);    //输出打印buffer
////    itoa(i, buffer, 32);    //将i转化为2进制数，存到buffer中
////    printf("binary: %s\n", buffer);    //输出打印buffer
//    char six;
//    six = '6';
////    int s six - "0";
////    six = '6'-'0';
//
//    printf("%d\n", ctoi(six));
//    return 0;
//}