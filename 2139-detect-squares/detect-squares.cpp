
class DetectSquares {
public:
    map<pair<int, int>, int> pc;
    DetectSquares() {
    }
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        pc[{x, y}]++;
    }
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int sc = 0;
        for (auto& num : pc) {
            int px = num.first.first;
            int py = num.first.second;
            if (px == x || py == y) continue;
            if (abs(px - x) != abs(py - y)) continue;
            if (pc.count({x, py}) && pc.count({px, y})) {
                sc += num.second * pc[{x, py}] * pc[{px, y}];
            }
        }
        return sc;
    }
};


/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */