class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int len=code.size();
         vector<int>result(len);
         if(k==0){
            for(int i=0;i<len;i++)
            result[i]=0;
         }
         else if(k>0){
            for(int i=0;i<len;i++){
                for(int j=1;j<=k;j++){
                    result[i]+=code[(i+j)%len];

                }
            }

         }
        else{
            for(int i=0;i<len;i++)
            {
                for(int j=-1;j>=k;j--){
                    int index=(i+j)%len;
                    if(index<0){
                        index=index+len;
                    }
                    result[i]+=code[index];
                }
            }

         }
         return result;
    }
};