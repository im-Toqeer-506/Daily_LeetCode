class Node {
public:
    Node* links[26]; 
    bool isEnd;      
    
    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        isEnd = false;
    }
    
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    void setEnd() {
        isEnd = true;
    }
    
    bool isEndNode() {
        return isEnd;
    }
};

class Trie{
private:
    Node* root;

public:
   Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEndNode();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
