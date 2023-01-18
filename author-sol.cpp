#include <bits/stdc++.h>
using namespace std;

void test_case(int& tc) {
	int n;
	cin >> n;
	auto cmp = [](const pair<int, int>& x, const pair<int, int>& y) {
		return x > y; // reverse the order of the set
	};
	set<pair<int, int>, decltype(cmp)> s(cmp);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > 0) {
			s.insert(make_pair(x, i + 1));
		}
	}
	vector<pair<int, int>> indices;
	while (s.size() > 1) {
		// remove the two highest elements
		auto p1 = *s.begin();
		s.erase(p1);
		auto p2 = *s.begin();
		s.erase(p2);
		indices.push_back(make_pair(p1.second, p2.second));
		// insert them back
		if (p1.first > 1) {
			s.insert(make_pair(p1.first - 1, p1.second));
		}
		if (p2.first > 1) {
			s.insert(make_pair(p2.first - 1, p2.second));
		}
	}
	cout << indices.size() << "\n";
	for (pair<int, int>& p : indices) {
		cout << p.first << " " << p.second << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
