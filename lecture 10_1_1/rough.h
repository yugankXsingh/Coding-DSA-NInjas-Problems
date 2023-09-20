
template <typename T>
class TreeNode
{
    T data;
    vector<TreeNode<T> *> Children;

    TreeNode(T data)
    {
        this->data = data;
    }
};