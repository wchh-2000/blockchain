#ifndef mining_h
#define mining_h

#include "sha256.h"
#define blockBytes 96 //ÿ��������ռ�ֽ��� δ����˵� 96+
#define N0 2  //hash��ͷ��N0��16����0 
#define MaxNum 1000000 //��nonce1,nonce2������� 
//typedef unsigned char BYTE;             // 8-bit byte

typedef struct {
	long long chain_version;//64 bits
	BYTE prev_hash[32];//256
	long long nonce1;//64
	long long nonce2;//64
	BYTE coinbase[32];//256 �ڿ��߹�Կ
	double award;//64 �ڿ��� 
	//BILL bill[2];//1000�ʽ��״��Ϊһ������  ����ʱΪ����ȡ2 
} BLOCK;
typedef struct {
	BYTE from[32];//256 ��Դ�߹�Կ 
	double amount;//64 ת�Ʊ���
	BYTE to[32];//256 ȥ���߹�Կ 
	char time[16];//eg: 2021/03/30/16:05 
}BILL; //704

void Block_init(BLOCK *p);
int Mining(SHA256_CTX *ctx,BLOCK *p,BYTE *hash,int n0);
//�ҵ�nonce1 nonce2 ʹ��block��hash���㿪ͷ��n0��16����0 
#endif  
