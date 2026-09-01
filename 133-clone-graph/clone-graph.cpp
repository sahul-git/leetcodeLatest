class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        queue<Node*> q;
        unordered_map<Node*, Node*> mp;

        Node* newNode = new Node(node->val);

        mp[node] = newNode;
        q.push(node);

        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();

            for(Node* nbrNode : temp->neighbors) {

                // Create clone if it doesn't exist
                if(mp.find(nbrNode) == mp.end()) {
                    Node* newNeigh = new Node(nbrNode->val);

                    mp[nbrNode] = newNeigh;
                    q.push(nbrNode);
                }

                // Connect current clone to neighbor clone
                mp[temp]->neighbors.push_back(mp[nbrNode]);
            }
        }

        return newNode;
    }
};