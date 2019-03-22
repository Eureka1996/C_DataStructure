#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
const int nmax = 27;
const int mmax = 1000;
int chudu[nmax];
int rudu[nmax];
int father[nmax];
int vis[mmax];
vector<string > mystring;
struct edge
{
	int adjvex;
	int adjid;
	struct edge *next;
	string tmp;
};
struct ver
{
	struct edge *first;
};
struct graph
{
	struct ver v[nmax];
	int mnum;
}mg;
void init()
{
	for (int i = 0; i<nmax; i++)
	{
		mg.v[i].first = NULL;
		chudu[i] = 0;
		rudu[i] = 0;
		father[i] = i;
	}
	mystring.clear();
	memset(vis, 0, sizeof(vis));
}
int findfa(int a)
{
	if (father[a] == a) return a;
	else
	{
		return father[a] = findfa(father[a]);
	}
}
void merge(int a, int b)
{
	if (findfa(b) == a)
		return;
	father[a] = b;
}
bool judge(int &start)//判断是否有欧拉路径或者回路  如果有求出出发点
{
	bool flag = false;//第一个根是否找到的标志
	bool churu = false;
	bool ruchu = false;
	int fa;
	int num = 0;
	for (int i = 0; i<nmax; i++)//检查有向图的弱连通性
	{
		if (rudu[i] || chudu[i])//输入中是否输入了这个顶点
		{
			if (!flag)
			{
				fa = findfa(i);//存储根节点
				flag = true;//找到第一个根
			}
			else
			{
				if (fa != findfa(i))
					return false;
			}
			start = i;//如果是环则随便一个顶点作为出发点
		}
	}
	for (int i = 0; i<nmax; i++)//检查入度和出度的关系
	{
		if (rudu[i] != chudu[i]) num++;//记录出度不等于入度的顶点的个数
		if (chudu[i] - rudu[i] == 1)
		{
			start = i;
			churu = true;
		}
		if (rudu[i] - chudu[i] == 1)
		{
			ruchu = true;
		}
	}
	if ((ruchu&&churu&&num == 2) || num == 0)//如果只有两个点入度和出度不等 且一个入度比出度大一 一个出度比入度大一或者出度等于入度
		return true;
	else
		return false;
}
void dfs(int s)
{
	struct edge *temp;
	int id;
	for (temp = mg.v[s].first; temp; temp = temp->next)//如果有指向自己的边 优先访问自己
	{
		if (temp->adjvex == s)
		{
			id = temp->adjid;
			if (!vis[id])
			{
				vis[id] = 1;
				mystring.push_back(temp->tmp);
				//cout<<temp->tmp<<".";
				dfs(temp->adjvex);
			}
		}
	}
	for (temp = mg.v[s].first; temp; temp = temp->next)
	{
		id = temp->adjid;
		if (!vis[id])
		{
			vis[id] = 1;
			mystring.push_back(temp->tmp);
			//cout<<temp->tmp<<".";
			dfs(temp->adjvex);
		}

	}
}
int main16(int argc, char *argv[])
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, b, start;
		string s;
		cin >> mg.mnum;
		init();//初始化图的连接表
		getchar();
		for (int i = 1; i <= mg.mnum; i++)
		{
			getline(cin, s);
			a = s[0] - 'a';
			b = s[s.length() - 1] - 'a';
			struct edge *temp = new edge;
			temp->adjvex = b;
			temp->tmp = s;
			temp->next = mg.v[a].first;
			mg.v[a].first = temp;
			temp->adjid = i;
			chudu[a]++;
			rudu[b]++;
			merge(a, b);
		}
		if (!judge(start))
		{
			cout << "***" << endl;
		}
		else
		{
			dfs(start);
			for (int i = 0; i<mystring.size(); i++)
			{
				if (i == mystring.size() - 1)
					cout << mystring[i] << endl;
				else
					cout << mystring[i] << ".";
			}
			mystring.clear();

		}
	}
	system("pause");
	return 1;
}