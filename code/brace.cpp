/*
* This program manipulate braces
* Input: curly braces
* Output: pop or push braces in stack
* Line: 140
*/

void check_while_expression(int line, string s)
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


void check_do_while(int line, string s)
{
    int index, index2;
    string str;

    str = s.substr(0, 5);

    /*
    * check whether it is while or not
    * if it is while then examine this portion
    */
    if(str == "while") {

        /* search for parenthesis */
        index = s.find_first_of('(');
        index2 = s.find_last_of(')');

        /* if opening parenthesis not found then report error */
        if(index == -1)
            cout << "Line " << line << " :\tinsert a '(' token\n" << endl;

        /* if closing parenthesis not found then report error */
        if(index2 == -1)
            cout << "Line " << line << " :\tinsert a ')' token\n" << endl;

        /* check whether parenthesis are in disorder */
        if(index != -1 && index2 != -1) {
            if(index > index2)
                cout << "Line " << line << " :\tparenthesis in disorder\n" << endl;

            /* take the expression portion */
            str = s.substr(index + 1, index2 - index - 1);
            str = erase_first_last_space(str);
            /* if empty then report error */
            if(str == "")
                cout << "Line " << line << " :\tput an expression before ')' token\n" << endl;

            /* if expression not empty then check it */
            else
                check_while_expression(line, str);
        }

        /* search for semicolon */
        if(index2 != -1) {
            index = s.find_first_of(';', index2 + 1);

            if(index == -1)
                cout << "Line " << line << " :\tinsert a ';' after ')' token\n" << endl;

            /*
            * if semicolon found then check for extra
            * character before and after semicolon
            */
            else{
                /* check the portion before semicolon */
                str = s.substr(index2 + 1, index - index2 -1);
                str = erase_first_last_space(str);

                if(str != "")
                    cout << "Line " << line << " :\tunexpected character before ';' token\n" << endl;

                /* check the portion after semicolon */
                str = s.substr(index + 1);
                str = erase_first_last_space(str);

                if(str != "")
                    cout << "Line " << line << " :\tunexpected character after ';' token\n" << endl;
            }
        }
    }
}

void check_brace(int line, string s)
{
    string str;
    int index;

    /* if opening brace then push it to stack */
    if(s[0] == '{') {
        mystack.push('{');

        /* if extra character found then report error */
        if(s[1] != '\0') {
            index = s.find_first_not_of(' ', 1);
            if(index != -1) {
                cout << "Line " << line << " :\tunexpected character after '{' token\n" << endl;
            }
        }
    }

    /*
    * if closing brace then check whether the stack
    * empty or not; if empty then report error;
    * else pop a opening brace from the stack
    */
    else if(s[0] == '}') {
        if(mystack.empty())
            cout << "Line " << line << " :\tunexpected '}' token\n" << endl;
        else {
            mystack.top();
            mystack.pop();
        }

        /*
        * if extra character found after closing curly brace
        * then test whether it is while or not
        */
        if(s[1] != '\0') {
            index = s.find_first_not_of(' ', 1);
            if(index != -1) {
                str = s.substr(index);
                str = erase_first_last_space(str);
                check_do_while(line, str);
            }
        }
    }
}
