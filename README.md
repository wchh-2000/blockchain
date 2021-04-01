# blockchain
mining.h中定义了区块结构体数据格式,还没有添加交易记录。
![image](https://user-images.githubusercontent.com/69345371/113304322-81313400-9334-11eb-871d-a93d44a0552d.png)

使用sha-256杂凑算法。 尝试改变区块中的nonce1, nonce2, 使得整个区块block得到的hash值前n个16进制数为0.
n=2时（8 bits is 0）结果 下面一行为block的hash
![image](https://user-images.githubusercontent.com/69345371/113302773-f8fe5f00-9332-11eb-9d6d-fe3345457a16.png)
