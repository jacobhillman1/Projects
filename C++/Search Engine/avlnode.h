#ifndef AVLNODE
#define AVLNODE

template<class T>
class AvlNode
{
private:
    T data;
    AvlNode<T>* left;
    AvlNode<T>* right;
    int height;
public:
    AvlNode<T>(const T& theData, AvlNode<T>* lt, AvlNode<T>* rt,
            int h = 0) : data(theData), left(lt), right(rt),
            height(h) {}
    template<class U> friend class AvlTree;
};


#endif // AVLNODE

