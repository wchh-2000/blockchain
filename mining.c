#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "mining.h"
void struct2str(BLOCK *p,BYTE *s)
//区块结构体转为字符数组 用于计算hash 
//每次运行字符数组会被更新 
{
	int i;
	for(i=0;i<blockBytes;i++)
		s[i]=*((BYTE *)p+i);
	s[i]="\0";//以空字符结尾 便于以后得到字符长度 
}
void long2str(long long n,BYTE *s)//long long 64bits 分成8个BYTE 
{
	int i;
	long long a=n;
	for(i=0;i<8;i++)
		s[i]=*((BYTE *)&a+i);
}
void Block_init(BLOCK *p)
{
	int i;
	p->chain_version=101;
	memset(p->prev_hash, 0, sizeof(BYTE) * 32);
	p->nonce1=0;
	p->nonce2=0;
	for(i=0;i<32;i++)
		p->coinbase[i]=rand()%256;//0-255随机数 
	p->award=100;
	//p->bill[0].from=
}
int Mining(SHA256_CTX *ctx,BLOCK *p,BYTE *hash,int n0)
//找到nonce1 nonce2 使得block的hash满足开头有n0个16进制0 
//试不同nonce，区块转为字符数组 验证verify 存下最终nonce, hash 
{
	long long i,j;
	int v;
	int k;
	BYTE str[blockBytes+1];//以空字符结尾 所以+1 
	struct2str(p,str);
	v=verify(ctx,str,hash,n0);
	
	for(i=0;v==0&& i<MaxNum;i++)
	{
		long2str(i,&str[40]);//直接修改字符数组内的值，避免重新struct2str 提高效率 
		for(j=0;v==0 && j<MaxNum;j++)
		{
			long2str(j,&str[48]);
			v=verify(ctx,str,hash,n0);
		} 
		if(v)//满足要求
		{
			p->nonce1=i;
			p->nonce2=j;
			/*
			for (k = 0; k < 96; k++)
				printf("%d ", str[k]);
			printf("\n");验证字符串数组*/ 
			printf("nonce1:%lld nonce2:%lld\n",i,j);//注意lld才能正确显示long long  
			return 1;
		}
	}
	return 0;
}
int verify(SHA256_CTX *ctx,BYTE *str,BYTE *hash,int n)
// 字符串数组str 使得hash前n个16进制数为0 满足返回1 
{
	int i;
	sha256_update(ctx, str, strlen(str));
	sha256_final(ctx, hash);
	if(n%2==0)
	{
		for(i=0;i<n/2;i++)
			if(hash[i]!=0)
			{
				return(0);
			}
		return(1);		
	} 
	else//n为奇数 
	{
		for(i=0;i<(n-1)/2;i++)
			if (hash[i]!=0)
			{
				return(0);
			}
		if (hash[i]<=0x0f)//第n个十六进制位为0
			return(1);
		else
			return(0);
	}
		
}
