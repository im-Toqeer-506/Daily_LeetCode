class Solution {
public:
    int fibo(int n, unordered_map<int, int>& map) {
        map[0] = 0;
        map[1] = 1;
        map[2] = 1;
        //base case 
        if (map.find(n) != map.end())
            return map[n];

        for (int i = 3; i <= n; i++) {
            map[n] = fibo(i - 1, map) + fibo(i - 2, map) + fibo(i - 3, map);
        }

        return map[n];
    }
    int tribonacci(int n) {
        unordered_map<int, int> map;
        return fibo(n, map);
    }
};
// 0,1,1,2,4,7,13....