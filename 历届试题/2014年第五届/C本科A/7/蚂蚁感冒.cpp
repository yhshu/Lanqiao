/*

���⣺���ϸ�ð

    ��100���׵�ϸ��ֱ��������nֻ���ϡ����ǵ�ͷ�еĳ����еĳ��ҡ� 

    ÿֻ���϶�ֻ�����Ÿ�����ǰ�����ٶ���1����/�롣

    ����ֻ��������ʱ�����ǻ�ͬʱ��ͷ���෴�ķ������С�

    ��Щ�����У���1ֻ���ϸ�ð�ˡ������ں�������������ʱ����Ѹ�ð��Ⱦ�����������ϡ�

    ������㣬���������϶��������ʱ���ж���ֻ���ϻ����˸�ð��


�����ݸ�ʽ��

    ��һ������һ������n (1 < n < 50), ��ʾ���ϵ�������

    ���ŵ�һ����n���ÿո�ֿ������� Xi (-100 < Xi < 100), Xi�ľ���ֵ����ʾ�����뿪������߶˵�ľ��롣��ֵ��ʾͷ���ң���ֵ��ʾͷ���������в������0ֵ��Ҳ���������ֻ����ռ��ͬһλ�á����У���һ�����ݴ�������ϸ�ð�ˡ�

    Ҫ�����1����������ʾ����ð���ϵ���Ŀ��

���磬���룺
3
5 -2 8
����Ӧ�����
1

�����磬���룺
5
-10 8 -20 12 25
����Ӧ�����
3

��ԴԼ����
��ֵ�ڴ����� < 256M
CPU����  < 1000ms


���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

���д������ͬһ��Դ�ļ��У�����ͨ���󣬿����ύ��Դ�롣

ע��: main������Ҫ����0
ע��: ֻʹ��ANSI C/ANSI C++ ��׼����Ҫ���������ڱ��뻷�������ϵͳ�����⺯����
ע��: ���������ĺ���������ȷ����Դ�ļ��� #include <xxx>�� ����ͨ���������ö�ʡ�Գ���ͷ�ļ���

�ύʱ��ע��ѡ���������ı��������͡�

*/

#include <iostream>

using namespace std;

const int maxn = 55;
int x[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int x0 = x[0];
    if (x0 > 0) { // ����
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (x[i] < 0 && -x[i] > x0) { // ��������
                ans++;
            }
        }
        if (ans != 1) { // �д��ҵ���
            for (int i = 0; i < n; i++) {
                if (x[i] > 0 && x[i] < x0) {
                    ans++;
                }
            }
        }
        cout << ans;
    }

    if (x0 < 0) { // ����
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (x[i] > 0 && x[i] < -x0) { // ��������
                ans++;
            }
        }
        if (ans != 1) { // �д�������
            for (int i = 0; i < n; i++) {
                if (x[i] < 0 && -x[i] > -x0) {
                    ans++;
                }
            }
        }
        cout << ans;
    }

    return 0;
}
