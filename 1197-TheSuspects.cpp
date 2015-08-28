#include<bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define ull unsigned long long
using namespace std;
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define mod 1000000007
class Uns
{
private:
	vector<int> Rank, Parent, Size;
public:
	Uns(int N)
	{
		Rank.assign(N, 0);
		Size.assign(N, 1);
		Parent.assign(N, 0);
		for (int i = 0; i < N; i++)
			Parent[i] = i;
	}
	int find_set(int i)
	{
		return Parent[i] == i ? i : (Parent[i]=find_set(Parent[i]));
	}
	void join_set(int i, int j)
	{
		if (find_set(i) != find_set(j))
		{
			int x = find_set(i), y = find_set(j);
			if (Rank[x]>Rank[y])
			{
				Parent[y] = x;
				Size[x] += Size[y];
			}
			else
			{
				Parent[x] = y;
				Size[y] += Size[x];
				if (Rank[x] == Rank[y])
				{
					Rank[y]++;
				}
			}
		}
	}
	int set_size(int i)
	{
		return Size[find_set(i)];
	}
};
int main()
{
	int n, m, k, x, temp;

	while (scanf("%d %d", &n, &m))
	{
		if (n == 0 && m == 0)break;
		Uns u(n);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &k,&temp);
			for (int j = 1; j < k; j++)
			{
				scanf("%d", &x);
				u.join_set(temp, x);
				temp = x;
			}
		}
		printf("%d\n", u.set_size(0));
	}
	system("pause");

}