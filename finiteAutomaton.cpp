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
 * @return bool True if condition is true
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
/**
 * @brief Simulates a double pushdown automaton for a specific context-free language.
 * @param word The word to be processed by the automaton, containing a mix of a and b
 * @return true if the mix  has the same number of as and bs
 */
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

int main(){
    string input ;
    while(input != "X"){
        cout<<"Enter word: " <<endl;
        getline(cin,input);
        cout <<pushdown_automaton(input)<<endl ;
       
       
    


    }
    return 0;
}

