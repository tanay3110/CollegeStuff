# Data Structures & Algorithms — Complete Reference Notes

---
title: "Data Structures & Algorithms — Complete Reference Notes"
subtitle: "From Fundamentals to Advanced Topics, with Cybersecurity Applications"
author: "DSA Reference Guide (C++)"
date: \today
toc: true
toc-depth: 2
numbersections: true
geometry: margin=1in
fontsize: 10pt
colorlinks: true
linkcolor: blue
urlcolor: blue
---

\newpage

# How to Use This Document

This document is organized as a **linear learning path** from basics to advanced topics, followed by **quick-revision cheat sheets** at the end of each major section. Every data structure / algorithm follows the same template:

1. **Concept** — plain-English explanation
2. **Diagram** — ASCII visualization
3. **Pseudocode** — language-agnostic logic
4. **C++ Implementation** — ready-to-use code
5. **Complexity** — time & space
6. **Cybersecurity Angle** — where this concept shows up in security work
7. **Common Mistakes** — pitfalls to avoid

Use it three ways:
- **Exam prep** → read Concept + Diagram + Complexity boxes
- **Interview prep** → focus on Pseudocode + C++ + "Common Mistakes" + the cheat sheets
- **Competitive programming** → jump straight to C++ templates in each section

\newpage

# 1. Complexity Analysis (Big-O) — Foundation

## 1.1 Why It Matters
Every DS/algorithm choice is a trade-off between **time** (speed) and **space** (memory). Big-O describes how runtime/memory *grows* as input size `n` grows — it ignores constants and lower-order terms because we care about behavior at scale.

## 1.2 Growth Rates (Best to Worst)

| Notation | Name | Example | 1M input, rough steps |
|---|---|---|---|
| O(1) | Constant | Array index access | 1 |
| O(log n) | Logarithmic | Binary search | ~20 |
| O(n) | Linear | Single loop scan | 1,000,000 |
| O(n log n) | Linearithmic | Merge sort, quicksort avg | ~20,000,000 |
| O(n²) | Quadratic | Nested loops, bubble sort | 10¹² |
| O(n³) | Cubic | Triple nested loops, naive matrix mult | 10¹⁸ |
| O(2ⁿ) | Exponential | Recursive subsets, naive Fibonacci | astronomically large |
| O(n!) | Factorial | Brute-force permutations (TSP) | astronomically large |

```
Growth curve (qualitative):

runtime
  ^
  |                                   ___ O(n!)
  |                              ,--''  
  |                         ,--'' O(2^n)
  |                    ,-''
  |               ,-''      O(n^2)
  |           ,-''     __--
  |        ,-'    __--'     O(n log n)
  |     ,-'  __--'
  |  ,-'__--'                O(n)
  |-'__------------------    O(log n)
  |________________________  O(1)
  +------------------------------> n
```

## 1.3 Rules for Calculating Big-O

- **Drop constants**: O(2n) → O(n)
- **Drop non-dominant terms**: O(n² + n) → O(n²)
- **Different inputs get different variables**: two arrays of size `a` and `b` → O(a + b), not O(n)
- **Sequential blocks add**: loop1 O(n) + loop2 O(n) → O(n), not O(n²)
- **Nested blocks multiply**: loop inside loop, each O(n) → O(n²)

## 1.4 Best, Average, Worst Case

| Case | Meaning | Example (Quicksort) |
|---|---|---|
| Best | Most favorable input | O(n log n) — balanced partitions |
| Average | Typical/expected input | O(n log n) |
| Worst | Most unfavorable input | O(n²) — already sorted array, bad pivot |

**Interview tip**: Always state worst-case unless asked otherwise — interviewers assume worst-case by default.

## 1.5 Space Complexity
Counts **extra** memory used (not counting input itself), including:
- Auxiliary variables
- Recursion call stack (each recursive call frame counts!)
- Data structures created (hash maps, extra arrays)

**Recursion example**: `factorial(n)` uses O(n) space due to n stacked call frames, even though it does no extra array allocation.

## 1.6 Amortized Analysis
Some operations are occasionally expensive but cheap on average over a sequence of operations.
- **Example**: `std::vector::push_back` — occasionally O(n) when resizing (doubling capacity), but O(1) amortized because resizes become exponentially rare.

## 1.7 Cheat Sheet — Common Operation Complexities

| Data Structure | Access | Search | Insert | Delete |
|---|---|---|---|---|
| Array | O(1) | O(n) | O(n) | O(n) |
| Dynamic Array (vector) | O(1) | O(n) | O(1) amortized end / O(n) mid | O(n) |
| Singly Linked List | O(n) | O(n) | O(1) at head | O(1) at head |
| Doubly Linked List | O(n) | O(n) | O(1) w/ pointer | O(1) w/ pointer |
| Stack | O(n) | O(n) | O(1) | O(1) |
| Queue | O(n) | O(n) | O(1) | O(1) |
| Hash Table | N/A | O(1) avg / O(n) worst | O(1) avg | O(1) avg |
| BST (balanced) | O(log n) | O(log n) | O(log n) | O(log n) |
| BST (unbalanced) | O(n) | O(n) | O(n) | O(n) |
| Heap (binary) | O(1) top | O(n) | O(log n) | O(log n) |
| Trie | O(L) | O(L) | O(L) | O(L) — L = key length |

## Common Mistakes — Complexity Analysis
- Confusing **average case** with **worst case** (hash maps look O(1) but degrade to O(n) under collisions/bad hash functions).
- Forgetting that **string concatenation in a loop** is O(n²) in many languages (each concat copies).
- Ignoring **recursion stack space** when reporting space complexity.
- Assuming `vector::push_back` is always O(1) — it's amortized, not strictly O(1).
- Mixing up O(log n) bases — in Big-O, log base doesn't matter (log₂n and log₁₀n differ by a constant factor), but this only holds inside Big-O notation, not for actual runtime comparisons.
