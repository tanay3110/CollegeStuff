# 9. Sorting Algorithms

## 9.1 Comparison Cheat Sheet

| Algorithm | Best | Average | Worst | Space | Stable? | In-place? |
|---|---|---|---|---|---|---|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No | Yes |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes | No |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No | Yes |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | No | Yes |
| Counting Sort | O(n+k) | O(n+k) | O(n+k) | O(k) | Yes | No |
| Radix Sort | O(d(n+k)) | O(d(n+k)) | O(d(n+k)) | O(n+k) | Yes | No |

*Stable = equal elements keep their relative order. Matters when sorting objects by one key while preserving order by another.*

## 9.2 Merge Sort — Divide & Conquer, O(n log n) guaranteed
```cpp
void merge(vector<int>& a, int l, int m, int r) {
    vector<int> left(a.begin()+l, a.begin()+m+1), right(a.begin()+m+1, a.begin()+r+1);
    int i=0, j=0, k=l;
    while (i < left.size() && j < right.size())
        a[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i < left.size()) a[k++] = left[i++];
    while (j < right.size()) a[k++] = right[j++];
}
void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    merge(a, l, m, r);
}
```
```
Divide:  [5,2,4,1] -> [5,2] [4,1] -> [5][2] [4][1]
Merge:   [5][2] -> [2,5]   [4][1] -> [1,4]
         [2,5] + [1,4] -> [1,2,4,5]
```

## 9.3 Quick Sort — Divide & Conquer, in-place
```cpp
int partition(vector<int>& a, int low, int high) {
    int pivot = a[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (a[j] < pivot) swap(a[++i], a[j]);
    swap(a[i+1], a[high]);
    return i + 1;
}
void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}
```
**Worst case O(n²)** happens with a bad pivot choice (e.g., always picking the last element on already-sorted data). **Mitigation**: random pivot or median-of-three.

**Cybersecurity note**: predictable pivot selection in quicksort has historically been exploited for **algorithmic complexity DoS attacks** against services that sort user-supplied data — always randomize the pivot in adversarial contexts.

## 9.4 Heap Sort — O(n log n) guaranteed, O(1) space
```cpp
void heapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; i--) heapify(a, n, i); // build max-heap
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);       // move max to end
        heapify(a, i, 0);       // re-heapify reduced heap
    }
}
```

## 9.5 Non-Comparison Sorts (linear time under constraints)
- **Counting Sort**: works when values are integers in a small known range `[0, k]`. Count occurrences, then place directly.
- **Radix Sort**: sorts digit-by-digit (least significant first) using counting sort as subroutine — good for fixed-width integers/strings.

**When to use**: only when the constraint (small integer range, fixed digit-width keys) holds — otherwise comparison sort is the general-purpose choice.

## 9.6 Choosing the Right Sort — Decision Guide
- Need **stability** + guaranteed O(n log n) + have extra memory → **Merge Sort**
- Need **in-place** + average-case speed is priority → **Quick Sort** (with randomized pivot)
- Need **guaranteed O(n log n)** + **O(1) space**, don't care about stability → **Heap Sort**
- Small (n < ~20) or **nearly sorted** data → **Insertion Sort** (fast in practice, simple)
- Integer keys in small range → **Counting/Radix Sort**

## Common Mistakes — Sorting
- Assuming `std::sort` is stable — it is **not** (use `std::stable_sort` if order-preservation matters).
- Quick sort worst case from naive pivot choice on sorted/reverse-sorted input.
- Off-by-one in partition/merge boundary indices (`m` vs `m+1`, `<=` vs `<`).
- Forgetting merge sort needs O(n) auxiliary space — not truly in-place.
- Comparing floating-point values for sorting without considering precision/epsilon issues.

\newpage

# 10. Searching Algorithms

## 10.1 Linear Search — O(n)
```cpp
int linearSearch(vector<int>& a, int target) {
    for (int i = 0; i < a.size(); i++) if (a[i] == target) return i;
    return -1;
}
```

## 10.2 Binary Search — O(log n), requires sorted array
```cpp
int binarySearch(vector<int>& a, int target) {
    int lo = 0, hi = a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;   // avoids overflow vs (lo+hi)/2
        if (a[mid] == target) return mid;
        else if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```
```
Search 42 in [1,5,12,20,42,55,70]
lo=0 hi=6 mid=3 -> a[3]=20 < 42 -> lo=4
lo=4 hi=6 mid=5 -> a[5]=55 > 42 -> hi=4
lo=4 hi=4 mid=4 -> a[4]=42 == 42 -> FOUND at index 4
```

### Binary Search Variants (interview favorites)
- **Lower bound / upper bound** (first/last occurrence, insertion point) — `std::lower_bound`, `std::upper_bound`
- **Binary search on answer**: applies when the search space is monotonic but not a literal array — e.g., "find minimum capacity such that condition holds" (binary search over the *answer*, checking feasibility each time).

```cpp
// Binary search on answer template
int lo = minPossible, hi = maxPossible;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (feasible(mid)) hi = mid;      // mid works, try smaller
    else lo = mid + 1;
}
// lo is the answer
```

**Cybersecurity use**: binary search accelerates lookups in **sorted IP blocklists**, **certificate revocation list lookups**, and **log timestamp range queries** during incident investigation.

## Common Mistakes — Searching
- Running binary search on an **unsorted** array — silently gives wrong results.
- Integer overflow from `(lo + hi) / 2` on large arrays — use `lo + (hi - lo) / 2`.
- Infinite loop from incorrect boundary updates (`lo = mid` instead of `lo = mid + 1` when not excluding `mid`).
- Off-by-one in `<=` vs `<` for the while condition, causing missed elements or infinite loops.

\newpage