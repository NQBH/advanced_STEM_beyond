#include <math.h>
#include <stdio.h>

// function taking a function pointer as an argument
double compute_sum(double (*funcp)(double), double a, double b) {
    double sum = 0.0;
    
    // add values returned by the pointed-to function '*funcp'
    for (int i = 0; i <= 100; ++i) {
        // use the function pointer 'funcp' to invokve the function
        double x = i / 100.0 * (b - a) + a;
        double y = funcp(x);
        sum += y;
    }
    return sum / 101.0 * (b - a);
}

double square(double x) {
    return x * x;
}

int main(void) {
    double sum;

    // use standard library function sin() as the pointed-to function
    sum = compute_sum(sin, 0.0, 1.0);
    printf("sum(sin): %g\n", sum);
    
    // use standard library function cos() as the pointed-to function
    sum = compute_sum(cos, 0.0, 1.0);
    printf("sum(cos): %g\n", sum);
    
    // use user-defined function square() as the pointed-to function
    sum = compute_sum(square, 0.0, 1.0);
    printf("sum(square): %g\n", sum);
    return 0;
}
/*
(base) nqbh@nqbh:~/advanced_STEM_beyond/OLP_ICPC/C$ gcc -O2 -Wall NQBH_Riemann_integration.c -o NQBH_Riemann_integration
/usr/bin/ld: /tmp/ccX09HTy.o: in function `main':
NQBH_Riemann_integration.c:(.text.startup+0x1b): undefined reference to `sin'
/usr/bin/ld: NQBH_Riemann_integration.c:(.text.startup+0x39): undefined reference to `cos'
collect2: error: ld returned 1 exit status
(base) nqbh@nqbh:~/advanced_STEM_beyond/OLP_ICPC/C$ g++ -O2 -Wall NQBH_Riemann_integration.c -o NQBH_Riemann_integration
(base) nqbh@nqbh:~/advanced_STEM_beyond/OLP_ICPC/C$ ./NQBH_Riemann_integration 
sum(sin): 0.459308
sum(cos): 0.840758
sum(square): 0.335
*/