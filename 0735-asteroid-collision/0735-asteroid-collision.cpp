class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int curr: asteroids){
            bool destroyed=false;
            while(! st.empty() && st.top()>0 && curr<0){
                int topVal = st.top();

                if(abs(topVal)< abs(curr)){
                    st.pop();
                    continue;

                }
                else if(abs(topVal) > abs(curr)){
                    destroyed = true;
                }
                else{
                    st.pop();
                    destroyed = true;
                }
                break;
            }
            if(!destroyed)st.push(curr);

            
        }
        vector<int> result(st.size());
        for(int i=st.size()-1; i>=0; i--){
            result[i] = st.top();
            st.pop();
            
        }
        return result;
        
    }
};