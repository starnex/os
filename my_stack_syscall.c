#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/linkage.h>

int stack[10];
int top = 0;

SYSCALL_DEFINE1(oslab_push, int, a){
	
	int i;

	printk("[System call] oslab_push(): Push %d\n", a);

	for (i = 0; i < top; i++) {
		if(stack[i] == a) {
			printk("Do not allow the duplicated number: %d\n", a);
			return;
		}
	}

	stack[top++] = a;
	
	printk("Stack Top ----------\n");

	for(i = top - 1; i >= 0; i--) {
		printk("%d\n", stack[i]);
	}

	printk("Stack Bottom -------\n");
	
}

SYSCALL_DEFINE0(oslab_pop){
	
	int i;

	top--;
	printk("[System call] oslab_pop(): Pop %d\n", stack[top]);

	printk("Stack Top ----------\n");

	for(i = top - 1; i >= 0; i--) {
		printk("%d\n", stack[i]);
	}

	printk("Stack Bottom -------\n");
	return stack[top];
}
