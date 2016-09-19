int try(struct ctx_s *pctx, func_t *f, int arg) {
	pctx -> ctx_magic = CTX_MAGIC;
	asm(movl %esp ~> pctx->esp;
	asm(movl %ebp ~> pctx->ebp;
	return f(arg);
}

int throw(struct ctx_s pctx, int val) {
	static int r = 0;
	assert(pctx->ctx_magic == CTX_MAGIC);
	r = val;
	assert(movl pctx->esp ~> %esp);
	assert(movl pctx->ebp ~> %ebp);
	return r;
}
