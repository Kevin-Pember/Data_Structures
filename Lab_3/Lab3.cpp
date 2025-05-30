// Pember, Kevin

// Part 1
void BST::nonRecursiveInsert(int elemToInsert)
{
    Node *insertNode = new Node;
    insertNode->data = elemToInsert;

    if (root == nullptr)
    {
        this->root = insertNode;
        ++count;
    }
    else
    {
        Node *head = this->root;
        while (head != insertNode)
        {
            if (head->data > elemToInsert)
            {
                if (head->llink != nullptr)
                {
                    head = head->llink;
                }
                else
                {
                    head->llink = insertNode;
                    ++count;
                    head = insertNode;
                }
            }
            else if (head->data < elemToInsert)
            {
                if (head->rlink != nullptr)
                {
                    head = head->rlink;
                }
                else
                {
                    head->rlink = insertNode;
                    ++count;
                    head = insertNode;
                }
            }
            else if (head->data == elemToInsert)
            {
                cerr << "Element " << elemToInsert
                     << " is already in the list. Duplicates are "
                        "not "
                        "allowed."
                     << endl;
                delete insertNode;
                head = insertNode;
            }
        }
    }
}

// Part 2
void BST::nonRecursiveInorder() const
{

    stack<Node *> nodeBackorder;
    Node *current = root;

    while (current != nullptr || !nodeBackorder.empty())
    {

        while (current != nullptr)
        {
            nodeBackorder.push(current);
            current = current->llink;
        }

        current = nodeBackorder.top();
        nodeBackorder.pop();
        cout << current->data << " ";

        current = current->rlink;
    }
    cout << endl;
}