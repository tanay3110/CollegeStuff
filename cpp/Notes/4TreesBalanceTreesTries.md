# 6. Trees

## 6.1 Binary Tree — Concept
A hierarchical structure where each node has at most two children (left, right).

```
              50
            /    \
          30      70
         /  \    /  \
       20   40  60   80
```

```cpp
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

## 6.2 Tree Traversals

| Traversal | Order | Use case |
|---|---|---|
| Preorder | Root → Left → Right | Copy/serialize a tree |
| Inorder | Left → Root → Right | Gives **sorted order** for a BST |
| Postorder | Left → Right → Root | Delete tree / evaluate expression trees |
| Level-order (BFS) | Level by level | Shortest path in unweighted tree, printing by levels |

```cpp
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void levelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```
**Complexity**: All traversals are O(n) time, O(h) space (h = height, due to recursion stack; O(n) for level-order due to queue).

## 6.3 Binary Search Tree (BST)
**Property**: left subtree < node < right subtree, for every node.

```cpp
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

bool search(TreeNode* root, int val) {
    if (!root) return false;
    if (root->val == val) return true;
    return val < root->val ? search(root->left, val) : search(root->right, val);
}
```
**Complexity**: O(log n) average (balanced), O(n) worst case (degenerates into a linked list — e.g., inserting sorted data).

**Cybersecurity Angle**: This worst-case degeneration is exactly what an **algorithmic complexity attack (DoS)** exploits — an attacker feeds sorted/crafted input to force a BST-backed service into O(n) behavior per operation, degrading performance. This is why production systems use **self-balancing trees** or randomized structures.

## 6.4 Self-Balancing Trees (AVL / Red-Black) — Concept Only
Guarantee O(log n) height by rebalancing (rotations) after insert/delete.

- **AVL Tree**: strictly balanced (height difference ≤ 1 between subtrees); more rotations, faster lookups.
- **Red-Black Tree**: loosely balanced (colored nodes with rules); fewer rotations, faster inserts — used in `std::map`/`std::set` internally.

```
Rotation example (Left-Left case → Right Rotation):

      z                y
     / \             /   \
    y   T4    ->     x     z
   / \                    / \
  x  T3                 T3  T4
```

| Structure | Balance Guarantee | Used In |
|---|---|---|
| AVL Tree | Strict (height diff ≤ 1) | Read-heavy databases |
| Red-Black Tree | Loose | `std::map`, `std::set`, Linux kernel scheduler |
| B-Tree / B+ Tree | Multi-way, disk-optimized | Databases, filesystems (indexes) |

## 6.5 Trie (Prefix Tree)
Stores strings character by character; shared prefixes share nodes.

```
Words: "cat", "car", "cart"

        root
         |
         c
         |
         a
        / \
       t   r
       |   |
     (end) t
           |
         (end - car)
           |
           t
           |
         (end - cart)
```

```cpp
struct TrieNode {
    TrieNode* children[26] = {};
    bool isEnd = false;
};

class Trie {
    TrieNode* root = new TrieNode();
public:
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i]) node->children[i] = new TrieNode();
            node = node->children[i];
        }
        node->isEnd = true;
    }
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i]) return false;
            node = node->children[i];
        }
        return node->isEnd;
    }
};
```
**Complexity**: O(L) per insert/search, where L = word length — independent of number of words stored.

**Cybersecurity Angle**: Tries power **IP routing tables (longest-prefix matching)**, **autocomplete/URL-blocklist filters in web proxies**, and **domain-name matching in DNS filtering / firewall rule sets** (e.g., matching `*.malicious.com` efficiently against millions of blocked domains).

## 6.6 Heaps / Priority Queues (Tree-Based)

**Concept**: A complete binary tree satisfying the heap property — **min-heap**: parent ≤ children; **max-heap**: parent ≥ children. Stored efficiently as an **array** (no pointers needed): for index `i`, children are at `2i+1`, `2i+2`, parent at `(i-1)/2`.

```
Max-Heap:              Array representation:
        90              [90, 70, 80, 20, 60, 40, 50]
       /  \
     70    80
    /  \   / \
   20  60 40 50
```

```cpp
priority_queue<int> maxHeap;              // O(log n) push/pop, O(1) top
priority_queue<int, vector<int>, greater<int>> minHeap;

maxHeap.push(50); maxHeap.push(90); maxHeap.push(20);
cout << maxHeap.top();  // 90
maxHeap.pop();           // O(log n) — re-heapify
```

**Manual heapify (for custom types / heap sort)**:
```cpp
void heapify(vector<int>& arr, int n, int i) { // max-heapify
    int largest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
```

**Complexity**: Build heap O(n), Insert/Extract O(log n), Peek O(1).

**Applications**: priority scheduling, Dijkstra's algorithm, k-largest/k-smallest elements, median maintenance (two-heap technique), event simulation.

**Cybersecurity Angle**: Priority queues drive **intrusion-detection alert triage** (highest-severity alerts processed first) and **network packet scheduling / QoS** in firewalls.

## Common Mistakes — Trees & Heaps
- Forgetting the **null check** at the top of every recursive tree function → segfault.
- Confusing **BST property** with "left child < parent < right child" only locally — the property must hold for the *entire* left/right subtree, not just immediate children (a common bug when validating a BST).
- Assuming a BST is always balanced — it's not, unless explicitly self-balancing.
- Using `priority_queue::top()` on an empty queue.
- Forgetting that `priority_queue` is **max-heap by default** in C++ (many assume min-heap).
- Trie: not marking `isEnd` correctly, causing false positives on prefix vs full-word search (e.g., "car" search wrongly succeeding when only "cart" was inserted).

\newpage