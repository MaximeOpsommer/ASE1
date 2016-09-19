#define CTX_MAGIC 0xABBACAFE

typedef int (func_t) (int);

struct ctx_s {
	void * ctx_esp;
	void * ctx_ebp;
	unsigned ctx_magic;
};
