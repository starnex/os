#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <stdio.h>
#define my_stack_push_syscall 335
#define my_stack_pop_syscall 336

void push(int i);
void pop();

int main(int argc, char *argv[]) {
	
	push(1);
	push(2);
	push(3);

	pop();
	pop();
	pop();

	return 0;
}


void push(int i) {

	int r;
	r = syscall(my_stack_push_syscall,i);
	
	if (r != -1) {
		printf("Push: %d\n", i);
	}
	else {
		printf("Push failed\n");
	}
}

void pop() {

	int r;
	r = syscall(my_stack_pop_syscall);

	if (r != -1){
		printf("Pop: %d\n", r);
	}
	else {
		printf("Pop failed\n");
	}
}
