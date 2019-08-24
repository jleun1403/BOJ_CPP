#include<bits/stdc++.h>
using namespace std;
char c[6][16];

int main()
{
	int i, j;
	for (i = 0; i < 5; i++)
		scanf("%s", c[i]);
	for(j=0;j<15;j++){
		for (i = 0; i < 5; i++)
		{
			if ((c[i][j] >= 'a'&&c[i][j] <= 'z') || (c[i][j] >= 'A'&&c[i][j] <= 'Z') || (c[i][j] >= '0'&&c[i][j] <= '9'))
				printf("%c",c[i][j]);
		}

    }
    return 0;
}