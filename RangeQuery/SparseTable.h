#include <vector>
using namespace std;
// Based on: https://github.com/the-tourist/algo/blob/master/data/sparsetable.cpp
/* 
Usage:
   auto func = [&] (int i, int j) { return min(i, j); }
   SparseTable<int, decltype(fun)> st(arr, func)
or:
   SparseTable<int> st(a, [&] (int i, int j) { return min(i, j); });
*/
// Sparse-Table for a static array
// Complexity: O(n log n) for initialization and O(1) for get
// Assumption: func must be associative
template<typename T, class F = function<T(const T&, const T&)> >
struct SparseTable {
    int n;
    vector< vector<T> > mat;
    F func;

    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for(int j = 1; j < max_log; ++j) {
            mat[j].resize(n - (1 << j) + 1);
            for(int i = 0; i <= n - (1 << j); ++i) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

