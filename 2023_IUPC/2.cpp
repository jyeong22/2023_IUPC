#include<iostream>
#include <vector>
using namespace std;

int n, m;
int score[2][3];
vector<pair<int, int>> v; // j, scroe 저장
vector<int> vec; // (0, 0) ~ (5, 5) 저장
vector<int> result;

void calc() {
	int sum = v[vec[0]].second;
	for (int i = 1; i < n; ++i) {
		if (v[vec[i]].first == v[vec[i - 1]].first) {
			sum += v[vec[i]].second / 2;
		}
		else {
			sum += v[vec[i]].second;
		}
	}
	result.push_back(sum);
}

void print() {
	int i = vec[0];
	int j = vec[1];
	cout << i << " " << j << "\n";
}

void count(int cur_index) {
	if (cur_index == n) {
		calc();
		return;
	}
	for (int i = 0; i < 6; ++i) {
		vec.push_back(i);
		count(cur_index + 1);
		vec.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m; 

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> score[i][j];
			v.push_back({ j, score[i][j] });
		}
	}
	count(0);

	int cnt = 0;
	for (int i = 0; i < result.size(); ++i) {
		if (result[i] >= m) {
			++cnt;
		}
	}
	cout << cnt;
}