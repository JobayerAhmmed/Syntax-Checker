/*
* This program check while statement
* Input: line number, line
* Output: report error
* Line: 105
*/

void while_expression(int line, string s)
{
    int index;
    /* search semicolon*/
    index = s.find(';');
    if(index != -1)
        cout << "Line " << line << " :\ttoken ';' is not permissible in an expression\n" << endl;

    /* search comma */
    index = s.find(',');
    if(index != -1)
        cout << "Line " << line << " :\ttoken ',' is not permissible in an expression\n" << endl;
}

void check_while(int line, string s)
{
    int index, index2;
    string str, expression;

    /*
    * check whether it is while or not
    * if while then proceed
    */
    if(s[5] == ' ' || s[5] == '(') {

        /* search for parenthesis*/
        index = s.find_first_of('(');
        index2 = s.find_last_of(')');

        if(index == -1)
            cout << "Line " << line << " :\tinsert a '(' token after 'while'\n" << endl;

        if(index2 == -1)
            cout << "Line " << line << " :\tinsert a ')' token\n" << endl;

        if(index != -1 && index2 != -1) {
            if(index > index2)
                cout << "Line " << line << " :\t'(' and ')' are in disorder\n" << endl;
            else {
                expression = s.substr(index, index2 - index -1);

                /*
                * check the portion between while
                * and opening parenthesis
                */
                str = s.substr(5, index - 5);
                str = erase_first_last_space(str);
                if(str != "")
                    cout << "Line " << line << " :\tunexpected character before '(' token\n" << endl;

                /*
                * check the expression within parenthesis
                */
                expression = erase_first_last_space(expression);
                if(expression == "")
                    cout << "Line " << line << " :\tput an expression within parenthesis\n" << endl;
                else
                    while_expression(line, expression);

                /*
                * check the portion after closing parenthesis
                */
                /* search for '{' */
                index = s.find_last_of('{');
                if(index != -1) {
                    mystack.push('{');

                    /* check the portion between ')' and '{' */
                    str = s.substr(index2 + 1, index - index2 -1);
                    str = erase_first_last_space(str);

                    if(str != "")
                        cout << "Line " << line << " :\tunexpected character after ')' token\n" << endl;

                    /* check the portion after '{' */
                    str = s.substr(index + 1);
                    str = erase_first_last_space(str);

                    if(str != "")
                        cout << "Line " << line << " :\tunexpected character after '{' token\n" << endl;
                }

                /*
                * if '{' not found then check the portion
                * after closing parenthesis
                */
                else {
                    str = s.substr(index2 + 1);
                    str = erase_first_last_space(str);

                    if(str != "")
                        cout << "Line " << line << " :\tunexpected character after ')' token\n" << endl;
                }
            }
        }
    }
}
