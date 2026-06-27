class Trie
{
private:

struct Node
{
    array<Node*, 26> children{};
    bool value{false};
};

Node* root_{};

// Precondition: cur is not nullptr
static void DeleteTrie(Node* cur)
{
    for (size_t i = 0; i < cur->children.size(); i++) {
        if (cur->children[i]) {
            DeleteTrie(cur->children[i]);
        }
    }
    delete cur;
}

public:
    Trie()
    {
        root_ = new Node;
    }

    ~Trie()
    {
        DeleteTrie(root_);
    }

    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;

    void insert(string word)
    {
        Node* cur = root_;
        for (char c : word) {
            if (!cur->children[c-'a']) {
                cur->children[c-'a'] = new Node;
            }
            cur = cur->children[c-'a'];
        }
        cur->value = true;
    }

    bool search(string word)
    {
        Node* cur = root_;
        for (char c : word) {
            if (!cur->children[c-'a']) {
                return false;
            }
            cur = cur->children[c-'a'];
        }
        return cur->value;
    }

    bool startsWith(string prefix)
    {
        Node* cur = root_;
        for (char c : prefix) {
            if (!cur->children[c-'a']) {
                return false;
            }
            cur = cur->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */