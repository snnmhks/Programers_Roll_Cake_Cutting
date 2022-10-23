#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
우선은 전체 토핑 종류 가짓수를(KindNum)을 알아낸다. -> 방법은 kind라는 빈 배열을 만들고 토핑 숫자에 해당되는
                                                        위치가 0이면 가짓수를 ++해준다.(0이 아니면 이미 한번 스캔한 위치이므로 패스)
kind라는 빈 배열은 토핑 숫자에 해당되는 토핑의 갯수이다. -> kind[3] = 7이면 3이라는 토핑이 7개 있다는 뜻

이후 1번과 2번의 토핑 종류 수를 저장할 변수를 가져온다. 이때 1번의 토핑 종류 수는 전체 토핑 종류 가짓수다.

토핑을 스캔하면서 해당 토핑 숫자의 kind위치의 값을 1씩 빼준다. 그리고 체킹리스트를 따로 만들어서 2번 친구가
최초로 그 토핑을 마주했을 데이터를 저장한다. -> 체킹리스트[3] = 0이면 2번친구는 아직 3번 토핑을 가지지 못했다.

체킹리스트로 2번 친구의 토핑 종류 수를 최신화하고 (체킹리스트의 값이 0이면 1로 바꾸고 가짓수 +1) kind배열을 보면서
1번 친구의 토핑 종류를 최신화한다. (토핑을 마주할 때마다 그 토핑 숫자의 kind위치를 1씩 빼는데 0이 되면 2번 친구는
그 토핑을 가지지 못한 경우이므로 가짓수에서 1을 뺀다.)
*/

// topping_len은 배열 topping의 길이입니다.
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