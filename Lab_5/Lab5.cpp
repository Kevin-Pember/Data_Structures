// Pember, Kevin

// Part 1
int hashValue(int key, int j, int capacity)
{
    return (((3 * key) + 3) + (j * j)) % capacity;
}

// Part 2
void insertKey(int table[], int capacity, int &numElements, int key)
{
    int j = 0;
    int hashIndex = 0;
    while (j < LIMIT)
    {
        hashIndex = hashValue(key, j, capacity);
        if (table[hashIndex] <= 0)
        {
            table[hashIndex] = key;
            ++numElements;
            j = LIMIT;
        }
        else if (table[hashIndex] == key)
        {
            cout << "Key " << key << " is a duplicate." << endl;
            j = LIMIT;
        }
        ++j;
    }
    if (j == LIMIT)
    {
        cout << "Key " << key << " not inserted. Need to rehash."
             << endl;
    }
}

// Part 3
bool searchKey(const int table[], int capacity, int key)
{
    int j = 0;
    int hashIndex = 0;
    bool found = false;
    while (j < LIMIT && !found)
    {
        hashIndex = hashValue(key, j, capacity);
        if (table[hashIndex] == key)
        {
            found = true;
        }
        else if (!table[hashIndex])
        {
            j = LIMIT;
        }
        ++j;
    }
    return found;
}

// Part 4
void deleteKey(int table[], int capacity, int &numElements, int key)
{
    int j = 0;
    int hashIndex = 0;
    while (j < LIMIT)
    {
        hashIndex = hashValue(key, j, capacity);
        if (table[hashIndex] == key)
        {
            table[hashIndex] = -2;
            --numElements;
            j = LIMIT;
        }
        else if (!table[hashIndex])
        {
            j = LIMIT - 1;
        }
        ++j;
    }
    if (j == LIMIT)
    {
        cout << "Key " << key << " is not in the table." << endl;
    }
}