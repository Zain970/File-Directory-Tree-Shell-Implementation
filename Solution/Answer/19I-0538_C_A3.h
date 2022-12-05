#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////// Stack Implementation  /////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class X>
class Node2
{
public:
    X data;
    Node2<X>* Next;
public:
    Node2()
    {
        this->Next = NULL;
    }
};

template<class X>
class stack
{
public:
    Node2<X>* Top;
public:
    stack()
    {
        this->Top = NULL;
    }
    void push(X data)
    {
        Node2<X>* temp;
        temp = new Node2<X>();
        if (!temp)
        {
            cout << "Heap Overflow" << std::endl;
        }
        temp->data = data;
        temp->Next = Top;
        Top = temp;
    }

    bool empty()
    {
        if (this->Top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ///////////////////////////////////////////////// Return The Top Of The Stack /////////////////////////////////////////////////////
    X top()
    {
        if (!empty())
        {
            return Top->data;
        }
        else
        {
            std::cout << "The stack is empty " << std::endl;
            exit(1);

        }
    }

    ////////////////////////////////////////////////// Pop Element From the Stack /////////////////////////////////////////////////////
    void pop()
    {
        Node2<X>* temp;
        if (Top == NULL)
        {
            std::cout << "Stack Underflow" << endl;

        }
        else
        {
            temp = Top;
            Top = Top->Next;
            temp->Next = NULL;
            delete temp;
        }
    }
};

stack <std::string>S1;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////  QUEUE IMPLEMENTATION /////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class X>
class node
{
public:
    X data;
    node<X>* Next;
};

template <class X>
class Queue
{
public:
    node<X>* Front;
    node<X>* Rear;

public:
    Queue()
    {
        Front = NULL;
        Rear = NULL;
    }

    // CHECKS IF THE QUEUE IS EMPTY
    bool empty()
    {
        if (Front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(X n)
    {
        node<X>* newNode = new node<X>;
        newNode->data = n;

        newNode->Next = NULL;
        if (Front == NULL && Rear == NULL)
        {
            Front = newNode;
            Rear = newNode;
        }
        else
        {
            Rear->Next = newNode;
            Rear = newNode;
        }
    }

    X front()
    {
        if (empty())
        {
            cout << "The queue is empty " << std::endl;
        }
        return Front->data;
    }

    void pop()
    {
        if (empty())
        {
            std::cout << "The queue is empty .Cannot be dequeued " << std::endl;
        }
        else
        {
            if (this->Front == this->Rear)
            {
                Front = NULL;
                Rear = NULL;
            }
            else
            {
                node<X>* T = Front;
                Front = Front->Next;
                delete T;
            }
        }
    }
    int size()
    {
        int s = 0;
        if (empty())
        {
            std::cout << "The queue is empty " << std::endl;
            return s;
        }
        else
        {
            node<X>* T = Front;
            while (T != NULL)
            {
                T = T->Next;
                s = s + 1;
            }
            return s;
        }
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////// DYNAMIC ARRAY CLASS FOR CHILDREN /////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class dynamicClass
{
public:
    T* arr;
    int capacity;
    int current;
public:
    dynamicClass()
    {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    void push_back(T data)
    {
        if (current == capacity)
        {
            //std::cout << "///////////////////////// Size is Full /////////////////////////" << std::endl;
            T* temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }

    void pop_back()
    {
        current--;
    }
    int size()
    {
        return current;
    }

    T& operator [](const int index)
    {
        if (index >= 0 && index <= current)
        {
            return arr[index];
        }
    }
};


/////////////////////////////////////////////////////////////////// CLASS NODE ////////////////////////////////////////////////////////////////////
template<class X>
class Node
{
public:
    X val;
    dynamicClass<Node*> child;

public:

    //////////////////////////////////////////////////////////// DEFAULT CONSTRUCTOR //////////////////////////////////////////////////////////////
    Node(std::string data)
    {
        this->val = data;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////// CLASS TREE ///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class X>
class Tree
{
public:
    Node<X>* Root;
public:

    ////////////////////////////////////////////////////// DEFAULT CONSTRUCTOR  ///////////////////////////////////////////////////////////////////
    Tree()
    {
        this->Root = NULL;
    }

    ///////////////////////////////////////////////////// INSERTS NODE INTO THE TREE //////////////////////////////////////////////////////////////
    void insert(Node<X>* root, std::string parent, std::string v)
    {
        if (this->Root == NULL)
        {
            Root = new Node<X>(v);
            //std::cout << v << " Inserted at root " << std::endl;
            //std::cout << "-----------------------" << std::endl;
            return;
        }
        else
        {
            if (root->val == parent)
            {
                int l = root->child.size();
                bool check = false;
                for (int i = 0; i < l; i++)
                {
                    if (root->child[i]->val == v)
                    {
                        check = true;
                    }
                }
                if (check == false)
                {
                    bool check2 = true;
                    for (int i = 0; i < parent.length(); i++)
                    {
                        if (parent[i] == '.')
                        {
                            check2 = false;
                            std::cout << "It is a file.It cannot have a child " << std::endl;
                        }
                    }
                    if (check2 == true)
                    {
                        Node<X>* newNode = new Node<X>(v);
                        root->child.push_back(newNode);
                        //std::cout << v << " inserted as the child of " << root->val << std::endl;
                       // std::cout << "-----------------------------" << std::endl;
                    }
                }
            }
            else
            {

                int l = root->child.size();
                for (int i = 0; i < l; i++)
                {
                    insert(root->child[i], parent, v);
                }
            }
        }
    }

    //////////////////////////////////////////////////// LEVEL ORDER TRAVERSAL OF THE TREE ////////////////////////////////////////////////////////
    void LevelOrderTraversal(Node<X>* root, std::string path)
    {
        std::cout << "-----------------------------------------------" << std::endl;
        if (root == NULL)
        {
            return;
        }
    /////////////////////////////////////////// CREATING FILE TO WRITE LEVEL ORDER TRAVERSAL IN IT ////////////////////////////////////////////////
        ofstream obj;
        obj.open(path);

        Queue<Node<X>*> q;            // Create a queue
        q.push(root);              // Enqueue root
        while (!q.empty())
        {
            int n = q.size();
            while (n > 0)
            {
                Node<X>* p = q.front();
                q.pop();
                obj << p->val;
                for (int i = 0; i < p->child.size(); i++)
                {
                    q.push(p->child[i]);
                }
                n--;
                if (n > 0)
                {
                    obj << " ";
                }
            }
            if (!q.empty())
            {
                obj << endl;
            }
        }
        std::cout << "---------------------------------------" << std::endl;
    }

    /////////////////////////////////////////////////////////// DELETE THE NODE ///////////////////////////////////////////////////////////////////
    bool deletenode(Node<X>* root, std::string folder)
    {

        if (root == NULL)
        {
            return false;
        }
        if (root->val == folder)
        {
            return true;
        }
        for (int i = 0; i < root->child.size(); i++)
        {
            bool check = false;
            check = deletenode(root->child[i], folder);
            if (check == true)
            {
                for (int k = 0; k < root->child.size(); k++)
                {
                    std::cout << root->child[k]->val << "\t";
                }
                std::cout << std::endl;
                for (int j = i; j < root->child.size() - 1; j++)
                {
                    root->child[j] = root->child[j + 1];
                }
                root->child.pop_back();
                for (int k = 0; k < root->child.size(); k++)
                {
                    std::cout << root->child[k]->val << "\t";
                }
                std::cout << std::endl;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////// Search for file or Folder in The File ///////////////////////////////////////////////////////
    bool Search(Node<X>* root, std::string folder, std::string absolutePath)
    {
        if (Root == NULL)
        {
            return false;
        }
        if (root->val == folder)
        {
            absolutePath = absolutePath + root->val;
            S1.push(absolutePath);
        }
        if (root->val != "/")
        {
            absolutePath = absolutePath + root->val + "/";
        }
        for (int i = 0; i < root->child.size(); i++)
        {
            Search(root->child[i], folder, absolutePath);
        }
        return false;
    }

    void Extract(Node<X>* root)
    {
        Queue<Node<X>*> q;
        q.push(root); 
        while (!q.empty())
        {
            int n = q.size();
            while (n > 0)
            {
                Node<X>* p = q.front();
                q.pop();
                for (int i = 0; i < p->child.size(); i++)
                {
                    q.push(p->child[i]);
                }
                if (p->val != root->val)
                {
                    S1.push(p->val);
                }
                n--;
            }
            S1.push(",");
        }
        std::string Temp[10];
        int i = 0;
        while (!S1.empty())
        {
            Temp[i] = S1.top();
            S1.pop();
            i = i + 1;
        }
        int j = 0;
        while (j < i)
        {
            if (j != 0 && j != i - 1)
            {
                S1.push(Temp[j]);
            }
            j = j + 1;
        }
        // std::cout<<"-------------------STACK-------------------"<<std::endl;
        // while (!S1.empty())
        // {
        //     std::cout << S1.top()<<"\t";
        //     S1.pop();
        // }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void MergeIt(Node<X>* Root)
    {
        std::string T;
        int i = 0;
        while (!S1.empty())
        {
            T = S1.top();
            if (T != ",")
            {
                Node<X>* newNode = new Node<X>(T);
                S1.pop();
                Root->child.push_back(newNode);
            }
            else
            {
                S1.pop();
                Root = Root->child[i];
                i = i + 1;
            }
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool MergeFolder(Node<X>* root, std::string folder1, std::string folder2)
    {
        // if tree is empty then return null
        if (Root == NULL)
        {
            return false;
        }

        if (root->val == folder1)
        {
            Extract(root);
        }
        if (root->val == folder2)
        {
            MergeIt(root);
        }
        for (int i = 0; i < root->child.size(); i++)
        {
            MergeFolder(root->child[i], folder1, folder2);
        }
        return false;
    }
};

Tree<std::string> T1;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////// Create Tree /////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void createTree(string inputFilePath)
{
    Tree<std::string> Temp;
    ifstream obj;
    obj.open(inputFilePath);
    std::string row;
    std::string column;
    int i = 1;
    std::string prev;

    while (!obj.eof())
    {
        getline(obj, row);
        stringstream S(row);
        // if (!obj.eof())
      //   {
        while (getline(S, column, '/'))
        {
            if (i == 1)
            {
                Temp.insert(Temp.Root, " ", "/");
            }
            else
            {
                Temp.insert(Temp.Root, prev, column);
            }
            if (i == 1)
            {
                prev = "/";
            }
            else
            {
                prev = column;
            }
            i = i + 1;
        }
        i = 1;
        // }
    }
    // T2.LevelOrderTraversal(T2.Root, "levelOrder.txt");
    T1 = Temp;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////// Level Order Traversal of Tree /////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void levelOrderFunction(string outputFilePath)
{
    T1.LevelOrderTraversal(T1.Root, outputFilePath);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// Insert New File Folder Into The Tree ////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void insertFileFolder(string source, string targetPath, string outputFilePath)
{
    int index = 0;
    for (int i = 0; targetPath[i] != '\0'; i++)
    {
        if (targetPath[i] == '/')
        {
            index = i;
        }
    }

    index = index + 1;

    char path[10];
    int i;
    for (i = 0; targetPath[index] != '\0'; i++, index++)
    {
        path[i] = targetPath[index];
    }
    path[i] = '\0';
    T1.insert(T1.Root, path, source);
    T1.LevelOrderTraversal(T1.Root, outputFilePath);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// DELETE A FILE OR FOLDER ////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void deleteFileFolder(string targetPath, string outputFilePath)
{
    int index = 0;
    for (int i = 0; targetPath[i] != '\0'; i++)
    {
        if (targetPath[i] == '/')
        {
            index = i;
        }
    }

    index = index + 1;

    char path[15];

    int i;

    for (i = 0; targetPath[index] != '\0'; i++, index++)
    {
        path[i] = targetPath[index];
    }
    path[i] = '\0';
    T1.deletenode(T1.Root, path);
    T1.LevelOrderTraversal(T1.Root, outputFilePath);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////// Merge Two Folders /////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mergeFolder(string sourcePath, string targetPath, string outputFilePath)
{
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; targetPath[i] != '\0'; i++)
    {
        if (targetPath[i] == '/')
        {
            index1 = i;
        }
    }
    for (int i = 0; sourcePath[i] != '\0'; i++)
    {
        if (sourcePath[i] == '/')
        {
            index2 = i;
        }
    }
    index1 = index1 + 1;
    index2 = index2 + 1;

    char path1[15];
    char path2[15];

    int i;
    int j;

    for (i = 0; targetPath[index1] != '\0'; i++, index1++)
    {
        path1[i] = targetPath[index1];
    }

    for (j = 0; sourcePath[index2] != '\0'; j++, index2++)
    {
        path2[j] = sourcePath[index2];
    }

    path1[i] = '\0';
    path2[j] = '\0';
    T1.MergeFolder(T1.Root, path2, path1);
    T1.LevelOrderTraversal(T1.Root, outputFilePath);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////// SEARCH FILE OR FOLDER ////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void searchFileFolder(string targetFileFolder, string outputFilePath)
{

    T1.Search(T1.Root, targetFileFolder, "/");

    ofstream obj;
    obj.open(outputFilePath);

    std::string Temp[5];
    int i = 0;
    while (!S1.empty())
    {
        Temp[i] = S1.top();
        S1.pop();
        i = i + 1;
    }
    int k = 0;
    while (k < i)
    {
        S1.push(Temp[k]);
        k = k + 1;
    }
    //////////////////////////////////////////////////// Writing In The File From The Stack ///////////////////////////////////////////////////////
    while (!S1.empty())
    {
        obj << S1.top();
        S1.pop();

        if (!S1.empty())
        {
            obj << endl;
        }
    }
}