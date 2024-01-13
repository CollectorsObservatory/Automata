#include <iostream> 
#include <vector>
#include <cctype>

using namespace std ;


/**
 * /brief function for a^nb^nlanguage 
 * basically simulating a pushdown automaton 
 */

string pushdown_automaton(string word){
    string t = "true";
    string f = "false";
    vector<string> alpha ;

    if (word[0] != 'a') {return f;}

    for (int i=0; i< word.size()/2 ;i ++){
        if (word[i] != 'a') {return f;}
        if (word[i] =='a') {alpha.push_back("a");}
    }
    for (int j = word.size()/2; j<word.size();j++){
        if (word[j] != 'b' || alpha.empty()) {return f;}
        if (word[j] =='b' && (!(alpha.empty()))) {alpha.pop_back();}

    }
    return t;

}

/**
 * /brief function for a^nb^nc^n language 
 * basically simulating a TM with a double stacked pushdown automaton 
 */

string double_pushdown_automaton(string word){
    string t = "true";
    string f = "false";

    vector<string> alpha ;
    vector<string> beta;

    if (word[0] != 'a') {return f;}

    for (int i=0; i< word.size()/3 ;i ++){
        if (word[i] != 'a') {return f;}
        if (word[i] =='a') {alpha.push_back("a");
        beta.push_back("a");}
    }
    for (int j = word.size()/3; j<2*(word.size())/3;j++){
        if (word[j] != 'b' || alpha.empty()) {return f;}
        if (word[j] =='b' && (!(alpha.empty()))) {alpha.pop_back();}

    }
    for (int k =2*(word.size())/3 ; k<word.size();k++){
        if (word[k] != 'c' || beta.empty()) {return f;}
        if (word[k] =='c' && (!(beta.empty()))) {beta.pop_back();}

    }


    return t;


}




int main(){
    string user_input ; 
    while (true) {
        cout << "Enter word(a^nb^n c^n format): " << endl;
        getline(cin, user_input);
        cout << double_pushdown_automaton(user_input)<<endl;

    }



    return 0;

}