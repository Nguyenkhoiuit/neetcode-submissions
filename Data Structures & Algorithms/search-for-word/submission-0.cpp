#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        auto dfs=[&](auto self,int r,int c,int index)->bool{
            if(index==word.size()) return true;
            if(r<0||r>=rows||c<0||c>=cols||board[r][c]!=word[index]) return false;
            char temp=board[r][c];
            board[r][c]='#';
            bool found=self(self,r+1,c,index+1)||self(self,r-1,c,index+1)||self(self,r,c+1,index+1)||self(self,r,c-1,index+1);
            board[r][c]=temp;
            return found;
        };
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(dfs(dfs,i,j,0)) return true;
            }
        }
        return false;
    }
};