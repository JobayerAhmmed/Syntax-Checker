/*
*****************************
*
* NAME: Syntax Checker
* INPUT: C File
* OUTPUT: Report Errors
*
*****************************
*
* DESCRIPTION:
* This program checks a C file for basic syntax
* errors and reports errors as much as possible.
*
************************************************
*
* DEVELOPERS:
*           JOBAYER AHMMED
*           BSSE 0502
*           SHADIQUR RAHAMAN
*           BSSE 0517
*           SAUVIK BHAUMIK ANIK
*           BSSE 0518
*
************************************************
* TOTAL LINE OF CODE: 1900
************************************************
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<vector>
#include<stack>

using namespace std;

/*
* global variables
*/
stack <char> mystack;       // holds opening curly brace
vector <string> local_var;  // holds local variable
int brace_flag = -1;        // opening curly brace flag of function

/*
* files of required functions
*/
#include "erase_first_last_space.cpp"
#include "tokenizer.cpp"
#include "kmp.cpp"          // string searching function
#include "character.cpp"    // character searching function
#include "name.cpp"         // check variable and function name
#include "type.cpp"
#include "token.cpp"
#include "header.cpp"
#include "brace.cpp"
#include "function.cpp"
#include "declaration.cpp"
#include "assignment.cpp"
#include "printf.cpp"
#include "scanf.cpp"
#include "if.cpp"
#include "else.cpp"
#include "for.cpp"
#include "while.cpp"
#include "do.cpp"
#include "break.cpp"
#include "return.cpp"


