#include <bits/stdc++.h>
using namespace std;

struct Trie
{
	map<int, int> ch;
	int val;
};

class Solution
{
public:
	Trie t[20005];

	int cnt = 0;
	int root = 0;
	int createNode()
	{
		cnt++;
		t[cnt].ch.clear();
		t[cnt].val = 0;
		return cnt;
	}

	void insert(string &s)
	{
		auto r = root;
		for (auto c : s)
		{
			if (t[r].ch[c - 'a'] == 0)
				t[r].ch[c - 'a'] = createNode();
			r = t[r].ch[c - 'a'];
		}
		t[r].val++;
	}

	void init(vector<string> &products)
	{
		root = createNode();
		for (auto s : products)
			insert(s);
	}

	int findPre(string &target, int pos, int r)
	{
		if (r == 0)
			return 0;
		if (pos == target.length())
			return r;
		int next_r = t[r].ch[target[pos] - 'a'];
		return findPre(target, pos + 1, next_r);
	}

	void qfind(int r, int &cnt, string &s, vector<string> &res)
	{
		if (r == 0)
			return;
		if (!cnt)
			return;
		for (int i = 0; i < t[r].val; i++)
		{
			if (cnt <= 0)
				break;
			cnt--;
			res.push_back(s);
		}
		for (int i = 0; i < 26; i++)
		{
			s.push_back((char)(i + 'a'));
			qfind(t[r].ch[i], cnt, s, res);
			s.pop_back();
		}
	}

	void query(string &searchWord, vector<vector<string>> &res)
	{
		string pre = "";
		for (auto c : searchWord)
		{
			pre += c;
			int pre_r = findPre(pre, 0, root);
			vector<string> temp_res;
			int cnt = 3;
			string x = "";
			qfind(pre_r, cnt, x, temp_res);
			for (auto &ele : temp_res)
				ele = pre + ele;
			res.push_back(temp_res);
		}
	}

	vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
	{
		init(products);
		vector<vector<string>> res;
		query(searchWord, res);
		return res;
	}
};