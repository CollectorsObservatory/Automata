/**
 * @file finiteAutomaton.cpp
 * @brief Implements a finite automaton and a pushdown automaton.
 */

#include <iostream> 
#include <string>
#include <vector>

using namespace std; 


/**
 * @enum STATES3101
 * @brief Defines the states for the finite automaton.
 */
enum STATES3101 {
    State_1,
    State_2,
    State_3,
    State_Final, 


};

/**
 * @brief Simulates a finite automaton that manages a regular language.
 * @param word The word to be processed by the automaton.
 */

void automaton_ift3101(string word){
    STATES3101 currentState = State_1;
    for(char &c : word){
        switch (currentState)
        {
            case State_1:
            if (c == 'a'){
                currentState = State_2;
            }else if (c =='b'){
                currentState = State_3;
            }break;

            case State_2:
            if (c == 'a'){
                currentState = State_Final;
            }else if (c =='b'){
                currentState = State_3;
            }break;

            case State_3:
            if (c == 'a'){
                currentState = State_2;
            }else if (c =='b'){
                currentState = State_Final;
            }break;

            case State_Final:
            if (c == 'a' ||c =='b'){
                currentState = State_Final;

                
     }
        }
    }
    if (currentState == State_Final) {
        cout << "ACCEPTED" << endl;
    }else {
        cout <<"REJECTED" <<endl;
    }
}
/**
 * @enum Pushdown_States
 * @brief Defines the states for the pushdown automaton.
 */
enum Pushdown_States{
    S_1,
    S_2,
    Final,


};
/**
 * @brief Simulates a pushdown automaton for a specific context-free language.
 * @param word The word to be processed by the automaton, containing only '0's and '1's.
 * @return A string "true" if the word is accepted, otherwise "false".
 */
bool pushdown_automaton(string word){
    


    Pushdown_States currentState = S_1;

    vector<char>stack;
    stack.push_back('$');
   

    for(char& c : word){
        switch(currentState){
            case S_1:
            if(c=='0'){
                stack.push_back('0');
            }else if(c=='1' && stack.back()=='0'){
                stack.pop_back();
                currentState = S_2;
            }
            break;

            case S_2:
            if(c=='0'){
                stack.push_back('0');
                currentState = S_1;
            }else if(c=='1' && !stack.empty() && stack.back()!='$'){
                stack.pop_back();

            }else {
                return false;
            }
            break;

            case Final:
            break;

        }
    }
    if(stack.back()=='$'){
        currentState = Final;
        return true;
    }else{
        return false;
    }

}

bool double_pushdown_automaton(string word){

    vector<char> alpha ;
    vector<char> beta;
    enum States{
        State1,
        State_final
    };
    States currentState = State1;


    for (char c:word) {
        switch(currentState) {
            case State1:
            if (c=='a') {
                alpha.push_back('a');
            }else if(c== 'b') {
                beta.push_back('b');
            }break;
            case State_final:
            break;
        }


        
    }
    if (alpha.size()==beta.size()) {currentState = State_final; return true;}
    else {return false;}
}
/**
 * @brief Verifies if a given string of parentheses is properly nested.
 * 
 * This function simulates a pushdown automaton to check whether a string composed
 * exclusively of parentheses '(' and ')' is correctly nested. The automaton uses a stack
 * to track the opening parentheses and ensures each opening parenthesis is properly closed
 * in the correct order. Input containing any characters other than '(' and ')' is immediately
 * rejected.
 * 
 * @param word The string of parentheses to be checked.
 * @return bool Returns true if the string is properly nested, false otherwise.
 */
