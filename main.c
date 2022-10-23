#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
�켱�� ��ü ���� ���� ��������(KindNum)�� �˾Ƴ���. -> ����� kind��� �� �迭�� ����� ���� ���ڿ� �ش�Ǵ�
                                                        ��ġ�� 0�̸� �������� ++���ش�.(0�� �ƴϸ� �̹� �ѹ� ��ĵ�� ��ġ�̹Ƿ� �н�)
kind��� �� �迭�� ���� ���ڿ� �ش�Ǵ� ������ �����̴�. -> kind[3] = 7�̸� 3�̶�� ������ 7�� �ִٴ� ��

���� 1���� 2���� ���� ���� ���� ������ ������ �����´�. �̶� 1���� ���� ���� ���� ��ü ���� ���� ��������.

������ ��ĵ�ϸ鼭 �ش� ���� ������ kind��ġ�� ���� 1�� ���ش�. �׸��� üŷ����Ʈ�� ���� ���� 2�� ģ����
���ʷ� �� ������ �������� �����͸� �����Ѵ�. -> üŷ����Ʈ[3] = 0�̸� 2��ģ���� ���� 3�� ������ ������ ���ߴ�.

üŷ����Ʈ�� 2�� ģ���� ���� ���� ���� �ֽ�ȭ�ϰ� (üŷ����Ʈ�� ���� 0�̸� 1�� �ٲٰ� ������ +1) kind�迭�� ���鼭
1�� ģ���� ���� ������ �ֽ�ȭ�Ѵ�. (������ ������ ������ �� ���� ������ kind��ġ�� 1�� ���µ� 0�� �Ǹ� 2�� ģ����
�� ������ ������ ���� ����̹Ƿ� ���������� 1�� ����.)
*/

// topping_len�� �迭 topping�� �����Դϴ�.
int solution(int topping[], size_t topping_len) {
    int* kind = (int*)malloc(sizeof(int) * topping_len);
    int* CheckingList = (int*)malloc(sizeof(int) * topping_len);
    int KindNum = 0;
    int KindNum2 = 0;
    int answer = 0;

    for (int i = 0; i < topping_len; i++)
    {
        kind[i] = 0;
    }

    for (int i = 0; i < topping_len; i++)
    {
        if (kind[topping[i]] == 0)
        {
            KindNum++;
        }
        kind[topping[i]] += 1;
    }

    for (int i = 0; i < topping_len; i++)
    {
        if (CheckingList[topping[i]] != 1)
        {
            KindNum2++;
            CheckingList[topping[i]] = 1;
        }
        kind[topping[i]] -= 1;
        if (kind[topping[i]] == 0)
        {
            KindNum--;
        }
        if (KindNum2 == KindNum)
        {
            answer++;
        }
    }
    return answer;
}