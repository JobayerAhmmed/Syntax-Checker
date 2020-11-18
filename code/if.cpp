/*
* This program check if statement
* Input: line number, string
* Output: report error
* Line: 70
*/

void check_if_expression(int line, string s)
{
    int index;
    /* search semicolon*/
    index = s.find(';');
    if(index != -1) {
        cout << "Line " << line << " :\ttoken ';' is not";
        cout << " permissible in an expression\n" << endl;
    }

    /* search comma */
    index = s.find(',');
    if(index != -1) {
        cout << "Line " << line << " :\ttoken ',' is not";
        cout << " permissible in an expression\n" << endl;
    }
}

void check_if(int line, string s)
{
    int index, index2;
    string str, expression;

    /* index of closing parenthesis*/
    index = s.find_last_of(')');

    /* if closing parenthesis not found then report error */
    if(index == -1) {
        cout << "Line " << line << " :\tinsert a closing parenthesis\n" << endl;
        return;
    }

    /* if found then take the expression */
    else {
        index2 = s.find_first_of('(');
        expression = s.substr(index2 + 1, index - index2 -1);

        /*
        * check the expression whether it is empty or not
        */
        expression = erase_first_last_space(expression);
        if(expression == "")
            cout << "Line " << line << " :\texpected expression before ')' token\n" << endl;

        /* send expression to check */
        else
            check_if_expression(line, expression);

        /* take the portion after closing parenthesis */
        str = s.substr(index + 1);
        str = erase_first_last_space(str);

        /* check after closing parenthesis */
        if(str == "{")
            mystack.push('{');

        else if(str != "")
            cout << "Line " << line << " :\tunexpected character after ')' token\n" << endl;
    }
}
