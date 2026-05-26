class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       
        vector<vector<int>> tree;
        tree.push_back( {1} ) ;
        if(numRows == 1){return tree;}

        tree.push_back( {1,1} ) ;
        if(numRows == 2){return tree;}

        // for(int i =0;i<tree.size();i++ ){
        //     for(int j=0;j<tree[i].size();j++ ){
        //         cout<<tree[i][j]<<" " <<i<<" "<<j;;
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        for(int i=3 ; i <= numRows ; i++){
            tree.push_back({1}); // creates i-th level (vector with first element as 1)
            
            // fill
            for(int j = 1 ; j<=i-2 ; j++){
                // tree[i-1] = current level to be filled
                //tree[i-2] = previous level 
                tree[i-1].push_back( tree[i-2][j-1] + tree[i-2][j]);
            }
            
            tree[i-1].push_back(1);
        }
        return tree;
    }
};