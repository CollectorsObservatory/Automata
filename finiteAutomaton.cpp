#include <iostream> 
#include <string>
using namespace std; 

/* Implenting a finite automata that managea a regular language*/
/**/
enum STATES {
    State_1,
    State_2,
    State_3,
    State_Final, 

};

void automata_ift3101(string word){
    STATES currentState = State_1;
    for(char &c : word){
        switch (currentState)
        {
            case State_1:
            if (c == 'a'){
                currentState = State_2;
            }if (c =='b'){
                currentState = State_3;
            }break;

            case State_2:
            if (c == 'a'){
                currentState = State_Final;
            }if (c =='b'){
                currentState = State_3;
            }break;

            case State_3:
            if (c == 'a'){
                currentState = State_2;
            }if (c =='b'){
                currentState = State_Final;
            }break;

            case State_Final:
            if (c == 'a' ||c =='b'){
                currentState = State_Final;
                //break;
            }
            //default: cout <<"Word not accepted" << endl;
        }
    }
    if (currentState == State_Final) {
        cout << "ACCEPTED" << endl;
    }else {
        cout <<"REJECTED" <<endl;
    }
}

int main(){
    string input ;
    while(input != "X"){
        cout<<"Enter password (using only a and b with at least two consecutives iterations of one letter-X to quit): " <<endl;
        getline(cin,input);
        automata_ift3101(input) ;


    }
    return 0;
}

