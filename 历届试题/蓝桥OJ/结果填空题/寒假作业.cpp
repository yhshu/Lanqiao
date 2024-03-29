/*
现在小学的数学题目也不是那么好玩的。
看看这个寒假作业：
□ + □ = □
□ - □ = □
□ × □ = □
□ ÷ □ = □
每个方块代表1~13中的某一个数字，但不能重复。
比如：
6 + 7 = 13
9 - 8 = 1
3 * 4 = 12
10 / 2 = 5
以及：
7 + 6 = 13
9 - 8 = 1
3 * 4 = 12
10 / 2 = 5
就算两种解法。（加法，乘法交换律后算不同的方案）
你一共找到了多少种方案？
请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
 */

#include <iostream>

using namespace std;

bool vis[15];
int map[15];
int ans;

void DFS(int pos) {
    if (pos == 13) {
        if (map[12] * map[11] == map[10]) {
            ans++;
            return;
        }
    } else if (pos == 4) {
        if (map[1] + map[2] != map[3])
            return;
    } else if (pos == 7) {
        if (map[4] - map[5] != map[6])
            return;
    } else if (pos == 10) {
        if (map[7] * map[8] != map[9])
            return;
    }
    for (int i = 1; i <= 13; ++i) {
        if (vis[i])continue;
        vis[i] = true;
        map[pos] = i;
        DFS(pos + 1);
        vis[i] = false;
        map[pos] = 0;
    }

}

int main() {
    DFS(1);
    cout << ans;
    return 0;
}
