/*

标题：史丰收速算

    史丰收速算法的革命性贡献是：从高位算起，预测进位。不需要九九表，彻底颠覆了传统手算!

    速算的核心基础是：1位数乘以多位数的乘法。

    其中，乘以7是最复杂的，就以它为例。

    因为，1/7 是个循环小数：0.142857...，如果多位数超过 142857...，就要进1

    同理，2/7, 3/7, ... 6/7 也都是类似的循环小数，多位数超过 n/7，就要进n

    下面的程序模拟了史丰收速算法中乘以7的运算过程。

    乘以 7 的个位规律是：偶数乘以2，奇数乘以2再加5，都只取个位。

    乘以 7 的进位规律是：
	满 142857... 进1,
	满 285714... 进2,
	满 428571... 进3,
	满 571428... 进4,
	满 714285... 进5,
	满 857142... 进6

    请分析程序流程，填写划线部分缺少的代码。
*/

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

//计算个位：偶数乘以2，奇数乘以2加5
int ge_wei(int a) {
    if (a % 2 == 0)
        return (a * 2) % 10;
    else
        return (a * 2 + 5) % 10;
}

//计算进位 
int jin_wei(char *p) {
    char *level[] = {
            "142857",
            "285714",
            "428571",
            "571428",
            "714285",
            "857142"
    };

    char buf[7];
    buf[6] = '\0';
    strncpy(buf, p, 6);

    int i;
    for (i = 5; i >= 0; i--) { // 从高位开始
        int r = strcmp(level[i], buf);
        if (r < 0) return i + 1;
        while (r == 0) {
            p += 6;
            strncpy(buf, p, 6);
            r = strcmp(level[i], buf);
            if (r < 0) return i + 1;
            return i; // 填空
        }
    }

    return 0;
}

//多位数乘以7
void f(char *s) {
    int head = jin_wei(s);
    if (head > 0) printf("%d", head);

    char *p = s;
    while (*p) {
        int a = (*p - '0');
        int x = (ge_wei(a) + jin_wei(p + 1)) % 10;
        printf("%d", x);
        p++;
    }

    printf("\n");
}

int main() {
    cout << 428571428571 * 7 << endl << 34553834937543 * 7 << endl;
    f("428571428571");
    f("34553834937543");

    return 0;
}
