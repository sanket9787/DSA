
class Solution{
public:
    void InsertAtbottom(int top, stack<int> &st){
        //if stack is empty insert the element into the stack
        if(st.empty()){
            st.push(top);
            return;
        }
       
       //if stack is not empty it means we first need to empty the stack so that the element which has come now in the function
       //call(top) should be inserted at the bottom.
       //set the current top element in stack to newtop
        int newtop = st.top();
        st.pop();
        //call this function as much times until stack becomes empty and the given element in the function call (top) is inserted
        //at the bottom in stack.
        InsertAtbottom(top, st);
    
        //After inserting the element from function call at the bottom insert the newtop into the stack.
        st.push(newtop);
        
    }
    
    void Reverse(stack<int> &st){
        //first take out elements from stack
        if(st.empty()) return;
        int top = st.top();
        st.pop();
        Reverse(st);
        //get element from stack and insert it at the bottom
        InsertAtbottom(top,st);
    }
    
};