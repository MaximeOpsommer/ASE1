#include "try.h"
#include <stdio.h>
#include <assert.h>

int try(struct ctx_s *pctx, func_t *f, int arg) {
	pctx->ctx_magic = CTX_MAGIC;
	asm("movl %%esp, %0"
	    : "=r" (pctx->ctx_esp));
	asm("movl %%ebp, %0"
	    : "=r" (pctx->ctx_ebp));
	printf("test_try\n");
	return f(arg);
}

int throw(struct ctx_s *pctx, int val) {
	static int r = 0;
	assert(pctx->ctx_magic == CTX_MAGIC);
	r = val;
	printf("test_throw\n");
	printf("val = %d\n", r);
	asm("movl %0, %%esp"
	    : 
	    : "r" (pctx->ctx_esp));
	asm("movl %0, %%ebp"
	    :
	    : "r" (pctx->ctx_ebp));
	return r;
}
