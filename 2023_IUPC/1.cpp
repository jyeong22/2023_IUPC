#include <iostream>
using namespace std;

int alpha[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin >> s;
	
	for (int i = 0; i < s.size(); ++i) {
		alpha[s[i] - 65]++;
	}
	if (alpha['M' - 65] > 0 && alpha['O' - 65] > 0 && alpha['B' - 65] > 0 && alpha['I' - 65] > 0
		&& alpha['S' - 65] > 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}