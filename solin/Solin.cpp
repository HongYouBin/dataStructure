#include "mstree.h"

priority_queue< Edge, vector<Edge>, Compare >* PQ;

// �ʿ��Լ��� ���� �� �����Ͻÿ�
void MovePQ(int v1, int v2){
    Edge e;
    priority_queue< Edge, vector<Edge>, Compare > tmp;
    tmp = PQ[v2];
    
    while (tmp.empty() == false) {
        e = tmp.top();
        PQ[v1].push(e);
        tmp.pop();
        
    }
    PQ[v2] = PQ[v1];
}

void ReadEdges4sollin(istream& is) {

    //�� ��(tree) ���� ����� �������� minheap�� �ʿ���. 
    // NNODES���� minheap�� ���� �ִ� PQ �迭�� �����Ͻÿ�.  
    PQ = new priority_queue< Edge, vector<Edge>, Compare >[NNODES];
    
    Edge e;

    while (GetEdge(is, e)) {
        PQ[e.v1].push(e);
        PQ[e.v2].push(e);
    }
}

void sollin() {
    Sets sets(NNODES);
    int nedges = 0;
    Edge e;
    while (PQ[0].empty()==false) {
        while (nedges < NNODES - 1) {
            e = PQ[nedges].top();
            
            PQ[nedges].pop();
            
            int v1root1 = sets.Find(e.v1);
            int v2root2 = sets.Find(e.v2);

            if (v1root1 != v2root2) {
                sets.WeightedUnion(v1root1, v2root2);
                nedges++;
                cout << e;
                MovePQ(e.v1, e.v2);
            }
            
            else {
                
                 
                
                
                nedges++;
            } 
            
        }
        nedges = 0;
    }
}

int main(int argc, char* argv[]) {
    //���� �Է� �κ��� kruskal���� �����ϰ�
    //�߰� 

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
        ReadEdges4sollin(is);
        sollin();
    }
    catch (char const* str)
    {
        cerr << "Exception: " << str << endl; exit(1);
    }
}