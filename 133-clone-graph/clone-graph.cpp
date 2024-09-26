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
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> map;
        queue<Node*> queue;
        queue.push(node);
        map[node] = new Node(node->val, std::vector<Node*>());
        while (!queue.empty()) {
            Node* current = queue.front();
            queue.pop();
            for (Node* neighbor : current->neighbors) {
                if (neighbor == nullptr) continue;
                if (map.find(neighbor) == map.end()) {
                    map[neighbor] = new Node(neighbor->val, vector<Node*>());
                    queue.push(neighbor);
                }
                map[current]->neighbors.push_back(map[neighbor]);
            }
        }
        return map[node];
    }
};
