#include <iostream>
#include "graph.h"

using namespace std;


Graph* createGraph(int vertex)
{
	Graph *graph = new Graph;
	graph->array = new int*[vertex];
	for (int i = 0; i < vertex; ++i)
	{
		graph->array[i] = new int[vertex];
	}
	graph->vertexNumber = vertex;
	return graph;
}

void setWeight(Graph* graph, int vertex1, int vertex2, int weight)
{
	graph->array[vertex1][vertex2] = weight;
	graph->array[vertex2][vertex1] = weight;
}

int get(Graph* graph, int vertex1, int vertex2)
{
	return graph->array[vertex1][vertex2];
}

bool hasEdge(Graph* graph, int vertex1, int vertex2)
{
	return (graph->array[vertex1][vertex2] != 0);
}

void deleteGraph(Graph* graph, int vertex)
{
	for (int i = 0; i < vertex; ++i)
	{
			delete graph->array[i];
	}
}
