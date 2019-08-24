

#include <cstdio>

#include <cstring>

#include <vector>

#include <algorithm>

using namespace std;

struct Quest {

    int s, i, point;

};

int N;

Quest quest[101];

bool visit[101];

int dp[1001][1001];

int solve(int Str, int Int) {

    int &ret = dp[Str][Int];

    if (ret != -1) return ret;

    ret = 0;

    int save_point = 0;

    vector<int> save;

    for (int n = 0;n < N;n++) {

        if (quest[n].s <= Str || quest[n].i <= Int) {

            if (!visit[n]) {

                visit[n] = true;

                save.push_back(n);

                save_point += quest[n].point;

            }

            ret++;

        }

    }

 

    for (int s = Str; s <= min(1000, Str + save_point);s++) {

        int i = min(1000, Int + save_point - (s - Str));

        ret = max(ret, solve(s, i));

    }

    for (int &s : save) visit[s] = false;

    return ret;

}

int main() {

    memset(dp, -1, sizeof dp);

    scanf("%d", &N);

    for (int n = 0;n < N;n++)

        scanf("%d%d%d", &quest[n].s, &quest[n].i, &quest[n].point);


    printf("%d\n", solve(1, 1));

    return 0;
}