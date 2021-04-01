# blockchain
mining.h中定义了区块结构体数据格式,还没有添加交易记录。
![image](https://user-images.githubusercontent.com/69345371/113304322-81313400-9334-11eb-871d-a93d44a0552d.png)

使用sha-256杂凑算法。 尝试改变区块中的nonce1, nonce2, 使得整个区块block得到的hash值前n个16进制数为0.
n=2时（8 bits is 0）结果 
![image](https://user-images.githubusercontent.com/69345371/113305806-f9e4c000-9335-11eb-84ac-06fa812c477a.png)

n=5:
![image](https://user-images.githubusercontent.com/69345371/113305628-d0c42f80-9335-11eb-8ab4-097158949c00.png)

