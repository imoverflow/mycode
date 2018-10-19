#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

bool ls(const string& a, const string& b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}

struct Expression {
	int p, t;
	string e;

	Expression(string _e, int t_, int _p) : e(_e), t(t_), p(_p) {}

	bool operator < (const Expression& ex) const {
		if (ex.e == e) {
			if (t != ex.t) {
				return t < ex.t;
			}
			return p < ex.p;
		}
		return ls(e, ex.e);
	}
};

set<Expression> q;

const int FULL = 0xff;
const vector<int> B = {1, 2, 4, 8, 16, 32, 64, 128};
const int X_TABLE = B[4] + B[5] + B[6] + B[7];
const int Y_TABLE = B[2] + B[3] + B[6] + B[7];
const int Z_TABLE = B[1] + B[3] + B[5] + B[7];

string dp[1 << 8][3];

void add(int pr, const string& s, int mask) {
	if (dp[mask][pr].empty() || ls(s, dp[mask][pr])) {
		dp[mask][pr] = s;
		Expression e(s, mask, pr);
		q.insert(e);
	}
}

int main() {
	add(2, "x", X_TABLE);
	add(2, "y", Y_TABLE);
	add(2, "z", Z_TABLE);
	while (!q.empty()) {
		auto e = *q.begin();
		q.erase(q.begin());

		if (e.p == 2) {
			add(2, "!" + e.e, ~e.t & FULL);
			add(1, e.e, e.t);
		}

		if (e.p == 1) {
			for (int mask = 0; mask < FULL; ++mask) {
				if (!dp[mask][2].empty()) {
					add(1, dp[mask][2] + "&" + e.e, mask & e.t);
					add(1, e.e + "&" + dp[mask][2], mask & e.t);
				}
			}
			add(2, "(" + e.e + ")", e.t);
			add(0, e.e, e.t);
		}

		if (e.p == 0) {
			for (int mask = 0; mask < FULL; ++mask) {
				for (int pr = 1; pr <= 2; ++pr) {
					if (!dp[mask][pr].empty()) {
						add(0, dp[mask][pr] + "|" + e.e, mask | e.t);
						add(0, e.e + "|" + dp[mask][pr], mask | e.t);
					}
				}
			}
			add(2, "(" + e.e + ")", e.t);
		}
	}


	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int mask = 0;
		for (int i = 0; i < 8; ++i) {
			if (s[i] == '1') {
				mask |= (1 << i);
			}
		}

		cout << dp[mask][0] << endl;
	}

	return 0;
}
