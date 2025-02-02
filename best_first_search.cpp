// #include <iostream>
// #include <vector>
// #include <queue>
// #include <functional> // Include the functional header for the custom comparator
// using namespace std;

// // Define a custom struct to represent nodes in the graph
// struct Node {
//     int id;
//     double heuristic; // Evaluation function value (heuristic)
// };

// // Define a custom comparator struct for the priority queue
// struct NodeComparator {
//     bool operator()(const Node& a, const Node& b) const {
//         return a.heuristic > b.heuristic; // Min-heap based on heuristic values
//     }
// };

// // Define the graph as an adjacency matrix and store heuristic values
// vector<vector<int>> adj_matrix;
// vector<double> heuristic_values;

// // Function to perform Best-First Search
// void bestFirstSearch(int startNode, int goalNode) {
//     int n = adj_matrix.size();
//     vector<bool> visited(n, false);

//     // Create a priority queue for Best-First Search using the custom comparator
//     priority_queue<Node, vector<Node>, NodeComparator> pq;

//     pq.push({startNode, heuristic_values[startNode]}); // Initialize with the start node and its heuristic

//     while (!pq.empty()) {
//         Node currentNode = pq.top();
//         pq.pop();

//         int cv = currentNode.id;

//         if (cv == goalNode) {
//             cout << "Goal node " << goalNode << " reached." << endl;
//             return;
//         }

//         if (!visited[cv]) {
//             visited[cv] = true;
//             cout << "Visited node " << cv << endl;

//             // Iterate through neighbors
//             for (int i = 0; i < n; ++i) {
//                 if (adj_matrix[cv][i] && !visited[i]) {
//                     double heuristicValue = heuristic_values[i];
//                     pq.push({i, heuristicValue});
//                 }
//             }
//         }
//     }

//     cout << "Goal node " << goalNode << " not reached." << endl;
// }

// int main() {
//     int n, e;
//     cout << "Enter the number of vertices and edges: ";
//     cin >> n >> e;

//     adj_matrix.resize(n, vector<int>(n, 0));
//     heuristic_values.resize(n, 0.0);

//     cout << "Enter the edges: " << endl;
//     for (int i = 0; i < e; i++) {
//         int fv, lv;
//         cin >> fv >> lv;
//         adj_matrix[fv][lv] = 1; // undirected graph
//         adj_matrix[lv][fv] = 1;
//     }

//     cout << "Enter heuristic values for each node: " << endl;
//     for (int i = 0; i < n; i++) {
//         cin >> heuristic_values[i];
//     }

//     int startNode, goalNode;
//     cout << "Enter the start node: ";
//     cin >> startNode;
//     cout << "Enter the goal node: ";
//     cin >> goalNode;

//     cout << "Best-First Search Traversal path: " << endl;
//     bestFirstSearch(startNode, goalNode);

//     return 0;
// }



#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

// Define a custom struct to represent nodes in the graph
struct Node {
    int id;
    double heuristic; // Updated heuristic
    double cost; // Cost to reach the node
};

// Define a custom comparator struct for the priority queue
struct NodeComparator {
    bool operator()(const Node& a, const Node& b) const {
        return (a.heuristic + a.cost) > (b.heuristic + b.cost); // Min-heap based on f values (heuristic + cost)
    }
};

// Define the graph as an adjacency matrix and store heuristic values
vector<vector<int>> adj_matrix;
vector<double> heuristic_values;

// Function to perform Best-First Search
void bestFirstSearch(int startNode, int goalNode) {
    int n = adj_matrix.size();
    vector<bool> visited(n, false);

    // Create a priority queue for Best-First Search using the custom comparator
    priority_queue<Node, vector<Node>, NodeComparator> pq;

    pq.push({startNode, heuristic_values[startNode], 0}); // Initialize with the start node, updated heuristic, and cost

    while (!pq.empty()) {
        Node currentNode = pq.top();
        pq.pop();

        int cv = currentNode.id;

        if (cv == goalNode) {
            cout << "Goal node " << goalNode << " reached." << endl;
            return;
        }

        if (!visited[cv]) {
            visited[cv] = true;
            cout << "Visited node " << cv << endl;

            for (int i = 0; i < n; ++i) {
                if (adj_matrix[cv][i] && !visited[i]) {
                    double heuristicValue = heuristic_values[i];
                    double costToNeighbor = currentNode.cost + 1; // Assuming unit cost for all edges
                    pq.push({i, heuristicValue, costToNeighbor});
                }
            }
        }
    }

    cout << "Goal node " << goalNode << " not reached." << endl;
}

int main() {
    int n, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> e;

    adj_matrix.resize(n, vector<int>(n, 0));
    heuristic_values.resize(n, 0.0);

    cout << "Enter the edges: " << endl;
    for (int i = 0; i < e; i++) {
        int fv, lv;
        cin >> fv >> lv;
        adj_matrix[fv][lv] = 1; // undirected graph
        adj_matrix[lv][fv] = 1;
    }

    cout << "Enter updated heuristic values for each node: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> heuristic_values[i];
    }

    int startNode, goalNode;
    cout << "Enter the start node: ";
    cin >> startNode;
    cout << "Enter the goal node: ";
    cin >> goalNode;

    cout << "Best-First Search Traversal path: " << endl;
    bestFirstSearch(startNode, goalNode);

    return 0;
}

