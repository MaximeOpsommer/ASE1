#include <stdio.h>
#include <stdlib.h>

#include "try.h"

static struct ctx_s *pctx;

static int mul(int depth) {
	int i = 0;
	switch(scanf("%d", &i)) {
		case EOF:
			return 1;
		case 0:
			return mul(depth+1);
		case 1:
			if(i)
				return i * mul(depth+1);
			else
				throw(pctx, ~0);
	}
	return 0;
}

int main(int argc, char *argv[]) {

	int product;
	pctx = malloc(sizeof(ctx_s));

	printf("A list of int please.\n");
	if(!try(pctx, &mul, 0)) {
		product = mul(0);
	}
	else
		product = 0;
	printf("product = %d\n", product);
	free(pctx);

	return 1;

}
