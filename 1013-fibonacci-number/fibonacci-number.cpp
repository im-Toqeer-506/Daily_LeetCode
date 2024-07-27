class Solution {
public:
    int fib(int n) {
         if (n <= 1) return n; 
       vector<int> tabulor(n + 1);
        tabulor[0] = 0;  
        tabulor[1] = 1;  
        for (int i = 2; i <= n; i++) 
        {  
            tabulor[i] = tabulor[i-1] + tabulor[i-2];  
        }
       return tabulor[n]; 

    }
};