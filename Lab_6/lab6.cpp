// Pember Kevin

// Part 1
void iterSwapStacks(stack<int> &first, stack<int> &second)
{
    int size = first.size() - 1;
    int topVal = 0;
    int i = 0;
    int j = 0;
    while (i != size)
    {
        topVal = first.top();
        first.pop();
        for (j = 0; j < (size - i); ++j)
        {
            second.push(first.top());
            first.pop();
        }
        first.push(topVal);
        for (j = 0; j < (size - i); ++j)
        {
            first.push(second.top());
            second.pop();
        }
        ++i;
    }
    while (!first.empty())
    {
        second.push(first.top());
        first.pop();
    }
}

// Part 2
void recurSwapStacks(stack<int> &first, stack<int> &second)
{
    if (first.size() == 1)
    {
        second.push(first.top());
        first.pop();
    }
    else
    {
        int storedVal = first.top();
        first.pop();
        recurSwapStacks(first, second);
        second.push(storedVal);
    }
}
// Part 3
void stlSwapStacks(stack<int> &first, stack<int> &second)
{
    second.swap(first);
}

// Part 4
void moveStacks(stack<int> &first, stack<int> &second)
{
    second = move(first);
}