# 2. Arrays & Strings

## 2.1 Arrays

**Concept**: Contiguous block of memory holding elements of the same type, accessed via an index. Because memory is contiguous, address of element `i` = `base_address + i * element_size` → O(1) access.

```
Index:   0    1    2    3    4
       +----+----+----+----+----+
Array: | 10 | 25 | 7  | 42 | 3  |
       +----+----+----+----+----+
Addr:  100  104  108  112  116   (4-byte ints)
```

**C++ Implementation (static + dynamic)**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int staticArr[5] = {10, 25, 7, 42, 3};      // fixed size, stack
    vector<int> dynArr = {10, 25, 7, 42, 3};    // resizable, heap-backed

    dynArr.push_back(99);        // O(1) amortized
    dynArr.insert(dynArr.begin() + 1, 55); // O(n) — shifts elements
    dynArr.erase(dynArr.begin());          // O(n) — shifts elements

    for (int x : dynArr) cout << x << " ";
}
```

**Complexity**: Access O(1), Search O(n) unsorted / O(log n) sorted (binary search), Insert/Delete O(n) (worst case, due to shifting).

**Cybersecurity Angle**: Buffer overflows exploit the fact that arrays have no automatic bounds checking in C/C++ — writing past `arr[size-1]` corrupts adjacent memory (stack canaries, ASLR, and bounds-checked containers like `std::vector::at()` are defenses).

### Key Array Techniques (Interview Staples)

**Two Pointers** — O(n) instead of O(n²) for sorted-array problems:
```cpp
bool hasPairWithSum(vector<int>& arr, int target) { // arr sorted
    int l = 0, r = arr.size() - 1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == target) return true;
        else if (sum < target) l++;
        else r--;
    }
    return false;
}
```

**Sliding Window** — O(n) for subarray/substring problems:
```cpp
int maxSumSubarraySizeK(vector<int>& arr, int k) {
    int windowSum = 0, maxSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        windowSum += arr[i];
        if (i >= k - 1) {
            maxSum = max(maxSum, windowSum);
            windowSum -= arr[i - k + 1];
        }
    }
    return maxSum;
}
```

**Kadane's Algorithm** (max subarray sum) — O(n):
```cpp
int maxSubArray(vector<int>& nums) {
    int maxSoFar = nums[0], curMax = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        curMax = max(nums[i], curMax + nums[i]);
        maxSoFar = max(maxSoFar, curMax);
    }
    return maxSoFar;
}
```

**Prefix Sum** — O(1) range-sum queries after O(n) preprocessing:
```cpp
vector<int> prefix(arr.size() + 1, 0);
for (int i = 0; i < arr.size(); i++) prefix[i+1] = prefix[i] + arr[i];
// sum(l, r) inclusive = prefix[r+1] - prefix[l]
```

## 2.2 Strings

**Concept**: Array of characters. In C++, `std::string` manages dynamic resizing automatically (similar to vector).

**Common Operations**
```cpp
string s = "hello world";
s.substr(0, 5);        // "hello" — O(n)
s.find("world");       // returns index — O(n*m) naive
reverse(s.begin(), s.end()); // O(n)
s += "!";               // amortized O(1)
```

**Cybersecurity Angle**: String parsing bugs are the root of injection attacks (SQL injection, XSS, command injection). Off-by-one errors in string handling (`strcpy`, `gets`) are classic buffer-overflow vectors — this is why `strncpy`/bounds-checked APIs and input sanitization matter.

### Pattern Matching: KMP Algorithm (O(n+m))
Naive substring search is O(n·m). KMP precomputes a "failure function" so the pattern never re-scans matched characters.

```cpp
vector<int> buildLPS(string pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}

vector<int> KMPSearch(string txt, string pat) {
    vector<int> lps = buildLPS(pat), result;
    int i = 0, j = 0;
    while (i < txt.size()) {
        if (txt[i] == pat[j]) { i++; j++; }
        if (j == pat.size()) { result.push_back(i - j); j = lps[j - 1]; }
        else if (i < txt.size() && txt[i] != pat[j]) {
            if (j) j = lps[j - 1]; else i++;
        }
    }
    return result;
}
```
**Cybersecurity use**: signature-based IDS/antivirus engines use KMP/Aho-Corasick-style matching to scan network packets or files for known malware byte patterns.

### Rabin-Karp (Rolling Hash) — O(n+m) average
Uses hashing to compare substrings in O(1) after O(m) preprocessing — same rolling-hash idea used in **deduplication** and **plagiarism detection** tools.

## Common Mistakes — Arrays & Strings
- Off-by-one errors in loop bounds (`<=` vs `<`) — a classic source of buffer overflows.
- Modifying a `vector` while iterating over it with a range-based `for` (invalidates iterators).
- Using `==` to compare C-style strings (`char*`) instead of `strcmp`.
- Not checking for empty array/string before accessing `arr[0]`.
- Assuming `string::find` returns `-1` on failure — it actually returns `string::npos` (a huge unsigned value); comparing to `-1` silently works due to implicit conversion but is bad practice — compare to `string::npos` explicitly.
- Quadratic string building: repeated `s = s + c` in a loop instead of `s += c` or using a `stringstream`/reserving capacity.

\newpage

# 3. Linked Lists

**Concept**: A sequence of nodes where each node holds data + a pointer to the next (and previous, for doubly linked). No contiguous memory requirement → O(1) insertion/deletion when you already have the pointer, but O(n) access.

```
Singly:  [10|•]->[25|•]->[7|•]->[42|NULL]

Doubly:  NULL<-[•|10|•]<->[•|25|•]<->[•|7|NULL]
```

## 3.1 Singly Linked List — C++ Implementation
```cpp
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head = nullptr;

    void insertFront(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    void deleteValue(int val) {
        if (!head) return;
        if (head->data == val) { Node* tmp = head; head = head->next; delete tmp; return; }
        Node* cur = head;
        while (cur->next && cur->next->data != val) cur = cur->next;
        if (cur->next) { Node* tmp = cur->next; cur->next = tmp->next; delete tmp; }
    }

    void print() {
        for (Node* cur = head; cur; cur = cur->next) cout << cur->data << " -> ";
        cout << "NULL\n";
    }
};
```

## 3.2 Reverse a Linked List (classic interview Q) — O(n) time, O(1) space
```cpp
Node* reverse(Node* head) {
    Node* prev = nullptr;
    while (head) {
        Node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
```

## 3.3 Detect Cycle — Floyd's Tortoise & Hare — O(n) time, O(1) space
```cpp
bool hasCycle(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```
**Cybersecurity angle**: Cycle detection generalizes to detecting **infinite loops / circular references** in malware control-flow graphs and to detecting **cycles in permission-delegation graphs** (privilege escalation chains).

## Common Mistakes — Linked Lists
- **Memory leaks**: forgetting `delete` when removing nodes (C++ doesn't garbage-collect).
- **Dangling pointers**: using a node after it's deleted.
- Losing the reference to `head` while traversing (always traverse with a separate `cur` pointer).
- Off-by-one when handling the last node (`cur->next` vs `cur->next->next` null checks).
- Forgetting to update `prev`/`next` pointers on **both sides** when deleting from a doubly linked list.
