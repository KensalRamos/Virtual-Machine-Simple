/*
 *
 * Kensal J Ramos
 * Created on 1/14/2020
 *
 * Goal: Create a simple virtual machine initially following Felix Angell's article and branching out afterwards.
 * 
 */
 
 // Structures

/*
 * This struct provides the instruction set for our virtual machine. We declare it an enum type
 * because it will only store integers from 0 - X, where x is an int.
 */
typedef enum {
	PUSH,
	ADD,
	POP,
	SET,
	HLT
} InstructionSet;

typedef enum {
	A, B, C, D, E, F,
	NUM_OF_REGISTERS
} Registers;


// Pre-processor directives
#include <stdlib.h>
#include <stdio.h>
#include "program.h"

// Function prototypes
int fetch();
void eval(int instr);

// Global variables
int ip = 0; // Instruction pointer
int flag = 1;
int sp = -1; // Stack pointer
int stack[256];
int registers[NUM_OF_REGISTERS];

int main(void) {

	while (flag) {
		eval(fetch());
		ip++;
	}

	return 0;
}

/*
 * Fetches the current instruction
 * 
 */
int fetch() {
	return program[ip];
}

/*
 * This function uses a switch to evaluate fetched instructions.
 * We use a switch instead of a HashMap because of a faster runtime and simplicity.
 * 
 *	Parameters:
 *		- intstr: instruction (int due to enum type)
 */
void eval(int instr) {

	switch(instr) {
		// Braces gives case a scope so we can define variables
	case HLT: { 
		flag = 0;
		break;
	}
	case PUSH: {
		sp++;
		stack[sp] = program[++ip]; // Increments ip and then gets the num
		break;
	}
	case POP: { 
		int valPopped = stack[sp--];
		printf("popped %d\n", valPopped);
		break;
	}
	case ADD: {
		int a = stack[sp--];
		int b = stack[sp--];
		int result = a + b;

		sp++;
		stack[sp] = result;
		break;
	}

	}

}