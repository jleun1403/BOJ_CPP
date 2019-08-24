#include <bits/stdc++.h>

using namespace std;

// answer : 정답이 저장될 배열
// even : 주어진 입력의 길이가 짝수이면 true, 홀수이면 false
// n : 주어진 문자열의 길이
char answer[100000];
bool even;
int n;

// 문자열에서 채워야 하는 위치가 left, right 이고, 현재 남은 알파벳들의 개수가 capacity에 저장되어 있을 때
// Anti Panlindrome을 만들 수 있는지를 반환 
// capacity[0] 에는 a의 개수, capacity[1] = b의 개수 .... capacity[25] 에는 z의 개수가 들어있음

bool possible(int left, int right, vector<int> &capacity) {
	// 기저사례 : left >= right 이면 true
	// left == right (가운데에서 만나는 경우)이면 가운데 글자를 채워줌
	if (left > right) return true;
	if (left == right) {
		for (int i = 0 ; i < 26 ; i++) {
			if (capacity[i] > 0)
				answer[left] = i + 'a';
		}
		return true;
	}
	// remained_length = 앞으로 채워야 할 문자열의 길이 
	// 중간에 어떤 단계에서라도 한 문자가 남은 문자열의 길이의 반 보다 크면 (홀짝여부에 따라 미세하게 다름)
	// 절대 Anti Palindrome 을 만들 수 없음. 
	int remained_length = n - left*2;
	for (int i = 0 ; i < 26 ; i++ ){
		if (even) {
			if (capacity[i] > remained_length / 2) {
				return false;
			}
		}
		else {
			if (capacity[i] > remained_length / 2 + 1) {
				return false;
			}
		}
	}
	
	// first = 남은 문자열에서 첫번째로 오는 문자. (answer[left] 에 채워질 문자)
	// 그 문자를 사용할 것이므로 capacity[i] 를 1 만큼 감소시키고, answer[left] 는 
	// 해당하는 문자로 채운다.
	char first;
	for (int i = 0 ; i < 26 ; i++) {
		if (capacity[i] > 0) {
			first = i + 'a';
			capacity[i] -= 1;
			break;
		}
	}
	answer[left] = first;

	// answer[right] 에 채워질 문자를 탐색
	// 이 문자는 first랑 달라야 하며, 사전순으로 앞설 수 없다.
	// 아직 capacity가 남아있고, first 보다 뒤에있는 문자를 찾으면,
	// answer[right] 는 그 문자로 채워주고 capacity[i]를 1만큼 감소
	// 남은 capacity로 left+1과 right-1을 채울 수 있으면 true 반환 

	for (int i = 25 ; i >= 0 ; i--) {
		if (capacity[i] > 0 ) {
			if (i+'a' <= first)
				break;
			capacity[i]--;
			answer[right] = i+'a';
			if (possible(left+1, right-1, capacity)) {
				return true;
			}
			// 남은 알파벳들로 Anti Palindrome 을 만들 수 없는 경우
			// 마지막 문자를 바꿔가면서 시도해야 하므로
			// 현재 시도했던 capacity[i] 는 다시 1 늘려줌
			capacity[i]++;
		}
	}
	// 이 단계까지 왔으면 마지막 문자를 그 어떤 문자로 하더라도 capacity 에 저장된 문자열로는
	// Anti Palindrome 을 만들 수 없으므로
	// 첫번째 문자 역시 쓰지 않게된다. 따라서 first에 해당하는 index의 capacity도 다시 늘려주고
	// false 를 반환.
	capacity[first - 'a'] += 1;
	return false;

}


int main() {
	string s;
	cin >> s;
	n = s.length();
	vector<int> capacity(26, 0);
	even = (s.length() % 2) == 0;
	// String 을 입력받고 capacity 배열 생성
	for (int i = 0 ; i < s.length() ; i++) {
		capacity[s[i]- 'a'] += 1;
	}

	// 0번째와 문자열의 길이를 양 끝으로 하는 Anti Palindrome을 생성할 수 있으면
	// answer를 출력 . 생성할 수 없으면 -1 출력.
	if (possible(0, n-1, capacity)) {
		for (int i = 0 ; i < s.length() ; i++) {
			printf("%c", answer[i]);
		}
		printf("\n");
	}
	else printf("-1");

	return 0;
}