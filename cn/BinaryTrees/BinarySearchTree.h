
class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

    void deleteData(int data)
    {
        root = deleteData(data, root);
    }

    void insert(int data)
    {
        root = insert(data, root);
    }

    bool hasData(int data)
    {
        return hasData(data, root);
    }

    void printTree()
    {
        printTree(root);
    }

private:
    BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (data > root->data)
        {
            node->right = deleteData(data, node->right);
        }
        else if (data < node->data)
        {
            node->left = deleteData(data, node->right);
        }
        else
        {
            if (node->right == NULL && node->left == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *next = node->right;
                node->right = NULL;
                delete node;
                return next;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *next = node->left;
                node->left = NULL;
                delete node;
                return next;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(rightMin, node->right);
                return node;
            }
        }
        return node;
    }

    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if (data < node->data)
        {
            node->left = insert(data, node->left);
        }
        else
        {
            node->right = insert(data, node->right);
        }
        return node;
    }

    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }

        if (node->data == data)
        {
            return true;
        }
        else if (node->data > data)
        {
            return hasData(data, node->left);
        }
        else
        {
            return hasData(data, node->right);
        }
    }

    void printTree(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << ":";
        if (node->left != NULL)
        {
            cout << "L" << node->left->data;
        }
        if (node->right != NULL)
        {
            cout << "R" << node->right->data;
        }
        cout << endl;
        printTree(node->left);
        printTree(node->right);
    }
};