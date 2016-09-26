#define CTX_MAGIC 0xABBACAFE

typedef int (func_t) (int);
typedef struct ctx_s ctx_s;

struct ctx_s {
	void * ctx_esp;
	void * ctx_ebp;
	unsigned ctx_magic;
};

int try(struct ctx_s *pctx, func_t *f, int arg);
int throw(struct ctx_s *pctx, int val);
