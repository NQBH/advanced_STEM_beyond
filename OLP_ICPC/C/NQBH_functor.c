// This declares 'F', a function that accepts a 'char' & returns an 'int'. Definition is elsewhere.
int F(char c);

// This defines 'Fn', a type of function that accepts a 'char' & returns an 'int'.
typedef int Fn(char c);

// This defines 'fn', a variable of type pointer-to-'Fn', & assigns the address of 'F' to it.
Fn *fn = &F; // Note '&' not required - but it highlights what is being done.

// This calls 'F' using 'fn', assigning the result to the variable 'a'
int a = fn('A');

// This defines 'Call', a function that accepts a pointer-to-'Fn', calls it, & returns the result
int Call(Fn *fn, char c) {
	return fn(c);
} // call(fn, c)

// This calls function 'Call', passing in 'F' & assigning the result to 'call'
int call = Call(&F, 'A'); // again, '&' is not required

// LEGACY: Note that to maintain existing code bases, the above definition style can still be used first;
// then the original type can be defined in terms of it using the new style.

// This defines 'PFn', a type of pointer-to-type-Fn.
typedef Fn *PFn;

// 'PFn' can be used wherever 'Fn *' can
PFn pfn = F;
int CallP(PFn fn, char c);