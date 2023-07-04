class Solution {
     // size variable to store the size of the island during dfs
    private int size = 0;
    
    // function to find the maximum area of an island in the given grid
    public int maxAreaOfIsland(int[][] grid) {
        // variable to store the maximum area of an island encountered so far
        int result = 0;
        
        // loop through each element in the grid
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                // if current element is 1, call dfs to explore the island
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                }
                
                // if the size of the current island is greater than the result, update result
                if (size > result) {
                    result = size;
                }
                
                // reset the size for the next iteration
                size = 0;
            }
        }
        
        // return the maximum area of an island
        return result;
    }

    // function to perform depth-first search to explore the island
    public void dfs(int[][] grid, int y, int x) {
        // if current element is 1, mark it as visited and increment the size variable
        if (grid[y][x] == 1) {
            grid[y][x] = 0;
            size += 1;
            
            // recursively call dfs on neighboring elements that are also 1's in the grid
            if (y >= 1) {
                dfs(grid, y - 1, x);
            }
            if (x >= 1) {
                dfs(grid, y, x - 1);
            }
            if (x + 1 < grid[0].length) {
                dfs(grid, y, x + 1);
            }
            if (y + 1 < grid.length) {
                dfs(grid, y + 1, x);
            }
        }
    }
}