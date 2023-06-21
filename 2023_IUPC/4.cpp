#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

int n, k;
vector<int> v;
vector<string> str_vec;
map<string, vector<string>> m;
vector<string> result;
map<string, bool> visited;
stack<string> stk;

void calc() {
	string s="";
	for (int i = 0; i < v.size(); ++i) {
		s+=(char)(v[i] + 65);
	}
	str_vec.push_back(s);
}

void count(int cur_index) {
	if (cur_index == k) {
		calc();
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (find(v.begin(), v.end(), i) == v.end()) {
			v.push_back(i);
			count(cur_index + 1);
			v.pop_back();
		}
	}
}


void dfs(string s) {

	visited[s] = true;
	stk.push(s);
	string sub_str = s.substr(1, k - 1);
	int cnt = 0;
	for (int i = 0; i < m[sub_str].size(); ++i) {
		if (visited[m[sub_str][i]] == false) {
			dfs(m[sub_str][i]);
		}
		else {
			++cnt;
		}
	}

	if (stk.size() != str_vec.size() && cnt == m[sub_str].size()) {
		string top = stk.top();
		cout << top;
		visited[top] = false;
		stk.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k; // n 종류 사탕 중에 k개 선택
	count(0);

	
	for (int i = 0; i < str_vec.size(); ++i) {
		visited[str_vec[i]] = false;
		string sub_str = str_vec[i].substr(0, k - 1);
		m[sub_str].push_back(str_vec[i]);
	}

	dfs(str_vec[0]);

	if (stk.size() == str_vec.size()) {
		cout << "YES\n";
		for (int i = 0; i < stk.size(); ++i) {
			cout << stk.top() << " ";
			stk.pop();
		}
	}
	else {
		cout << "NO";
	}
}