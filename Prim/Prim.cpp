#include "mstree.h"

priority_queue< Edge, vector<Edge>, Compare > PQ;

queue< Edge >* Q; // each vertex has a queue of incident edges

void MoveIntoPQ_EdgesOfNodes(int v) {
    Edge e;
    // Move all edges of vertex 'v' in the queue Q into PQ
    while (Q[v].empty()==false) {
       e = Q[v].front();
       PQ.push(e);
       Q[v].pop();
     }
}

void prim() {
    Sets sets(NNODES);
    int nedges = 0; // #edges found up to now.
    while (nedges < NNODES - 1) {
        if (PQ.empty()) throw "No Spanning Tree Exists.";
        Edge e = PQ.top(); 
        PQ.pop();
        // ���� ���õ� edge e�� �� ��(���)���� ��Ʈ�� ���Ѵ�.
        int v1root1 = sets.Find(e.v1);
        int v2root2 = sets.Find(e.v2);
        // PQ ���� e�� �ڰ��� ������, �� ���� WeightedUnion, nedges �����߰�, e��� 
        if (v1root1 != v2root2) {
            // �� ������WeightedUnion, nedges ���� �߰�, ����e ��� 
            sets.WeightedUnion(v1root1, v2root2);
            nedges++;
            cout << e;
        }
        // Ʈ���� ���� ó���� e�� �� ���� ����� edge���� PQ�� �ű��.
        MoveIntoPQ_EdgesOfNodes(e.v1);
        MoveIntoPQ_EdgesOfNodes(e.v2);
    }
}
void ReadEdges4prim(istream& is) {
    Edge e;
    // NNODES�� �� ��(vertex)�� ���� queue���� �迭�� �����Ѵ�.
    // �� ���� ����� ����(edges)�� ��Ÿ���� ���� 
    Q = new queue<Edge>[NNODES];

    while (GetEdge(is, e))
    {
        //�� ��(vertex �Ǵ� ���)�� ť�� ���� e�� �ִ´�. 
        // �� edge�� ����� ���� �� �� (e.v1, e.v2) 
        Q[e.v1].push(e);
        Q[e.v2].push(e);
    }

    MoveIntoPQ_EdgesOfNodes(0); // ���� �� 0�� edge���� PQ �� �̵��Ѵ�.
}

int main(int argc, char* argv[]) {
    // �Էºκ��� kruskal ���� �����ϰ�
    // �߰� �� ��

    ifstream is;
    if (argc == 1)
        is.open("kin.txt");
    else
        is.open(argv[1]);

    if (!is) {
        cerr << "No such input file\n"; exit(1);
    }

    is >> NNODES;

    try {
        ReadEdges4prim(is);
        prim();
    }
    catch (char const* str)
    {
        cerr << "Exception: " << str << endl; exit(1);
    }
}