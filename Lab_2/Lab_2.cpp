//Pember, Kevin

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