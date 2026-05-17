class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row =matrix.size();
        int col =matrix[0].size();
        vector<int> out;
        
        int top = 0; // row from top
        int right = col-1; // column from right
        int bottom = row-1; // row from bottom
        int left = 0; // column from left 

        while( top<=bottom && right>=left ){

            // printing top row -> left to right
            for(int j = left; j<=right ; j++){    
                out.push_back(matrix[top][j]);
            }
            top++; // next top 
            
            // printing right column -> top to bottom
            for(int i = top ; i<=bottom  ; i++ ){
                out.push_back(matrix[i][right]);
            }
            right --; // next right
            
            // printing bottom row - right to left
            if(top<=bottom){
                for(int j = right ; j >= left ; j-- ){
                    out.push_back(matrix[bottom][j]);
                }
                bottom --; // for next bottom
            }
            
            // printing left column - bottom to top
            if(left<=right){
                for(int i = bottom ; i >=top ; i--){
                    out.push_back(matrix[i][left]);
                }
                left ++;
            }
        }    
        return out;
    }
};