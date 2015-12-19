#include <iostream>
#include <fstream>
#include <string>
#include "graph.h"
#include <vector>

using namespace std;

const int m = 4;

void print(Graph* graph)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << get(graph, i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void pathFinder(Graph* graph)
{
	for (int k = 0; k < m; k++)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!hasEdge(graph, i, k) || !hasEdge(graph, k, j) || i == j)
				{
					continue;
				}
				int const weight = get(graph, i, k) + get(graph, k, j);
				if ((get(graph, i, k) + get(graph, k, j) < get(graph, i, j)) || !hasEdge(graph, i, j))
				{
					setWeight(graph, i, j, weight);
				}
			}
		}
	}
}

void Prim(Graph* graph)
{
	int path[m*m] = { 0 }; 
	int path_index = 0;
	int visited[m] = { 0 };
	int min = 999;
	int minWeight = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (get(graph, i, j) == 0)
			{
				setWeight(graph, i, j, 999);
			}
		}
	}
	int change = 0;
	int onePartOfLine = 0;
	int twoPartOfLine = 0;
	int makeVisited = 0;
	visited[0] = 1;
	int check = 1;
	while (check < m)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				if (get(graph, i, j) < min)
					if (visited[i] != 0)
					{
						min = get(graph, i, j);
						change = i;
						onePartOfLine = i;
						makeVisited = j;
						twoPartOfLine = j;
					}
		if (visited[onePartOfLine] == 0 || visited[twoPartOfLine] == 0)
		{
			path[path_index] = makeVisited;
			path_index++;
			check++;
			minWeight += min;
			min = 999;
			visited[makeVisited] = 1;

		}
		setWeight(graph, change, makeVisited, 999);
	}
	cout << "\n -- " << 1;
	for (int i = 0; i < m - 1; i++)
	{
		cout << " -- " << path[i] + 1;
	}
	cout << "\n Minimum weight - " << minWeight << endl;
}

void main()
{
	Graph* graph = createGraph(m);
	ifstream file("test.txt", ios::in);
	if (!file)
	{
		cout << "Файл не найден" << endl; 
	}
	while (!file.eof())
	{
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int x = 0;
				file >> x;
				setWeight(graph, i, j, x);
			}
		}
	}
	file.close();
	print(graph);
	Prim(graph);
	deleteGraph(graph, m);
	system("pause");
}