// bignum.c
#include <stdio.h>
#include "bignum.h"

void print_bignum(bignum *n) {
    int i;    /* counter */
    if (n->signbit == MINUS) printf("- ");
    for (i = n->lastdigit; i >= 0; i--)
        printf("%c", '0' + n->digits[i]);
    printf("\n");
}

void initialize_bignum(bignum *n) {//初始化结构体
    int i;    /* counter */
    for (i = 0; i < MAXDIGITS; i++)
        n->digits[i] = 0; //初始化digits[100] 的值为0

    n->signbit = PLUS; //初始化signbit = 1
    n->lastdigit = 0; //初始化lastdigit = 0;长度
};

void set_bignum(bignum *n, char *s) {
    int i = 0, k, length;
    initialize_bignum(n);
    if (s[0] == '-') {       // skip beginning - sign
        n->signbit = MINUS;
        i = 1;
    } else if (s[0] == '+')  // skip beginning + sign
        i = 1;

    while (s[i] == '0') i++;   // skip beginning 0s

    for (k = i, length = 0; s[k] != '\0'; k++, length++) /* NONE长度 */ ;

    n->lastdigit = length - 1;
    for (k = length - 1; k >= 0; k--, i++)
        n->digits[k] = s[i] - '0';
};

void zero_justify(bignum *n) {
    while ((n->lastdigit > 0) && (n->digits[n->lastdigit] == 0))
        n->lastdigit--;

    if ((n->lastdigit == 0) && (n->digits[0] == 0))
        n->signbit = PLUS;   /* hack to avoid -0 */
}

int compare_bignum(bignum *a, bignum *b) {
    int i;    /* counter */
    // 原则：b>a,返回值为-1侧交换 a b
    // a是负数,b是正数,所以b>a,返回1
    if ((a->signbit == MINUS) && (b->signbit == PLUS)) return PLUS;
    // a是正数,b是负数,所以a>b ,返回-1
    if ((a->signbit == PLUS) && (b->signbit == MINUS)) return MINUS;
    // 符号一样
    // a,b是正数,b比a长,则b>a,返回1*1
    // a,b是负数,b比a长,则a>b,返回1*-1 = -1
    if (b->lastdigit > a->lastdigit) return (PLUS * a->signbit);
    // a,b是正数,a比b长,则b>a,返回1*1
    // a,b是负数,a比b长,则a>b,返回1*-1 = -1
    if (a->lastdigit > b->lastdigit) return (MINUS * a->signbit);
    // 符号、下标一样
    // 获取任意a的下标,进行首位比较,如果一样则比较下一位
    for (i = a->lastdigit; i >= 0; i--) {
        // a,b是正数,如果(200,100)a>b,则返回1*-1
        // a,b是负数,如果(-200,-100)b>a,则返回-1*-1
        if (a->digits[i] > b->digits[i])
            return (MINUS * a->signbit);
        // a,b是正数,如果(100,200)b>a,则返回1*-1
        // a,b是负数,如果(-100,-200)a>b,则返回1*-1
        if (b->digits[i] > a->digits[i])
            return (PLUS * a->signbit);
    }
    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int toInt(int a) {
    return a;
}

char toChar(char a) {
    return a;
}


void add_bignum(bignum *a, bignum *b, bignum *c) {
    // TODO ...
    zero_justify(c);//初始化C
    // -a+b  ==>  b-a
    if ((a->signbit == MINUS) && (b->signbit == PLUS)) {
        a->signbit = PLUS;
        subtract_bignum(b, a, c);
        a->signbit = MINUS;
    }
        // a+(-b)  ==>  a-b
    else if ((a->signbit == PLUS) && (b->signbit == MINUS)) {
        b->signbit = PLUS;
        subtract_bignum(a, b, c);
        b->signbit = MINUS;
    } else {
        // a+b,(-a)+(-b)
        int c_lastdigit = max(a->lastdigit, b->lastdigit);
        int i;
        for (i = 0; i < c_lastdigit + 1; ++i) {
            int count = 0;
            count = toInt(c->digits[i]) + toInt(b->digits[i]) + toInt(a->digits[i]);
            if (count > 9) {
                c->digits[i + 1] = toChar(1);//进位
                count = count % 10;//进位取余
            }
            c->digits[i] = toChar(count);
        }
        if ((toInt(c->digits[i + 1])) != 0) { c->lastdigit = c_lastdigit + 1; }//set c->lastdigit
        c->lastdigit = c_lastdigit;
        c->signbit = a->signbit;
    }
}


void subtract_bignum(bignum *a, bignum *b, bignum *c) {
    // TODO ...
    zero_justify(c);
    //a-(-b) = a+b
    if ((a->signbit == PLUS && b->signbit == MINUS)) {
        b->signbit = PLUS;
        add_bignum(a, b, c);
        b->signbit = MINUS;
    }
        // -a-b = -(a+b)
    else if (a->signbit == MINUS && b->signbit == PLUS) {
        a->signbit = PLUS;
        add_bignum(a, b, c);
        a->signbit = MINUS;
        c->signbit = MINUS;
    }
        // -a-(-b) = b-a
    else if (a->signbit == MINUS && b->signbit == MINUS) {
        a->signbit = PLUS;
        b->signbit = PLUS;
        subtract_bignum(b, a, c);
        a->signbit = MINUS;
        b->signbit = MINUS;
    }
        // a-b
    else {
        int n = compare_bignum(a, b);
        if (n == 1) {
            // a>b ==>  b+a
            subtract_bignum(b, a, c);
            c->signbit = MINUS;
        } else {
            int c_lastdigit = 0;
            c_lastdigit = max(a->lastdigit, b->lastdigit);//c长度
            int i;
            int count = 0;
            int lowBit = 0;
            for (i = 0; i < c_lastdigit + 1; i++) {
                count = toInt(c->digits[i]) + toInt(a->digits[i]) - toInt(b->digits[i]) + lowBit;
                lowBit = 0;//结束借位
                if (count < 0) {//减法借位
                    count += 10;
                    lowBit = -1;
                }
                c->digits[i] = toChar(count);
            }
            int j;
            for (j = c_lastdigit + 1; j > 0; j--) {//set c->lastdigit
                if (toInt(c->digits[j]) != 0) {
                    c->lastdigit = j;
                    break;
                }
            }
        }
    }
}
