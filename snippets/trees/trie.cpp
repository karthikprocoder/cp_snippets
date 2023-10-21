/*
                                        [v1, v2, v3, ....vn]
                                            n children
                                    [v1, v2, ...vn]

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{

    vector<Node *> children;
    bool is_leaf;

    Node(int N)
    {
        children.resize(N, NULL);
        is_leaf = false;
    }
};

template<typename T>
struct Trie
{
public:
    Trie(int N_)
    {
        N = N_;
        root = new Node(N);
    }

    void add(vector<T>& v) 
    {
        Node* trav = root;
        for(T x : v) 
        {
            /* when T = char */
            /* x = x - 'a' */
            if(!trav->children[x])
                trav->children[x] = new Node(N);
            trav = trav->children[x];
        }
        trav->is_leaf = true;
    }

    bool has_prefix(vector<T>& v)
    {
        Node* trav = root;
        for(T x : v)
        {
            /* when T = char */
            /* x = x - 'a' */
            if(!trav->children[x])
                return false;
            trav = trav->children[x];
        }
        return true;
    }

    bool has(vector<T>& v)
    {
        Node* trav = root;
        for(T x : v)
        {
            /* when T = char */
            /* x = x - 'a' */
            if(!trav->children[x])
                return false;
            trav = trav->children[x];
        }
        return trav->is_leaf;
    }

private:
    int N;
    Node *root;
};