class Solution {
public:
void Parenthesis(vector<string>&ans,int n,int os,int cs,string str){
    if(str.size()==n*2){
        //base case 
        ans.push_back(str);
        return ;
    }
    if(os<n){
      Parenthesis(ans,n,os+1,cs,str+"(");
    }
    if(cs<os){
        Parenthesis(ans,n,os,cs+1,str+")");

    }
}
    vector<string> generateParenthesis(int n) {
    vector<string>result;
    Parenthesis(result,n,0,0,"");
    return result;
    }
};