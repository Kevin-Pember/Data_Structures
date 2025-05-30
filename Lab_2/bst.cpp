// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
using namespace std;

void bfs(
    const vector<vector<int>> &adjMatrix,
    list<int> &bfsSequence,
    int startNode
    )
{
    const int nodeCount = static_cast<int>(adjMatrix.size());

    bool *visitedNodes = new bool[nodeCount];
    fill_n(visitedNodes, nodeCount, false);

    queue<int> nodeQueue;
    nodeQueue.push(startNode);

    visitedNodes[startNode] = true;
    bool allVisited = false;
    int i = 0;
    while (!nodeQueue.empty())
    {
        bfsSequence.push_back(nodeQueue.front());

        for (i = 0; i < nodeCount; ++i)
        {
            if (
                visitedNodes[i] != true &&
                adjMatrix[nodeQueue.front()][i] == 1
                )
            {
                visitedNodes[i] = true;
                nodeQueue.push(i);
            }
        }

        while (allVisited && (i < nodeCount))
        {
            cout << visitedNodes[i] << endl;
            allVisited = visitedNodes[i];
            ++i;
        }

        if (!allVisited)
        {
            nodeQueue.pop();
        }
        else
        {
            while (!nodeQueue.empty())
            {
                bfsSequence.push_back(nodeQueue.front());
                nodeQueue.pop();
            }
        }
    }
    delete[] visitedNodes;
    visitedNodes = nullptr;
}

int main()
{
    vector<vector<int>> graph1 = {
        // columns 0  1  2  3
        {0, 1, 0, 1}, // row 0
        {0, 0, 1, 0}, // row 1
        {1, 0, 0, 0}, // row 2
        {0, 0, 0, 0}, // row 3
    };

    list<int> sequence1;
    bfs(graph1, sequence1, 0);
    for (int node : sequence1)
    {
        cout << " " << node;
    }
    cout << "   ";
    vector<vector<int>> graph2 = {
        // 0  1  2  3  4  5  6  7  8  9  10
        {
            0,
            1,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
        }, // row 0
        {
            0,
            0,
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
        }, // row 1
        {
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
        }, // row 2
        {
            0,
            0,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            0,
        }, // row 3
        {
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            1,
            0,
        }, // row 4
        {
            0,
            0,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
        }, // row 5
        {
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
        }, // row 6
        {
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
        }, // row 7
        {
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            1,
        }, // row 8
        {
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            1,
        }, // row 9
        {
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
        }, // row 10
    };
    list<int> sequence2;
    bfs(graph2, sequence2, 0);
    for (int node : sequence2)
    {
        cout << " " << node;
    }
    return 0;
}
