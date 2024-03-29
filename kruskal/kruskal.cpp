#include "mstree.h"

priority_queue< Edge, vector<Edge>, Compare > PQ;   //minheap

void kruskal() {
    Sets sets(NNODES);
    int nedges = 0; // #edges found up to now.
    while ((nedges < NNODES - 1) && !PQ.empty()) {
        // 최소비용 간선e 선택 
        Edge e = PQ.top();

        // e를 PQ에서 삭제
        PQ.pop();
        // 간선e의 각 점v1 과 v2가 어느 집합에 속했는지 Find.
        int v1root1 = sets.Find(e.v1);
        int v2root2 = sets.Find(e.v2);

        // e가 사이클을 만들지 않는다면 
        if (v1root1 != v2root2) {
            // 두 집합을WeightedUnion, nedges 갯수 추가, 간선e 출력 
            sets.WeightedUnion(v1root1, v2root2);
            nedges++;
            cout << e;
        }
    }
}

void ReadEdges4kruskal(istream& is) {
    Edge e;
    while (GetEdge(is, e))
        PQ.push(e);
}

int main(int argc, char* argv[]) {
    ifstream is;
    if (argc == 1) 
        is.open("kin.txt");
    else 
        is.open(argv[1]);

    if (!is) { 
        cerr << "No such input file\n"; exit(1); 
    }

    is >> NNODES;

    if (NNODES < 2) { cerr << "#nodes must be 2.." << endl; exit(1); }

    try {
        ReadEdges4kruskal(is);
        kruskal();
    }

    catch (char const* str)
    {
        cerr << "Exception: " << str << endl; exit(1);
    }
}