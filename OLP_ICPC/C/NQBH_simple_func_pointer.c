#include <stdio.h>  /* for printf */
#include <string.h> /* for strchr */

double cm_to_inches(double cm) {
    return cm / 2.54;
}

// "strchr" is part of the C string handling (i.e., no need for declaration)

int main(void) {
    double (*func1)(double) = cm_to_inches;
    char * (*func2)(const char *, int) = strchr;
    printf("%f %s", func1(15.0), func2("Wikipedia", 'p')); // prints "5.905512 pedia"
    return 0;
}
/*
(base) nqbh@nqbh:~/advanced_STEM_beyond/OLP_ICPC/C$ g++ -O2 -Wall NQBH_simple_func_pointer.c -o NQBH_simple_func_pointer
NQBH_simple_func_pointer.c: In function ‘int main()’:
NQBH_simple_func_pointer.c:12:42: error: no matches converting function ‘strchr’ to type ‘char* (*)(const char*, int)’
   12 |     char * (*func2)(const char *, int) = strchr;
      |                                          ^~~~~~
In file included from NQBH_simple_func_pointer.c:2:
/usr/include/string.h:239:1: note: candidates are: ‘const char* strchr(const char*, int)’
  239 | strchr (const char *__s, int __c) __THROW
      | ^~~~~~
/usr/include/string.h:233:1: note:                 ‘char* strchr(char*, int)’
  233 | strchr (char *__s, int __c) __THROW
      | ^~~~~~
(base) nqbh@nqbh:~/advanced_STEM_beyond/OLP_ICPC/C$ gcc -O2 -Wall NQBH_simple_func_pointer.c -o NQBH_simple_func_pointer
(base) nqbh@nqbh:~/advanced_STEM_beyond/OLP_ICPC/C$ ./NQBH_simple_func_pointer 
5.905512 pedia
*/