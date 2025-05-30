if(totalNodes == 0)
{
   cerr << "Cannot delete from an empty tree." << endl;
}
else if(totalNodes == 1)
{
   delete root;
   root = nullptr;
   --totalNodes;
}
else
{
   Node* current = root;
   Node* above = nullptr;
   while(current != nullptr && current->data != itemToDelete)
   {
      if(current->data > itemToDelete)
      {
         above = current;
         current = current->llink;
      }
      else if(current->data < itemToDelete)
      {
         above = current;
         current = current->rlink;
      }
      
   }
   if(current == nullptr)
   {
      cerr << "The item to delete is not in the tree." << endl;
   }
   else if(current->llink == nullptr && current->rlink == nullptr)
   {
      if(current->data < above->data)
      {
         delete above->llink;
         above->llink = nullptr;
      }
      else
      {
         delete above->rlink;
         above->rlink = nullptr;
      }
      --totalNodes;
   }
   else if(current->llink != nullptr && current->rlink != nullptr)
   {
      deleteInternalNode(current);
      --totalNodes;
   }
   else if(current->llink == nullptr && current->rlink != nullptr)
   {
      deleteNoLeftSubtree(current, above);
      --totalNodes;
   }
   else if(current->llink != nullptr && current->rlink == nullptr)
   {
      deleteNoRightSubtree(current, above);
      --totalNodes;
   }
   
}
