class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool isValid = false;
        bool isValidForRow = true;
        bool isValidForCol = true;
        bool isValidForSubMat = true;
       
        //check row wise
        for(int i=0;i<9;i++){
            map<char,int> hash;
           
            for(int j = 0;j<9;j++){
                if(board[i][j]=='.')continue;
                hash[board[i][j]]++;
                if(hash[board[i][j]]>1) {
                    isValidForRow=false;
                    return isValid;
                }    
            }
        }
        //check column wise
        for(int i=0;i<9;i++){
            
            map<char,int> hash;
            for(int j = 0;j<9;j++){
                if(board[j][i]=='.')continue;
                hash[board[j][i]]++;
                if(hash[board[j][i]]>1) {
                    isValidForCol=false;
                    return isValid;
                }    
            }
        }
        //check submatrix wise
        for(int i=0;i<9;i++){
            
            map<char,int> hash;
            for(int j = 3*(i/3);j<3*(i/3)+3;j++){
               for(int k=3*(i%3);k<3*(i%3)+3;k++){
                if(board[j][k]=='.')continue;
                hash[board[j][k]]++;
                if(hash[board[j][k]]>1){
                    isValidForSubMat=false;
                    return isValid;
                }
               }
            }
        }
        if(isValidForRow && isValidForCol && isValidForSubMat){
            isValid = true;
        }
        return isValid;
    }

};