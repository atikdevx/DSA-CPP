#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int vertices;
    list<int>*l;
    Graph(int n){
        vertices=n;
        l=new list<int>[vertices];
    }
    void add(int a,int b){
        l[a].push_back(a);
        l[b].push_back(b);
    }

};