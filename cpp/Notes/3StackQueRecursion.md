# 4. Stacks & Queues

## 4.1 Stack — LIFO (Last In, First Out)

```
push(4)         pop() -> 4
   |                |
   v                v
 [ 4 ]  <- top     [   ]
 [ 3 ]              [ 3 ]  <- top
 [ 2 ]              [ 2 ]
 [ 1 ]              [ 1 ]
```

```cpp
#include <stack>
stack<int> st;
st.push(10);
st.push(20);
st.top();   // 20
st.pop();   // removes 20
st.empty(); // false
```

**Applications**: function call stack, undo/redo, expression evaluation (infix→postfix), balanced-parentheses checking, DFS.

**Balanced Parentheses (classic)**:
```cpp
bool isBalanced(string s) {
    stack<char> st;
    unordered_map<char, char> pair = {{')','('}, {']','['}, {'}','{'}};
    for (char c : s) {
        if (c=='('||c=='['||c=='{') st.push(c);
        else if (pair.count(c)) {
            if (st.empty() || st.top() != pair[c]) return false;
            st.pop();
        }
    }
    return st.empty();
}
```

**Cybersecurity Angle**: The **call stack** itself is a security-critical structure — stack-based buffer overflows overwrite the **return address** stored on the call stack to hijack control flow (classic exploit technique). Understanding stack frame layout is foundational to binary exploitation / reverse engineering.

## 4.2 Queue — FIFO (First In, First Out)

```
enqueue(4)                  dequeue() -> 1
front                              front
  v                                  v
[1][2][3]  <- enqueue here      [2][3][4]
```

```cpp
#include <queue>
queue<int> q;
q.push(10); q.push(20);
q.front();  // 10
q.pop();    // removes 10
```

**Circular Queue / Deque**: `std::deque` supports O(1) push/pop at both ends — used for sliding window maximum problems.

**Priority Queue** (binary heap under the hood):
```cpp
#include <queue>
priority_queue<int> maxHeap;                       // max-heap by default
priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap
```

**Applications**: BFS, task scheduling, print queues, Dijkstra's algorithm (priority queue), rate limiting / packet buffering in network security appliances.

## Common Mistakes — Stacks & Queues
- Calling `top()`/`front()` on an empty container → **undefined behavior**, always check `empty()` first.
- Using a `vector` as a queue with `erase(begin())` — that's O(n) per dequeue; use `std::queue` or `std::deque` instead.
- Confusing `stack::top()` with `queue::front()` — different semantics.
- Forgetting stack overflow risk: **unbounded recursion mimics unbounded stack growth** — same root cause.

\newpage

# 5. Recursion & Backtracking

## 5.1 Recursion — Concept
A function that calls itself on a smaller subproblem, with a **base case** to stop. Every recursive call adds a frame to the call stack.

```
factorial(4)
 -> 4 * factorial(3)
      -> 3 * factorial(2)
           -> 2 * factorial(1)
                -> 1 * factorial(0)
                     -> return 1   (base case)
                -> returns 1
           -> returns 2
      -> returns 6
 -> returns 24
```

```cpp
int factorial(int n) {
    if (n <= 1) return 1;         // base case
    return n * factorial(n - 1);  // recursive case
}
```

**Complexity**: Time depends on recursion tree size; Space = O(depth) for the call stack.

## 5.2 Backtracking
A refinement of recursion: **try → recurse → undo (backtrack)** if a choice doesn't lead to a solution. Used for constraint-satisfaction problems (permutations, subsets, N-Queens, Sudoku).

**Template (pseudocode)**:
```
function backtrack(state):
    if state is a complete solution:
        record(state); return
    for choice in possible_choices(state):
        if choice is valid:
            make(choice)          # try
            backtrack(next state) # recurse
            undo(choice)          # backtrack
```

### Example: Generate All Subsets — O(2ⁿ)
```cpp
void subsets(vector<int>& nums, int idx, vector<int>& cur, vector<vector<int>>& res) {
    if (idx == nums.size()) { res.push_back(cur); return; }
    // choice 1: exclude nums[idx]
    subsets(nums, idx + 1, cur, res);
    // choice 2: include nums[idx]
    cur.push_back(nums[idx]);
    subsets(nums, idx + 1, cur, res);
    cur.pop_back();   // backtrack
}
```

### Example: N-Queens — classic backtracking
```cpp
bool isSafe(vector<int>& board, int row, int col) {
    for (int r = 0; r < row; r++) {
        int c = board[r];
        if (c == col || abs(c - col) == abs(r - row)) return false;
    }
    return true;
}

void solveNQueens(vector<int>& board, int row, int n, int& count) {
    if (row == n) { count++; return; }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;                      // place
            solveNQueens(board, row + 1, n, count); // recurse
            // no explicit undo needed — board[row] overwritten next iteration
        }
    }
}
```

**Cybersecurity Angle**: Backtracking underlies **brute-force password/key search with pruning**, **constraint solving in SAT-based vulnerability analysis**, and **maze/graph traversal in penetration-testing path discovery** (e.g., finding an attack path through a permission graph).

## 5.3 Recursion vs Iteration
| Aspect | Recursion | Iteration |
|---|---|---|
| Readability | Often cleaner for tree/graph problems | Better for simple loops |
| Space | O(depth) stack frames | O(1) typically |
| Risk | Stack overflow on deep recursion | None (usually) |
| Speed | Slight overhead per call | Generally faster |

**Tail recursion**: some compilers optimize recursive calls that are the *last* operation into a loop (tail-call optimization) — C++ compilers do this inconsistently, so don't rely on it for deep recursion.

## Common Mistakes — Recursion & Backtracking
- **Missing or wrong base case** → infinite recursion → stack overflow.
- Forgetting to **backtrack (undo)** a change (e.g., not popping from `cur` vector) → corrupted state across branches.
- Passing large objects **by value** instead of by reference in recursive calls → hidden O(n) copy per call, blowing up complexity.
- Not memoizing overlapping subproblems (turns exponential recursion into exponential blow-up — see Dynamic Programming section).
- Recomputing the same recursive call multiple times without caching (classic naive Fibonacci = O(2ⁿ) instead of O(n)).

\newpage