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
    //hash maps
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        queue<Node*> q;

        Node* copy = new Node(node->val);
        m[node] = copy; //link original node to copy

        q.push(node);

        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (int i = 0; i < curr->neighbors.size(); i++) {
                //check if the neighbor exists in the map, create new copy if not
                Node* neighbor = curr->neighbors[i];
                if (m.find(neighbor) == m.end()) {
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                //push neighbor to copies 
                m[curr]->neighbors.push_back(m[neighbor]);
            }
        }//while loop

        return copy; //have to return the first copied node 
    }

private:
    map<Node*,Node*> m;

};