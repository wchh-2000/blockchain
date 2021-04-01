#ifndef mining_h
#define mining_h

#include "sha256.h"
#define blockBytes 96 //每个区块所占字节数 未添加账单 96+
#define N0 2  //hash开头有N0个16进制0 
#define MaxNum 1000000 //试nonce1,nonce2的最大数 
//typedef unsigned char BYTE;             // 8-bit byte

typedef struct {
	long long chain_version;//64 bits
	BYTE prev_hash[32];//256
	long long nonce1;//64
	long long nonce2;//64
	BYTE coinbase[32];//256 挖矿者公钥
	double award;//64 挖矿奖励 
	//BILL bill[2];//1000笔交易打包为一个区块  试验时为方便取2 
} BLOCK;
typedef struct {
	BYTE from[32];//256 来源者公钥 
	double amount;//64 转移币数
	BYTE to[32];//256 去向者公钥 
	char time[16];//eg: 2021/03/30/16:05 
}BILL; //704

void Block_init(BLOCK *p);
int Mining(SHA256_CTX *ctx,BLOCK *p,BYTE *hash,int n0);
//找到nonce1 nonce2 使得block的hash满足开头有n0个16进制0 
#endif  
