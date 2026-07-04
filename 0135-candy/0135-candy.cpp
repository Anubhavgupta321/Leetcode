class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int candy=1,i=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                candy++;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                candy+=peak;
                i++;
            }
            int down=0;
            while(i<n && ratings[i]<ratings[i-1]){
                down++;
                candy+=down;
                i++;
            }
            down++;
            if(down>peak){
                candy+=(down-peak);
            }
        }
        return candy;
    }
};