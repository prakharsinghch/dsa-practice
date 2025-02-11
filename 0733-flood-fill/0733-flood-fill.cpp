class Solution {
public:

    void recr(vector<vector<int>>& image,int sr, int sc, int color, int prev){
        if(sr >= image.size() || sc >= image[0].size() || sr < 0 || sc < 0 || image[sr][sc] != prev || image[sr][sc] == color ) {
            return;
        }

        image[sr][sc] = color;

        recr(image,sr+1,sc,color,prev);
        recr(image,sr,sc+1,color,prev);
        recr(image,sr-1,sc,color,prev);
        recr(image,sr,sc-1,color,prev);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        recr(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};