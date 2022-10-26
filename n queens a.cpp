void solve(vector<vector<string>>&ans,vector<string>&board,int n,int col,vector<int>&leftcol,vector<int>&upperdia,vector<int>&lowdia)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(leftcol[row]==0 && lowdia[col+row]==0 && upperdia[n-1+col-row]==0)
            {
                leftcol[row]=1;
                lowdia[col+row]=1;
                upperdia[n-1+col-row]=1;
                board[row][col]='Q';
                solve(ans,board,n,col+1,leftcol,upperdia,lowdia);
                board[row][col]='.';
                leftcol[row]=0;
                lowdia[col+row]=0;
                upperdia[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string str(n,'.');
        vector<string>board(n);
        for(int i=0;i<n;i++)
        {
            board[i]=str;
        }
        vector<int>leftcol(n,0),upperdia(2*n-1,0),lowdia(2*n-1,0);
        solve(ans,board,n,0,leftcol,upperdia,lowdia);
        return ans;
    }
