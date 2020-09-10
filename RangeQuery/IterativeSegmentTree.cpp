#include <vector>

using namespace std;

// Baseado em: https://codeforces.com/blog/entry/18051

// Iterative Segment Tree
// Complexity: build = O(n), query/modify = O(log(n))
// Assumptions: Node combination (*) must be associative (a * b) * c = a * (b * c) and commutative a * b = b * a
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
    
    T query(int l, int r) {
        T res = identity;
        for(l += N, r += N; l < r; l /= 2, r /= 2) {
            if(l & 1) res = res * tree[l++];
            if(r & 1) res = res * tree[--r];
        }
        return res;
    }
};
