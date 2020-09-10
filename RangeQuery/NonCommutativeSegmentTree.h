#include <vector>

using namespace std;

// Based on: https://codeforces.com/blog/entry/18051
/*
Usage:
    auto S = SegmentTree<T>(size, identity);
    S.query(a, b)...
*/
// Iterative Segment Tree (for non-commutative combine functions)
// Complexity: build = O(n), query/modify = O(log(n))
// Assumptions: Node combination (*) must be associative (a * b) * c = a * (b * c)
template <typename T> 
struct seg {
    int N;
    vector<T> tree;
    T identity;

    seg(int n, T id) : N(n), identity(id) { tree.assign(2 * N, id); }
    
    void build() {
        for(int idx = N - 1; idx > 0; --idx) {
            tree[idx] = tree[idx * 2] * tree[(idx * 2) | 1];
        }
    }

    void modify(int p, T val) {
        tree[p += N] = val;
        while(p > 1) {
            tree[p / 2] = tree[p] * tree[p ^ 1];
            p /= 2; 
        }
    }
    
    // Query on semi-open range [l, r)
    T query(int l, int r) {
        T res_r = identity, res_l = identity;
        for(l += N, r += N; l < r; l /= 2, r /= 2) {
            if(l & 1) res_l = res_l * tree[l++];
            if(r & 1) res_r = tree[--r] * res_r;
        }
        return res_l * res_r;
    }
};

struct node {
    // Define struct!
    node operator* (const node& rhs) const {
        // Teach segment tree how to combine two nodes
    }
};

