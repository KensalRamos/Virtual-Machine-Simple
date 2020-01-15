

// An example program the virtual machine will execute
// In reality just an array of integers since our struct is an enum type
const int program[] = {
	PUSH, 5, // Push 5 and then 6 to the stack
	PUSH, 6,
	ADD,	// Add top 2 integers
	POP,	// Pop operation
	HLT		// Terminate program

};