bool pushdown(string word){
  
    enum States{
        State_1,      // Initial state, expecting '(' or detecting unmatched ')'
        State_2,      // State after popping a '(', expecting more ')' or '('
        State_g,      // Garbage state (unnecessary for this simple logic but included for completeness)
        State_final   // Accepting state (also not actively used because acceptance is determined by the stack being empty)
    };
    for(int i=0 ; i<word.size();i++){
        if (word[i] != ')' && word[i] != '(') {return false;}
    }
    vector <char> stack; 
    stack.push_back('#');
    States currentState = State_1; 
    for (char c: word) {
        switch(currentState) {
            case State_1:
            if (c == '(') {
                stack.push_back('x');

            }else if(c == ')' && stack.back()!='x'){
                return false;
                break;
             
            }else if(c == ')' && stack.back()=='x'){
                stack.pop_back();
                currentState=State_2;
            }else {
                currentState = State_g;
            }break;

            case State_2:
            if(c == ')' && stack.back()=='x'){
                stack.pop_back();
            }
            else if(c == ')' && stack.back() !='x'){
                return false;
                break;}
            else if (c=='(') {
                stack.push_back('x');
                currentState = State_1;
            }else {
                currentState = State_g;
            }break;

            case State_g:
            return false;
            break;
            break;
            case State_final:
            break;
        }
    }
    if(stack.back()=='#'){
        currentState = State_final;
        return true;
    }else{
        currentState = State_g;
        return false;
    }


}

/**
 * @brief Verifies if a given string of parentheses and brackets is properly nested.
 * 
 * This function extends the pushdown automaton concept to check whether a string composed
 * exclusively of parentheses '(' and ')' and brackets '[' and ']' is correctly nested. It uses two stacks
 * to track the opening and closing of both types of symbols, ensuring each opening symbol is properly closed
 * in the correct order. Input containing any characters other than '(', ')', '[' and ']' is immediately
 * rejected. The automaton transitions between two states based on the input symbol and the top of the stacks,
 * ensuring the proper nesting of both parentheses and brackets independently.
 * 
 * @param word The string of parentheses and brackets to be checked.
 * @return bool Returns true if the string is properly nested, false otherwise.
 */

