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
string pushdown_automaton(string word){
    
    string t ="true" ;
    string f = "false";

    Pushdown_States currentState = S_1;

    vector<char>stack;
    stack.push_back('$');
    for(int i=0;i<word.size();i++){
        if(!(word[i] == '0' || word[i] == '1')){return f;}
    }


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

            }break;

            case Final:
            break;

        }
    }
    if(stack.back()=='$'){
        currentState = Final;
        return t;
    }else{
        return f;
    }

}



int main(){
    string input ;
    while(input != "X"){
        cout<<"Enter word: " <<endl;
        getline(cin,input);
        //automaton_ift3101(input) ;
       
       
        cout << pushdown_automaton(input)<<endl;


    }
    return 0;
}

