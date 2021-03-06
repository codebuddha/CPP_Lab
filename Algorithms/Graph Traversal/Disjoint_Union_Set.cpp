/*
 * Disjoint_Union_Set.cpp
 * Created on: 28-11-2018
 * Author: Abhirup
*/
#include<iostream>
#include<stdio.h>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
template<typename T>
struct Node{
    int rank=0;
    T data;
    struct Node<T>* parent=this;
    Node (T x)
    {
        data = x;
        // display();
    }
    Node (int r, T x)
    {
        rank = r;
        data = x;
    }
    Node (int r, T x, Node *par)
    {
        rank = r;
        data = x;
        parent = par;
    }
    Node (struct Node<T> *p)
    {
        this = p;
    }
    void display()
    {
        printf("Rank:%d Data:%d ParentData:%d\n", rank, data, parent->data);
    }
};
template<typename T>
class Set{
public:
    static Node<T>* findSet(Node<T> &a)
    {
        Node<T>* temp(&a);
        while(temp->parent != temp)
            temp = temp->parent;
        return temp;
    }
    static void unionSet(Node<T> &a, Node<T> &b)
    {
        Node<T> *par_a = findSet(a), *par_b = findSet(b);
        if(par_a->data == par_b->data)
        {
            cout << "Same parent!\n";
            return;
        }
        if(par_a->rank >= par_b->rank)
        {
            b.rank = 0;
            b.parent = par_a;
            par_a->rank = 1;
        }
        else
        {
            a.rank = 0;
            a.parent = par_b;
            par_b->rank = 1;
        }
    }
};
using si = Set<int>;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Node<int>> ver;
    vector<std::pair<int, int>> edges(e);
    for(int i=0; i<n; i++)
        ver.push_back(Node<int>(i));
    cout << "\n";
    for(Node<int> i : ver)//for without &
        i.display();
}