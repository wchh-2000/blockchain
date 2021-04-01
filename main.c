#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "sha256.h"
#include "mining.h"


int main(void) {
	int i;
	unsigned char Hash[32]={0}; //256 bits hash 
	SHA256_CTX ctx;
	BLOCK block;
	Block_init(&block);//创建初始区块 
	sha256_init(&ctx);
	Mining(&ctx,&block,Hash,N0); 
	for(i=0;i<32;i++)
		printf("%x ",Hash[i]);
	return 0;
	system("pause");
}
