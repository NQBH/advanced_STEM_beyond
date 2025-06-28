// This defines 'C', a class with similar static & member functions, & then creates an instance called 'c'
class C {
public:
	static int Static(char c);
	int Member(char c);
} c; // C

// This defines 'p', a pointer to 'C' & assigns the address of 'c' to it
C *p = &c;

// This assigns a pointer-to-'Static' to 'fn'.
// Since there is no 'this', 'Fn' is the correct type; and 'fn' can be used as above.
fn = &C::Static;

// This defines 'm', a pointer-to-member-of-'C' with type 'Fn',
// and assigns the address of 'C::Member' to it.
// You can read it right-to-left like all pointers:
// "'m' is a pointer to member of class 'C' of type 'Fn'"
Fn C::*m = &C::Member;

// This uses 'm' to call 'Member' in 'c', assigning the result to 'cA'
int cA = (c.*m)('A');

// This uses 'm' to call 'Member' in 'p', assigning the result to 'pA'
int pA = (p->*m)('A');

// This defines 'Ref', a function that accepts a reference-to-'C',
// a pointer-to-member-of-'C' of type 'Fn', and a 'char',
// calls the function and returns the result
int Ref(C &r, Fn C::*m, char c) {
   return (r.*m)(c);
} // Ref(r, m, c)

// This defines 'Ptr', a function that accepts a pointer-to-'C',
// a pointer-to-member-of-'C' of type 'Fn', and a 'char',
// calls the function and returns the result
int Ptr(C *p, Fn C::*m, char c) {
   return (p->*m)(c);
} // Ptr(p, m, c)

// LEGACY: Note that to maintain existing code bases, the above definition style can still be used first;
// then the original type can be defined in terms of it using the new style.

// This defines 'FnC', a type of pointer-to-member-of-class-'C' of type 'Fn'
typedef Fn C::*FnC;

// 'FnC' can be used wherever 'Fn C::*' can
FnC fnC = &C::Member;
int RefP(C &p, FnC m, char c);