int main(void)
{
    char* name;     // file name
    vector <string> lines;  // holds the content of the C file
    string s;       // holds a line
    int line;       // current line number
    int n = 0;      // total line number
    int index, index2;
    int comment_flag;
    int p, q;       // for temporary use
    string str;     // for temporary use
    string token[20], token1[10], token2[10];

    /*
    * print input message to enter file name,
    * check whether it is a C file or not,
    * open and read file,
    * close file.
    */
    cout << "Enter file name: ";
    getline(cin, s);
    cout << endl;

    /* check the file extension */
    index = s.find_last_of('.');
    if(index != -1) {
        str = s.substr(index + 1);
        str = erase_first_last_space(str);

        /* if extension is c then open file */
        if(str == "c") {

            name = new char[s.length() + 1];
            strcpy(name, s.c_str());

            ifstream file (name);

            if(file.is_open()) {

                while(getline(file, s)) {
                    lines.push_back(s);
                    n++;
                }

                file.close();
            }
            else{
                cout << "Unable to open file\n" << endl;
                cout << "Press any key to continue...";
                getch();
                exit(1);
            }
        }

        else {
            cout << "The given file is not a C file\n" << endl;
            cout << "Press any key to continue...";
            getch();
            exit(1);
        }
    }

    else {
        cout << "The given file is not a C file\n" << endl;
        cout << "Press any key to continue...";
        getch();
        exit(1);
    }

    /* ************END OF TAKING INPUT**********************
    ********************************************************/

    /*
    * examine each line
    */
    line = 1;
    comment_flag = 0;
    while(line <= n) {

        /* take a line */
        s = lines.at(line-1);
        s = erase_first_last_space(s);

        /* ***********************************************
        * search for comment
        *************************************************/
        if(comment_flag == 0) {
            index = s.find("//");
            index2 = s.find("/*");

            /* for single line comment */
            if(index != -1) {
                s = s.substr(0, index);
                s = erase_first_last_space(s);
            }

            /* for multi-line comment */
            else if(index2 != -1) {
                comment_flag = 1;
                str = s.substr(0, index2);

                index = s.find("*/", index2+2);

                if(index != -1) {
                    comment_flag = 0;
                    str = str + s.substr(index+2);
                }
                s = str;
            }
        }

        else {
            index = s.find("*/");
            if(index != -1) {
                comment_flag = 0;
                s = s.substr(index+2);
                s = erase_first_last_space(s);
            }
            else
                s = "";
        }
        /* ************ END OF COMMENT CHECK ********************
        ********************************************************/
        /*
        * take decision on each line
        */
        if(s == "")
            s = ""; // do nothing

        else {

            /*
            * search for opening curly brace of function
            */
            if(brace_flag == 0) {
                if(s[0] == '{') {
                    brace_flag = -1;
                }

                else {
                    cout << "Line " << line - 1 << " :\t" <<
                        "insert '{' after ')' token\n" << endl;
                    mystack.push('{');
                    brace_flag = -1;
                }
            }

            /*
            * take decision using token
            */
            tokenize(s, ' ', token);
            tokenize(s, '(', token1);   // assume branching or looping

            index = check_token(token[0]);
            p = check_token(token1[0]);

            q = -1;
            if(s.find('=') != -1) {
                tokenize(s, '=', token2);   // assume value assignment

                /* check for naming validity */
                token2[0] = erase_first_last_space(token2[0]);
                q = verify_name(token2[0]);
            }


            /*
            * test header file
            */
            if(s[0] == '#')
                check_header(line, s);

            /*
            * check braces
            */
            else if(s[0] == '{' || s[0] == '}')
                check_brace(line, s);


            /*
            * test on the basis of first token
            */
            else if(index != -1) {

                if(index >= 1 && index <= 4) {
                    index2 = s.find("(");

                    /* test function */
                    if(index2 != -1)
                        check_function(line, s);

                    /* test variable declaration */
                    else
                        check_declaration(line, s);
                }

                /* if void ,test function */
                else if(index == 0) {
                    index2 = s.find("(");

                    if(index2 != -1)
                        check_function(line, s);
                    else
                        cout << "Line " << line << " :\t'void' can not be a variable type\n" << endl;
                }

                /* test printf */
                else if(index == 5)
                    check_printf(line, s);

                /* test scanf */
                else if(index == 6)
                    check_scanf(line, s);

                /* test if statement */
                else if(index == 7)
                    check_if(line, s);

                /* check else and else if statement */
                else if(index == 8) {
                    // take 2 character ignoring space after else
                    int n = s.find_first_not_of(' ', 4);

                    if(n != -1) {
                        if(s.substr(n, 2) == "if")
                            check_if(line, s);

                        /* check for opening brace */
                        else {
                            string str2 = s.substr(n);
                            str2 = erase_first_last_space(str2);

                            if(str2[0] == '{')
                                check_brace(line, str2);
                        }
                    }
                    else
                        check_else(line, s);
                }

                /* check for statement */
                else if(index == 9)
                    check_for(line, s);

                /* check while statement */
                else if(index == 10)
                    check_while(line, s);

                /* check do statement */
                else if(index == 11)
                    check_do(line, s);

                /* check break statement */
                else if(index == 12)
                    check_break(line, s);

                /* check return statement */
                else if(index == 13)
                    check_return(line, s);

                /* check assignment or naming validity */
                else {
                    token[1] = erase_first_last_space(token[1]);

                    if(token[1][0] == '=')
                        check_assignment(line, s);

                    else if(token[0][0] > 64 && token[0][0] < 91 ||
                            token[0][0] > 96 && token[0][0] < 123 ||
                            token[0][0] == 95 || token[0][0] == 36)
                        check_name(line, token[0]);
                }
            }


            /*
            * check for branching and looping
            */
            else if(p != -1) {

                if(p == 5)
                    check_printf(line, s);

                else if(p == 6)
                    check_scanf(line, s);

                else if(p == 7)
                    check_if(line, s);

                else if(p == 9)
                    check_for(line, s);

                else if(p == 10)
                    check_while(line, s);
            }

            /*
            * check value assignment
            */
            else if(q != -1)
                check_assignment(line, s);

            /*
            * check for return statement
            */
            else if(s.substr(0, 6) == "return")
                check_return(line, s);

            /*
            * check for break statement
            */
            else if(s.substr(0, 5) == "break")
                check_break(line, s);

            /*
            * check for else
            */
            else if(s.substr(0, 4) == "else")
                check_else(line, s);

            /*
            * check do while
            */
            else if(s.substr(0, 3) == "do{" || s == "do")
                check_do(line, s);
        }

        line++;
    }

    /*
    * delete the vector
    */
    lines.clear();
    local_var.clear();

    cout << "Press any key to continue...";
    getch();

    return 0;
}
