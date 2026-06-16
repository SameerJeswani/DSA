class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int i:students){
            q.push(i);
        }

        int n = students.size();
        int count = 0;
        for(int i=1; i<n*n && !q.empty(); i++){
            int stud = q.front();
            q.pop();
            int sand = sandwiches[count];
            if(stud==sand){
                count++;
            }
            else{
                q.push(stud);
            }
        }
        // return
        return n-count;
    }
};