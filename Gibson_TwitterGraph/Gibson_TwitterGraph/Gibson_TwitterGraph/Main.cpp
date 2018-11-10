//Denzell Gibson
//8/17/2017

#include "Header.h"
#include "Graph.h"

int main()
{
	//Creates a list of six nodes.
	adjacencyList adjacency_list(6);
	
	//Adds edges to the nodes in the list.
	adjacency_list[0].push_back(Node(1, 7));
	adjacency_list[0].push_back(Node(2, 9));
	adjacency_list[0].push_back(Node(5, 14));

	adjacency_list[1].push_back(Node(0, 7));
	adjacency_list[1].push_back(Node(2, 10));
	adjacency_list[1].push_back(Node(3, 15));

	adjacency_list[2].push_back(Node(0, 9));
	adjacency_list[2].push_back(Node(1, 10));
	adjacency_list[2].push_back(Node(3, 11));
	adjacency_list[2].push_back(Node(5, 2));

	adjacency_list[3].push_back(Node(1, 15));
	adjacency_list[3].push_back(Node(2, 11));
	adjacency_list[3].push_back(Node(4, 6));

	adjacency_list[4].push_back(Node(3, 6));
	adjacency_list[4].push_back(Node(5, 9));

	adjacency_list[5].push_back(Node(0, 14));
	adjacency_list[5].push_back(Node(2, 2));
	adjacency_list[5].push_back(Node(4, 9));

	std::vector<double> min_distance;
	std::vector<int> previous;
	dijkstraComputePaths(0, adjacency_list, min_distance, previous);
	std::cout << "Distance from 0 to 4: " << min_distance[4] << std::endl;
	std::list<int> path = dijkstraGetShortestPathTo(4, previous);
	//path = dijkstraGetShortestPathTo(3, previous);
	std::cout << "Path : ";
	std::copy(path.begin(), path.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	system("pause");
	return 0;
}