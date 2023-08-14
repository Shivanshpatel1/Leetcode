class Solution {
public:

    void leftleast(vector<int>& heights, vector<int> &left){
        stack<int> st;
        st.push(-1);
        for(int i=0; i<heights.size(); i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            left[i]=st.top();
            st.push(i);
        }
    }

    void rightleast(vector<int>& heights, vector<int> &right){
        stack<int> st;
        st.push(-1);
        for(int i=heights.size()-1; i>=0; i--){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            right[i]=st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size(), -1);
        vector<int> right(heights.size(), -1);
        leftleast(heights, left);
        rightleast(heights, right);
        int maxarea=0;
        for(int i=0; i<heights.size(); i++){
            int l = left[i];
            int r = right[i];
            if(r==-1){
                r=heights.size();
            }
            int width = r-l-1;
            int height = heights[i];
            int area = width*height;
            maxarea=max(maxarea, area);
        }
        return maxarea;
    }
};