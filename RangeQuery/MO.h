// MO's Algorithm (reference: https://codeforces.com/blog/entry/61203, https://blog.anudeep2011.com/mos-algorithm/)
// Answer q range queries in O(n * sqrt(q))
/*
Usage:
    Set block_size to n / sqrt(m) + 1
    Implement add and remove functions
    Sort queries before running!!
*/

int block;
struct query {
    int l, r, id;
    query(int l, int r, int id) : l(l), r(r), id(id) {}
    inline pair<int, int> to_pair() const {
        return make_pair(l / block, ((l / block) & 1) ? -r : +r);
    }
};

inline bool operator<(const query& a, const query& b) {
    return a.to_pair() < b.to_pair();
}
