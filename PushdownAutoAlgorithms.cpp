/**
  *@brief Implemnting algorithms for different context free languages
 */
#include <iostream> 
#include <vector>
#include <cctype>
#include <unordered_set>
#include<array>

using namespace std ;


/**
 * /brief function for a^nb^nlanguage 
 * basically simulating a pushdown automaton 
 */

bool pushdown_automaton(string word){

    vector<string> alpha ;

    if (word[0] != 'a') {return false;}

    for (int i=0; i< word.size()/2 ;i ++){
        if (word[i] != 'a') {return false;}
        if (word[i] =='a') {alpha.push_back("a");}
    }
    for (int j = word.size()/2; j<word.size();j++){
        if (word[j] != 'b' || alpha.empty()) {return false;}
        if (word[j] =='b' && (!(alpha.empty()))) {alpha.pop_back();}

    }
    return true;

}

/**
 * /brief function for a^nb^nc^n language 
 * basically simulating a TM with a double stacked pushdown automaton 
 */

bool double_pushdown_automaton(string word){


    vector<string> alpha ;
    vector<string> beta;

    if (word[0] != 'a') {return false;}
      for (int i =0; i<word.size(); i++) {if (!isalpha(word[i])) {return false;}}

    
    for (int i=0; i< word.size()/3 ;i ++){
        if (word[i] != 'a') {return false;}
        if (word[i] =='a') {alpha.push_back("a");
        beta.push_back("a");}
    }
    for (int j = word.size()/3; j<2*(word.size())/3;j++){
        if (word[j] != 'b' || alpha.empty()) {return false;}
        if (word[j] =='b' && (!(alpha.empty()))) {alpha.pop_back();}

    }
    for (int k =2*(word.size())/3 ; k<word.size();k++){
        if (word[k] != 'c' || beta.empty()) {return false;}
        if (word[k] =='c' && (!(beta.empty()))) {beta.pop_back();}

    }


    return true;


}

/**
 * /brief function for 0^n1^n language where the order is not important
 * but we need to check that regardless of the word , we must find the same 
 * number of 0s and 1s
 * basically simulating a Turing Machine
 */

bool TuringMachine_version1(string word){
    
    int one_count = 0;
    int zero_count = 0;
    for (int i = 0; i<word.size(); i++){
        if(word[i] =='0') {zero_count ++;}
        else if(word[i] =='1') {one_count ++;}
        else{return false;}
        
    }
    if (zero_count == one_count) {return true;}
    else{return false;}
}





int main(){
    string user_input ; 
    
    while (true) {
        cout << "Enter word(a^nb^n c^n format): " << endl;
        getline(cin, user_input);
 
        cout << double_pushdown_automaton(user_input) <<endl;
  

    } 




    return 0;

}
