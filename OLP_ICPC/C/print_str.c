#include <stdio.h>
#include <string.h>
#define MAXLEN 3

void error_message();
void print_string(char* ch);

void print_string(char* ch) {
	if (strlen(ch) <= MAXLEN) printf("%s\n", ch);
	else error_message();
}

void error_message() {
	printf("String is oversized!");
}

int main() {
	char* ch = "abcd";
	print_string(ch);
}
/* (base) nqbh@nqbh:~/advanced_STEM_beyond/OLP_ICPC/C$ g++ -O2 -Wall print_str.c -o print_str
print_str.c: In function ‘int main()’:
print_str.c:18:20: warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
   18 |         char* ch = "abcd";
      |                    ^~~~~~
(base) nqbh@nqbh:~/advanced_STEM_beyond/OLP_ICPC/C$ gcc -O2 -Wall print_str.c -o print_str
(base) nqbh@nqbh:~/advanced_STEM_beyond/OLP_ICPC/C$ ./print_str 
String is oversized!(base)