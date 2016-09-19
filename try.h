#define CTX_MAGIC 0xABBACAFE

struct ctx_s {
	void * ctx_esp;
	void * ctx_ebp;
	unsigned ctx_magic;
}
