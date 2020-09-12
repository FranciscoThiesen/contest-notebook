// MO's Algorithm with Hilbert order (usually faster!)
// Anser q range queries in time O(n * sqrt(q))
inline int64_t hilbert_order(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = hilbert_order(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct query {
    int l, r, i;
    int64_t ord;
    query(int l, int r, int i) : l(l), r(r), i(i) {
        ord = hilbert_order(l, r, 19, 0);
    }
};

inline bool operator<(const query& a, const query& b) {
    return a.ord < b.ord;
}
