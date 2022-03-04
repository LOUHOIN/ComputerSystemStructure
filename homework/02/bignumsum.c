// bignumsum.c
#include "bignum.c"

void main(int argc, char **argv) {
    bignum a, b, c;

    //test data
//    argv[1] = "-10000";
//    argv[2] = "+";
//    argv[3] = "-2345";

    set_bignum(&a, argv[1]);
    set_bignum(&b, argv[3]);
    initialize_bignum(&c);

    if (argv[2][0] == '-')
        subtract_bignum(&a, &b, &c);
    else
        add_bignum(&a, &b, &c);

    print_bignum(&a);
    printf("%c\n", argv[2][0]);
    print_bignum(&b);
    printf("=\n");
    print_bignum(&c);
    printf("\n");
}
