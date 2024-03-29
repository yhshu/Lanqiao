/*
交换瓶子

有N个瓶子，编号 1 ~ N，放在架子上。

比如有5个瓶子：
2 1 3 5 4

要求每次拿起2个瓶子，交换它们的位置。
经过若干次后，使得瓶子的序号为：
1 2 3 4 5

对于这么简单的情况，显然，至少需要交换2次就可以复位。

如果瓶子更多呢？你可以通过编程来解决。

输入格式为两行：
第一行: 一个正整数N（N<10000）, 表示瓶子的数目
第二行：N个正整数，用空格分开，表示瓶子目前的排列情况。

输出数据为一行一个正整数，表示至少交换多少次，才能完成排序。

例如，输入：
5
3 1 2 5 4

程序应该输出：
3

再例如，输入：
5
5 4 3 2 1

程序应该输出：
2

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。
 */

#include <iostream>

using namespace std;

int main() {
    int N, res = 0;
    cin >> N;
    int nums[N + 5] = {};
    for (int i = 1; i <= N; i++)
        cin >> nums[i];

    // 选择排序，nums[i]应当为i，否则向后查找i，交换
    for (int i = 1; i <= N; i++) {
        if (nums[i] != i) {
            for (int j = i + 1; j <= N; j++) {
                if (nums[j] == i) {
                    swap(nums[i], nums[j]);
                    res++;
                }
            }
        }
    }
    cout << res;
    return 0;
}
