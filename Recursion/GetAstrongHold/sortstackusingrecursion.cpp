
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */


void push(int top, stack<int> &s){
    // Check if stack is empty or the element top is greater than the top element present in the stack
    // if it is greater only then push it into the stack.
    if(s.empty() || top > s.top()){
        s.push(top);
        return;
    }
    
    //if the element is not greater and stack is not empty it means we have to remove the greater elements than top 
    //present in the stack. so perform the recursion again until top is greater than s.top() or 
    // stack is empty
    int newtop = s.top();
    s.pop();
    push(top, s);
    
    //Now once smaller element is inserted into the stack now push the elemnt that is just above of it which is
    //newtop. This will happen for every recursion call
    
    s.push(newtop);
}
void SortedStack :: sort()
{
   //Your code here
   //first empty the stack then, for final element it will remove the final element and 
   //will call the function and will get return. then the last element in stack will go into the 
   //push function once that is done it will come to the second last element and again will call 
   //the push function with second last element in stack and likewise..
   if(s.empty()) return;
   int top = s.top();
   s.pop();
   sort();
   
   push(top, s);
   
}