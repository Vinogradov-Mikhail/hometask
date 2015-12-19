#pragma once

struct Graph
{
	int ** array;
	int vertexNumber;
};

Graph* createGraph(int vertex);

void setWeight(Graph* graph, int vertex1, int vertex2, int weight);

int get(Graph* graph, int vertex1, int vertex2);

bool hasEdge(Graph* graph, int vertex1, int vertex2);

void deleteGraph(Graph* graph, int vertex);


