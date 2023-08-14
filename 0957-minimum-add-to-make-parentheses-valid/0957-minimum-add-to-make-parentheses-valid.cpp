// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         stack<char> st;
//         for(int i=0; i<s.size(); i++){
//             char ch=s[i];
//             if(ch=='('){
//                 st.push(ch);
//             }else if(ch==')'){
//                 if(!st.empty() && st.top()=='('){
//                     st.pop();
//                 }else{
//                     st.push(ch);
//                 }
//             }
//         }
//         cout<<st.size();
//         if(st.size()%2!=0) return st.size();
//         int c=0;
//         while(!st.empty()){
//             char ch1=st.top();
//             st.pop();
//             char ch2=st.top();
//             st.pop();
//             cout<<ch1<<" "<<ch2<<endl;
//             if(ch1==')' && ch2=='(') c+=2;
//             if(ch1==')' && ch2==')') c+=1;
//             if(ch1=='(' && ch2=='(') c+=1;               
//         }
//         return c;
//     }
// };
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            char ch=s[i];
            if(ch=='('){
                st.push(ch);
            }else if(ch==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }
        }
        return st.size();
    }
};