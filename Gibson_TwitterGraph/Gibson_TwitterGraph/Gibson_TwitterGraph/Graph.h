//Denzell Gibson
//8/17/2017

#ifndef GRAPH_H_
#define GRAPH_H_

#include "Header.h"

const double max_weight = std::numeric_limits<double>::infinity(); //Makes max weight infinite.

//Node that holds a weight and a target.
class Node
{
public:
	Node(int, double); //Constructor that takes the target and weight.

	int target; //Represents the relationship between the source node and the target node, the source being the element in the list.
	double weight; //A directed graph is weighted so that some relationships between nodes are more important than others, and the shortest path between nodes is affected by weight.
};

typedef std::vector<std::vector<Node> > adjacencyList;

//Constructor that takes the target and weight.
Node::Node(int newTarget, double newWeight)
{
	target = newTarget;
	weight = newWeight;
}

//Computes the cost from source to the target node.
void dijkstraComputePaths(int source,
	const adjacencyList &adjList,
	std::vector<double> &minDistance,
	std::vector<int> &previous)
{
	int n = adjList.size(); //Holds all nodes in the graph.
	minDistance.clear(); //Clears minDistance.
	minDistance.resize(n, max_weight); //Makes minDistance to the size of all the nodes in the graph.
	minDistance[source] = 0; //Makes the source node equal to 0 in relation to the other nodes in the graph.
	previous.clear(); //Clears previous.
	previous.resize(n, -1); //Resizes to the number of nodes in the graph.
	std::set<std::pair<double, int>> vertexQueue; //Creates a set of pairs of double and int.
	vertexQueue.insert(std::make_pair(minDistance[source], source)); //Inserts a pair of the source value in the vector, which is 0, 
	//and the source's actual value that was passed in, into the set.

	while (!vertexQueue.empty()) //While the set is not empty...
	{
		double distance = vertexQueue.begin()->first; //Make distance equal to the first value in the first pair in the set.
		int u = vertexQueue.begin()->second; //Makes u equal to the second value in the first pair in the set.
		vertexQueue.erase(vertexQueue.begin()); //Erases the first pair in the set.

		const std::vector<Node> &nodes = adjList[u]; //Make a constant assigned to array of adjList of the size of u, which is an array of vectors of vectors of Nodes.
		for (std::vector<Node>::const_iterator Node_iter = nodes.begin(); //Makes an iterator for the vector.
			Node_iter != nodes.end();
			Node_iter++)
		{
			int v = Node_iter->target; //Make the variable equal to the current node's target.
			double weight = Node_iter->weight; //Make the variable equal to the current node's weight.
			double distanceU = distance + weight; //Combines the distance and the weight, creating a weight distance for calculating shortest distance.
			if (distanceU < minDistance[v]) //If weighted distance is less than the minDistance of the target node in relation to the source node...
			{
				vertexQueue.erase(std::make_pair(minDistance[v], v)); //Erases the target node from the queue.
				minDistance[v] = distanceU; //Replaces the minimum distance with the weighted distance.
				previous[v] = u; //Replaces the target with the weight of the source.
				vertexQueue.insert(std::make_pair(minDistance[v], v)); //Adds the target node into the queue.
			}
		}
	}
}

//Finds the shortest path from source to a target.
std::list<int> dijkstraGetShortestPathTo(
	int vertex, const std::vector<int> &previous)
{
	std::list<int> path; //Creates a list that will hold all the nodes to the target.
	for (; vertex != -1; vertex = previous[vertex]) //For as long as vertex does not equal -1
		path.push_front(vertex); //Adds the the node to the front of the path.
	return path;
}

#endif