#include <bits/stdc++.h>

using namespace std;

struct person{
	int age;
	string name;
	int order;
};

bool cmp(person &p1, person &p2) {
	if (p1.age == p2.age) {
		return p1.order < p2.order;
	}
	return p1.age < p2.age;
}

vector<person> v;


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0 ; i < n ;i++) {
		int age;
		string name;
		cin >> age >> name;
		person p;
		p.age = age;
		p.name = name;
		p.order = i;
		v.push_back(p);
	}
	//sort(v.begin(), v.begin() + n, cmp);
	//for (int i = 0 ; i < )
	sort(v.begin(), v.end(), cmp);
	for (int i = 0 ; i < n ;i++) {
		cout << v[i].age << ' ' << v[i].name << '\n';
	}
	return 0;
}