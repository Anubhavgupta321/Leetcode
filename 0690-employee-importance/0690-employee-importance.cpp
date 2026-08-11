/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    int solve(int id, unordered_map<int,Employee*> mpp){
        Employee* e=mpp[id];
        int total=e->importance;
        for(auto sub:e->subordinates){
            total+=solve(sub,mpp);
        }
        return total;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> mpp;
        for(auto e:employees){
            mpp[e->id]=e;
        }
        return solve(id,mpp);
    }
};