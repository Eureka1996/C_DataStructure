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
bool judge(int &start)//�ж��Ƿ���ŷ��·�����߻�·  ��������������
{
	bool flag = false;//��һ�����Ƿ��ҵ��ı�־
	bool churu = false;
	bool ruchu = false;
	int fa;
	int num = 0;
	for (int i = 0; i<nmax; i++)//�������ͼ������ͨ��
	{
		if (rudu[i] || chudu[i])//�������Ƿ��������������
		{
			if (!flag)
			{
				fa = findfa(i);//�洢���ڵ�
				flag = true;//�ҵ���һ����
			}
			else
			{
				if (fa != findfa(i))
					return false;
			}
			start = i;//����ǻ������һ��������Ϊ������
		}
	}
	for (int i = 0; i<nmax; i++)//�����Ⱥͳ��ȵĹ�ϵ
	{
		if (rudu[i] != chudu[i]) num++;//��¼���Ȳ�������ȵĶ���ĸ���
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
	if ((ruchu&&churu&&num == 2) || num == 0)//���ֻ����������Ⱥͳ��Ȳ��� ��һ����ȱȳ��ȴ�һ һ�����ȱ���ȴ�һ���߳��ȵ������
		return true;
	else
		return false;
}
void dfs(int s)
{
	struct edge *temp;
	int id;
	for (temp = mg.v[s].first; temp; temp = temp->next)//�����ָ���Լ��ı� ���ȷ����Լ�
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
		init();//��ʼ��ͼ�����ӱ�
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