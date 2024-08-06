class Solution {
public:
    int provide(vector<vector<int>>& grid,int row,int col,unordered_set<string>&memo){
        if( row < 0 || row >= grid.size()|| col < 0 || col >= grid[0].size() || grid[row][col] ==0 ) return 0;
        //to keep track of the visited that cell
        string pos=to_string(row) + " : "+to_string(col);
        if(memo.count(pos))return 0;
        memo.insert(pos);

        int size=1;//this is equal to 1 because the this counts the current cell 
        size+=provide(grid,row+1,col,memo);//left
        size+=provide(grid,row-1,col,memo);//right
        size+=provide(grid,row,col+1,memo);//up
        size+=provide(grid,row,col-1,memo);//down
        return size;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        unordered_set<string>memo;
        int maxarea=0;
        for(int i=0;i<m;i++)
        {
        for(int j=0;j<n;j++)
        {
            int area=provide(grid,i,j,memo);
            maxarea=max(area,maxarea);
        }
        }
        return maxarea;
    }
};