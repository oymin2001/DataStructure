#include<iostream>
#include<string>
#include"graph.h"
#define NUM_NODES 16
#define NUM_EDGES 50

typedef Graph::Vertex Vertex;
typedef Graph::Edge Edge;
typedef std::vector<Graph::Vertex> VtxList;
typedef std::list<Graph::Edge> EdgeList;
typedef std::vector<Graph::Vertex>::iterator VtxItor;
typedef std::list<Graph::Edge>::iterator EdgeItor;

int main()
{
	Vertex v[NUM_NODES] =
	{
		Vertex("A",0,UNEXPLORED),   Vertex("B",1,UNEXPLORED),
		Vertex("C",2,UNEXPLORED),   Vertex("D",3,UNEXPLORED),
		Vertex("E",4,UNEXPLORED),   Vertex("F",5,UNEXPLORED),
		Vertex("G",6,UNEXPLORED),   Vertex("H",7,UNEXPLORED),
		Vertex("I",8,UNEXPLORED),   Vertex("J",9,UNEXPLORED),
		Vertex("K",10,UNEXPLORED),   Vertex("L",11,UNEXPLORED),
		Vertex("M",12,UNEXPLORED),   Vertex("N",13,UNEXPLORED),
		Vertex("O",14,UNEXPLORED),   Vertex("P",15,UNEXPLORED),
	};
	Graph::Edge edges[NUM_NODES] =
	{
		Edge(v[0],v[1],10),     Edge(v[1],v[0],10),
		Edge(v[0],v[4],10),     Edge(v[4],v[0],10),
		Edge(v[0],v[5],15),     Edge(v[5],v[0],15),
		Edge(v[1],v[2],10),     Edge(v[2],v[1],10),
		Edge(v[1],v[5],10),     Edge(v[5],v[1],10),
		Edge(v[2],v[3],10),     Edge(v[3],v[2],10),
		Edge(v[2],v[6],10),     Edge(v[6],v[2],10),
		Edge(v[3],v[6],15),     Edge(v[6],v[3],15),
		Edge(v[3],v[7],10),     Edge(v[7],v[3],10),
		Edge(v[4],v[5],10),     Edge(v[5],v[4],10),
		Edge(v[4],v[8],10),     Edge(v[8],v[4],10),
		Edge(v[5],v[8],15),     Edge(v[8],v[5],15),
		Edge(v[6],v[9],15),     Edge(v[9],v[6],15),
		Edge(v[6],v[10],10),     Edge(v[10],v[6],10),
		Edge(v[6],v[11],15),     Edge(v[11],v[6],15),
		Edge(v[7],v[11],10),     Edge(v[11],v[7],10),
		Edge(v[8],v[9],10),     Edge(v[9],v[8],10),
		Edge(v[8],v[12],10),     Edge(v[12],v[8],10),
		Edge(v[8],v[13],15),     Edge(v[13],v[8],15),
		Edge(v[9],v[10],10),     Edge(v[10],v[9],10),
		Edge(v[10],v[13],15),     Edge(v[13],v[10],15),
		Edge(v[10],v[14],10),     Edge(v[14],v[10],10),
		Edge(v[11],v[15],10),     Edge(v[15],v[11],10),
		Edge(v[12],v[13],10),     Edge(v[13],v[12],10),
		Edge(v[14],v[15],10),     Edge(v[15],v[14],10),
	};

	Graph simpleGraph(NUM_NODES);

	std::cout << "Inserting vertices .." << '\n';
	for (int i = 0; i < NUM_NODES; i++)
	{
		simpleGraph.insertVertex(v[i]);
	}

	VtxList vtxLst;
	simpleGraph.vertices(vtxLst);

	int count = 0;
	std::cout << "Insrted vertices:";
	for (VtxItor vItor = vtxLst.begin(); vItor != vtxLst.end(); ++vItor)
	{
		std::cout << *vItor << "  ";
	}
	std::cout << '\n';

	std::cout << "Inserting edges.." << '\n';
	for (int i = 0; i < NUM_EDGES; i++)
	{
		simpleGraph.insertEdge(edges[i]);
	}
	std::cout << "Inserted edges: " << '\n';
	count = 0;
	EdgeList egLst;
	simpleGraph.edges(egLst);

	for (EdgeItor p = egLst.begin(); p != egLst.end(); ++p)
	{
		count++;
		std::cout << *p << ", ";
		if (count % 5 == 0)
			std::cout << '\n';
	}
	std::cout << '\n';

	std::cout << "Print out Graph based on Adjacency List.." << '\n';
	simpleGraph.printGraph();
}