class Trie
{
private:

struct Node
{
    array<Node*, 26> children{};
    bool is_end{false};
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

static Node* DeleteKeyImpl(Node* cur, string_view sv)
{
    if (!cur) {
        return nullptr;
    }
    if (sv.empty()) {
        cur->is_end = false;
    } else {
        cur->children[sv[0]-'a'] = DeleteKeyImpl(cur->children[sv[0]-'a'], sv.substr(1));
    }
    // If the current node is the end of other words, Keep it
    if (cur->is_end) {
        return cur;
    }
    // If it's not the end and not assiociated with other nodes, delete it
    for (size_t i = 0; i < cur->children.size(); i++) {
        if (cur->children[i]) {
            return cur;
        }
    }
    delete cur;
    return nullptr;
}

public:
    Trie() : root_(new Node)
    {
    }

    ~Trie()
    {
        DeleteTrie(root_);
    }

    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;

    void insert(const string& word)
    {
        Node* cur = root_;
        for (char c : word) {
            if (!cur->children[c-'a']) {
                cur->children[c-'a'] = new Node;
            }
            cur = cur->children[c-'a'];
        }
        cur->is_end = true;
    }

    bool search(const string& word) const
    {
        Node* cur = root_;
        for (char c : word) {
            if (!cur->children[c-'a']) {
                return false;
            }
            cur = cur->children[c-'a'];
        }
        return cur->is_end;
    }

    bool startsWith(const string& prefix) const
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

    void DeleteKey(const string& word)
    {
        root_ = DeleteKeyImpl(root_, word);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */