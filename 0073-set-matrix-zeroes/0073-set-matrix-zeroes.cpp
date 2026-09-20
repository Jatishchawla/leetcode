class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); // no. of rows
        int n = matrix[0].size(); // no. of columns
        int col0 = matrix[0][0]; 
        for(int i = 0 ; i < m ; i++ ){
            for(int j=0; j<n;j++){
                if(matrix[i][j] == 0 ){
                    matrix[i][0]=0; // marking rows that will set to zero 
                    if(j==0){
                        col0=0;
                    }
                    else{
                        matrix[0][j]=0;
                    }
                }
            }
        }
        for(int i=1; i<m ; i++){ // i = 1 because 1st row and 1st column column are inter dependent , we will handle them seperately
            for(int j=1; j<n ; j++){
                if(matrix[i][j] != 0 ){
                    // if row or column anyone is marked for this ele. set ele = 0 
                    if(matrix[0][j] ==0 || matrix[i][0]==0 ){
                        matrix[i][j]=0;
                    }
                }    

            }
        }
        // handling 1st column 
        if(matrix[0][0]==0){
            for(int j=0 ; j<n ; j++ ){
                matrix[0][j] = 0;
            }
        }
        // handling 1st row
        if(col0 == 0){
            for(int i=0 ; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};