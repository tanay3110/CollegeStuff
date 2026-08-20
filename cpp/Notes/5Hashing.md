# 7. Hashing

## 7.1 Concept
A **hash function** maps a key (of any size) to a fixed-size index/bucket. A **hash table** uses this to give average O(1) insert/search/delete.

```
key "apple" --> hash() --> index 3

Bucket array:
[0] -> empty
[1] -> ("banana", 5)
[2] -> empty
[3] -> ("apple", 10) -> ("grape", 7)   <- collision chain
[4] -> empty
```

## 7.2 Collision Handling

| Method | How it works | Trade-off |
|---|---|---|
| Chaining | Each bucket holds a linked list of entries | Simple, degrades gracefully, extra memory for pointers |
| Open Addressing (Linear Probing) | On collision, check next slot | Cache-friendly, but clustering can occur |
| Open Addressing (Double Hashing) | Use a second hash function for probe step | Reduces clustering, more computation |

```cpp
#include <unordered_map>
#include <unordered_set>

unordered_map<string, int> freq;
freq["apple"]++;                 // O(1) avg
if (freq.count("apple")) { ... } // O(1) avg lookup
```

## 7.3 Designing a Good Hash Function
A good hash function should:
- Be **deterministic** (same input → same output)
- Have **uniform distribution** (minimize collisions)
- Be **fast to compute**
- **Avalanche effect** for cryptographic hashes (tiny input change → drastically different output)

```cpp
// Simple polynomial rolling hash (used in Rabin-Karp, string hashing)
long long hashString(const string& s, long long p = 31, long long m = 1e9 + 9) {
    long long hash_value = 0, p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
```

## 7.4 Cybersecurity Deep-Dive: Hashing Is Everywhere in Security

| Use Case | How Hashing Applies |
|---|---|
| **Password storage** | Never store plaintext — store `hash(password + salt)` using slow, purpose-built hashes (bcrypt, scrypt, Argon2), NOT fast general-purpose hashes like MD5/SHA-1 |
| **Data integrity** | SHA-256 checksums verify a downloaded file/firmware hasn't been tampered with |
| **Digital signatures** | Sign the *hash* of a message (fixed size), not the whole message, for efficiency |
| **HashDoS attack** | Attacker crafts many keys that all collide into the same bucket, degrading a hash table from O(1) to O(n) per op → DoS. Defense: randomized hash seeds (e.g., SipHash used in many languages' default hash maps) |
| **Rainbow tables** | Precomputed hash→password lookup tables to reverse unsalted hashes — defeated by per-user **salting** |
| **Blockchain / Merkle trees** | Hash trees let you verify a large dataset's integrity by checking one root hash |
| **File deduplication / malware fingerprinting** | Hash files to detect known-malicious binaries (hash blocklists) |

**Critical distinction**: A **hash table hash function** (speed-optimized, e.g., FNV, MurmurHash) is fundamentally different from a **cryptographic hash function** (SHA-256, designed to be one-way and collision-resistant). Never use `std::hash` for security purposes.

## 7.5 Complexity Summary

| Operation | Average | Worst Case |
|---|---|---|
| Insert | O(1) | O(n) |
| Search | O(1) | O(n) |
| Delete | O(1) | O(n) |

Worst case occurs when many keys collide (bad hash function, or adversarial input — see HashDoS above).

## Common Mistakes — Hashing
- Using a **cryptographically insecure** hash (MD5, SHA-1) for passwords — both are broken/fast, enabling brute force.
- Forgetting to **salt** passwords before hashing (identical passwords produce identical hashes without salt, enabling rainbow-table attacks).
- Relying on `unordered_map` ordering — it is **not guaranteed** and can change between runs/insertions.
- Modifying a key that's already used to place an object in a hash-based container — corrupts the internal bucket structure.
- Not handling hash collisions at all in a custom hash table implementation (assuming a "perfect" hash function that never collides).
- Iterating and erasing from `unordered_map` simultaneously without using the iterator returned by `erase()`.

\newpage