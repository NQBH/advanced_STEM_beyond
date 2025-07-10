#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

struct Segment {
    Point p1, p2;
    Segment(Point a, Point b) : p1(a), p2(b) {}
};

// Check if three points are collinear
bool collinear(Point a, Point b, Point c) {
    double cross = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return abs(cross) < EPS;
}

// Check if two segments lie on the same infinite line
bool onSameLine(Segment s1, Segment s2) {
    return collinear(s1.p1, s1.p2, s2.p1) && collinear(s1.p1, s1.p2, s2.p2);
}

// Check if two segments overlap (lie on the same line and have non-zero intersection)
bool overlap(Segment s1, Segment s2) {
    if (!onSameLine(s1, s2)) return false;

    // Project onto the axis with larger span to avoid precision issues
    double dx = s1.p2.x - s1.p1.x;
    double dy = s1.p2.y - s1.p1.y;

    if (abs(dx) >= abs(dy)) {
        // Project onto X-axis
        double a1 = min(s1.p1.x, s1.p2.x);
        double b1 = max(s1.p1.x, s1.p2.x);
        double a2 = min(s2.p1.x, s2.p2.x);
        double b2 = max(s2.p1.x, s2.p2.x);

        // Overlap exists if segments intersect (including touching at endpoints)
        return max(a1, a2) <= min(b1, b2) + EPS;
    } else {
        // Project onto Y-axis
        double a1 = min(s1.p1.y, s1.p2.y);
        double b1 = max(s1.p1.y, s1.p2.y);
        double a2 = min(s2.p1.y, s2.p2.y);
        double b2 = max(s2.p1.y, s2.p2.y);

        return max(a1, a2) <= min(b1, b2) + EPS;
    }
}

// Union-Find to group overlapping segments
class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
    }

    int countComponents() {
        set<int> roots;
        for (int i = 0; i < parent.size(); i++) {
            roots.insert(find(i));
        }
        return roots.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        vector<Segment> segments;

        for (int i = 0; i < n; i++) {
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            segments.push_back(Segment(Point(x1, y1), Point(x2, y2)));
        }

        UnionFind uf(n);

        // Find all pairs of overlapping segments
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (overlap(segments[i], segments[j])) {
                    uf.unite(i, j);
                }
            }
        }

        cout << uf.countComponents() << "\n";
    }