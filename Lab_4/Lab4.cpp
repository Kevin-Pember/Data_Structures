// Pember, Kevin

void BST::deleteItem(itemToDelete)
{
    if (root == nullptr)
    {
        cerr << "Cannot delete from an empty tree." << endl;
    }
    else
    {
        Node *head = this->root;
        Node *parent;
        bool searching = true;
        while (head != nullptr && searching)
        {
            if (head->data == itemToDelete)
            {
                searching = false;
            }
            else
            {
                parent = head;
                if (head->data > itemToDelete)
                {

                    head = head->llink;
                }
                else
                {
                    head = head->rlink;
                }
            }
        }
        if (head == nullptr)
        {
            cerr << "The item to delete is not in the tree."
                 << endl;
        }
        else
        {
            --this->totalNodes;
            if (head->llink == nullptr && head->rlink == nullptr)
            {
                if (head == this->root)
                {
                    this->root = nullptr;
                }
                else
                {
                    if (parent->llink == head)
                    {
                        parent->llink = nullptr;
                    }
                    else
                    {
                        parent->rlink = nullptr;
                    }
                }
                delete head;
            }
            else if (head->rlink == nullptr)
            {
                BST::deleteNoRightSubtree(head, parent);
            }
            else if (head->llink == nullptr)
            {
                BST::deleteNoLeftSubtree(head, parent);
            }
            else
            {
                BST::deleteInternalNode(head);
            }
        }
    }
}