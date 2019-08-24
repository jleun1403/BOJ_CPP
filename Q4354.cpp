#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>

using namespace std;

char tmp[1000001];

// 실패함수
int getPi(string p)
{
	int max = 0;
	int m = (int)p.size();
	int j = 0;

	vector<int> pi(m, 0);

	for (int i = 1; i< m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
		{
			pi[i] = ++j;
			if (pi[i] > max)
				max = pi[i];
		}
	}
	return pi[m-1];
}

int main()
{
	int n;

	string str, p;

	while(1)
	{
		scanf("%s", tmp);

		str = tmp;

		// .인 경우 종료
		if (str.size() == 1 && str[0] == '.')
			return 0;

		// 실페 함수중 최대 크기를 가진 값을 ans에 저장
		int ans = getPi(str);

		// 출력 과정
		if (ans == 0 || str.size() % (str.size() -ans) != 0)
			printf("1\n");
		else
			printf("%d\n", str.size() / (str.size() - ans));
	}

	return 0;
}
