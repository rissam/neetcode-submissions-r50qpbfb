/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> mymap;
    queue<Node*> q;
public:
    Node* cloneGraph(Node* node) {
        Node *clonedNode, *origNode, *clonedNbr;
        if(node == nullptr) return nullptr;
        mymap[node] = new Node(node->val);
        q.push(node);
        while(q.size()) {
            origNode = q.front();
            clonedNode = mymap[origNode]; 
            q.pop();
            for(auto &nbr: origNode->neighbors) {
                clonedNbr = mymap[nbr];
                if(clonedNbr == nullptr) {
                    clonedNbr = new Node(nbr->val);
                    mymap[nbr] = clonedNbr;
                    q.push(nbr);
                }
                clonedNode->neighbors.push_back(clonedNbr);
            }
        }
        return mymap[node];
    }
};
