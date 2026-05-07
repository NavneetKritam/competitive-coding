// Link https://atcoder.jp/contests/arc218/tasks/arc218_b
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdio>
#include <algorithm>
#include <random>
using namespace std;

int fp(vector<int>&, unordered_map<string, int>&);
int sp(vector<int>&, unordered_map<string, int>&);

int fp(vector<int>& bb, unordered_map<string, int>& score_map) {
	//TODO: Return the defeated conditions empty means it is defeated returns -1
	if (bb.size() == 0)
		return -1;
	// TODO: Convert the bb into a representation of string with A at the end
	string rep = "";
	for (auto i : bb)
		rep = rep + to_string(i) + ",";
	rep = rep + "A";
	int ans = -1;
	//TODO: Check if value already exists in map
	if (score_map.find(rep) == score_map.end()) {
		//TODO: Fech first element, check if that is not zero or zero
		int first = bb[0];
		if (first > 0) {
			//TODO: ITerate from 1 to first and creata a new vector each time subtracting that much
			for (int i = 1; i <= first; i++) {
				vector<int> temp;
				for (int j = 0; j < bb.size(); j++)
					temp.push_back(bb[j] - i);
				int temp_score = sp(temp, score_map);
				temp.clear();
				if (i == 1)
					ans = temp_score;
				// TODO: It will try to maximize the score aka win 1 is this
				else if (temp_score > ans)
					ans = temp_score;
				if (ans == 1)
					break;
			}
		}
		else {
			for (int i = 0; i < bb.size(); i++) {
				if (bb[i] > 0)
					break;
				vector<int> temp;
				for (int j = i + 1; j < bb.size(); j++)
					temp.push_back(bb[j]);
				int temp_score = sp(temp, score_map);
				temp.clear();
				if (i == 0)
					ans = temp_score;
				else if (temp_score > ans)
					ans = temp_score;
				if (ans == 1)
					break;
			}

		}
		score_map[rep] = ans;
		return ans;
	}
	else {
		return score_map[rep];
	}
}

int sp(vector<int>& bb, unordered_map<string, int>& score_map) {
	//TODO: Return the defeated condition empty means it is defeated returns 1
	if (bb.size() == 0)
		return 1;
	// Convert the bb into a representation of string with B at the end
	string rep = "";
	for (auto i : bb)
		rep = rep + to_string(i) + ",";
	rep = rep + "B";
	//TODO: Check if value already exists in map
	int ans = 1;
	if (score_map.find(rep) == score_map.end()) {
		//TODO: Fech first element, check if that is not zero or zero
		int first = bb[0];
		if (first > 0) {
			//TODO: ITerate from 1 to first and creata a new vector each time subtracting that much
			for (int i = 1; i <= first; i++) {
				vector<int> temp;

				for (int j = 0; j < bb.size(); j++)
					temp.push_back(bb[j] - i);
				int temp_score = fp(temp, score_map);
				temp.clear();
				if (i == 1)
					ans = temp_score;
				// TODO: It will try to minimize the score aka win -1 is this
				else if (temp_score < ans)
					ans = temp_score;
				if (ans == -1)
					break;
			}
		}
		else {
			for (int i = 0; i < bb.size(); i++) {
				if (bb[i] > 0)
					break;
				vector<int> temp;
				for (int j = i + 1; j < bb.size(); j++)
					temp.push_back(bb[j]);
				int temp_score = fp(temp, score_map);
				temp.clear();
				if (i == 0)
					ans = temp_score;
				else if (temp_score < ans)
					ans = temp_score;
				if (ans == -1)
					break;
			}

		}
		score_map[rep] = ans;
		return ans;
	}
	else {
		return score_map[rep];
	}
}

int test_gen() {
	int t, n, temp;
	//scanf("%d", &t);
	random_device rd;
	int max_t = 10, max_n = 200;
	FILE* inp, * op;
	fopen_s(&inp, "input.txt", "w");
	fopen_s(&op, "output.txt", "w");
	t = rd() % max_t + 1;
	fprintf(inp, "%d\n", t);
	while (t--) {
		n = rd() % max_t + 1;
		fprintf(inp, "%d\n", n);
		unordered_map<string, int> score_map;
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			temp = rd() % max_n;
			fprintf(inp, "%d ", temp);
			arr.push_back(temp);
		}
		fprintf(inp, "\n");
		sort(arr.begin(), arr.end());
		int score = fp(arr, score_map);
		fprintf(op, "%s\n", (score == 1) ? "Alice" : "Bob");
	}
	fclose(inp);
	fclose(op);
	return 0;
}