bool pushdown_two(string word){
  
  
    enum States{
        State_1,      // Initial state, expecting '(' or detecting unmatched ')'
        State_2,      // State after popping a '(', expecting more ')' or '('
        State_g,      // Garbage state (unnecessary for this simple logic but included for completeness)
        State_final   // Accepting state (also not actively used because acceptance is determined by the stack being empty)
    };

    for(int i=0 ; i<word.size();i++){
        if (word[i] != ')' && word[i] != '(' &&
            word[i] != '[' && word[i] !=']') {return false;}
    }
    vector <char> stack; 
    vector <char> stack_two;

    stack.push_back('#');
    stack_two.push_back('$');

    States currentState = State_1; 

    for (char c: word) {
        switch(currentState) {
            case State_1:
            if (c == '(') {
                stack.push_back('x');
            }else if (c == '['){
                stack_two.push_back('x');
            }
            else if (c == ']' && stack_two.back()!='x') {
                return false;
                break;
            }
            else if(c == ']' && stack_two.back()=='x'){
                stack_two.pop_back();
                currentState=State_2;
            }
            else if(c == ')' && stack.back()!='x'){
                return false;
                break;
             
            }else if(c == ')' && stack.back()=='x'){
                stack.pop_back();
                currentState=State_2;
            }else {
                currentState = State_g;
            }break;

            case State_2:
            if(c == ')' && stack.back()=='x'){
                stack.pop_back();

            }else if(c == ']' && stack_two.back()=='x'){
                stack_two.pop_back();
            }
            else if(c == ')' && stack.back() !='x'){
                return false;
                break;}
            else if(c == ']' && stack_two.back() !='x'){
                return false;
                break;}
            else if (c=='(') {
                stack.push_back('x');
                currentState = State_1;
            }else if(c=='['){
                stack_two.push_back('x');
                currentState = State_1;
            }
            else {
                currentState = State_g;
            }break;

            case State_g:
            return false;
            break;
            break;
            case State_final:
            break;
        }
    }
    if(stack.back()=='#' && stack_two.back() =='$'){
        stack.pop_back();
        stack_two.pop_back();
        currentState = State_final;
        return true;
    }else{
        currentState = State_g;
        return false;
    }


}
bool pushdown_four(string word){
  
  
    enum States{
        State_1,      // Initial state, expecting '(' or detecting unmatched ')'
        State_2,      // State after popping a '(', expecting more ')' or '('
        State_g,      // Garbage state (unnecessary for this simple logic but included for completeness)
        State_final   // Accepting state (also not actively used because acceptance is determined by the stack being empty)
    };

    for(int i=0 ; i<word.size();i++){
        if (word[i] != ')' && word[i] != '(' &&
            word[i] != '[' && word[i] !=']' &&
            word[i] != '{' && word[i] !='}' &&
            word[i] != '<' && word[i] != '>') {return false;}
    }
    vector <char> stack; 
    vector <char> stack_two;
    vector <char> stack_three; 
    vector <char> stack_four; 

    stack.push_back('#');
    stack_two.push_back('$');
    stack_three.push_back('%');
    stack_four.push_back('*');


    States currentState = State_1; 

    for (char c: word) {
        switch(currentState) {
            case State_1:
            if (c == '(') {
                stack.push_back('x');

            }
            else if (c == '['){
                stack_two.push_back('x');
            }
            else if (c == '{') {
                stack_three.push_back('x');
            }
            else if (c == '<') {
                stack_four.push_back('x');
            }
            else if (c == ']' && stack_two.back()!='x') {
                return false;
                break;
            }
            else if (c == '}' && stack_three.back()!='x') {
                return false;
                break;
            }
            else if (c == '>' && stack_four.back()!='x') {
                return false;
                break;
            }
            else if(c == ']' && stack_two.back()=='x'){
                stack_two.pop_back();
                currentState=State_2;
            }
            else if(c == '}' && stack_three.back()=='x'){
                stack_three.pop_back();
                currentState=State_2;
            }
            else if(c == '>' && stack_four.back()=='x'){
                stack_four.pop_back();
                currentState=State_2;
            }
            else if(c == ')' && stack.back()!='x'){
                return false;
                break;
             
            }else if(c == ')' && stack.back()=='x'){
                stack.pop_back();
                currentState=State_2;
            }
            else {
                currentState = State_g;
            }break;

            case State_2:
            if(c == ')' && stack.back()=='x'){
                stack.pop_back();

            }else if(c == ']' && stack_two.back()=='x'){
                stack_two.pop_back();
            }else if(c == '}' && stack_three.back()=='x'){
                stack_three.pop_back();
            }else if(c == '>' && stack_four.back()=='x'){
                stack_four.pop_back();
            }
            else if(c == ')' && stack.back() !='x'){
                return false;
                break;}
            else if(c == ']' && stack_two.back() !='x'){
                return false;
                break;}
            else if(c == '>' && stack_four.back() !='x'){
                return false;
                break;}
            else if(c == '}' && stack_three.back() !='x'){
                return false;
                break;}
            else if (c=='(') {
                stack.push_back('x');
                currentState = State_1;
            }else if(c=='['){
                stack_two.push_back('x');
                currentState = State_1;
            }else if(c=='{'){
                stack_three.push_back('x');
                currentState = State_1;
            }else if(c=='<'){
                stack_four.push_back('x');
                currentState = State_1;
            }
            else {
                currentState = State_g;
            }break;

            case State_g:
            return false;
            break;
            break;
            case State_final:
            break;
        }
    }
    if(stack.back()=='#' && stack_two.back() =='$' && stack_three.back() == '%' && stack_four.back() == '*'){
        stack.pop_back();
        stack_two.pop_back();
        stack_three.pop_back();
        currentState = State_final;
        return true;
    }else{
        currentState = State_g;
        return false;
    }
}
int main(){
    string input ;
    while(input != "X"){
        cout<<"Enter word: " <<endl;
        getline(cin,input);
        cout<<pushdown_two(input)<<endl;
       
       
    


    }
    return 0;
}

