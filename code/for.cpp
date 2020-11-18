/*
* This program check for statement
* Input: line number, for string
* Output: report error
* Line: 100
*/

void check_for_expression(int line, string s)
{
    int n;
    string token[10];

    /* tokenize using semicolon */
    tokenize(s, ';', token);
    n = token_number(s, ';');

    /* report error if semicolon is missing */
    if(n != 3) {

        if(n == 2)
            cout << "Line " << line << " :\tinsert a ';' token in the expression\n" << endl;

        else if(n == 1)
            cout << "Line " << line << " :\tinsert two ';' token in the expression\n" << endl;

        else if(n > 3)
            cout << "Line " << line << " :\tunexpected ';' token in the expression\n" << endl;
    }

    /* check each expression */
    else{
        for(int i = 0; i < 3; i++) {
            n = token[i].find(',');
            if(n != -1)
                cout << "Line " << line << " :\tunexpected character in the expression\n" << endl;
        }
    }
}

void check_for(int line, string s)
{
    int index, index2, index3;
    string str, expression;

    /* find index parenthesis */
    index = s.find_first_of('(');
    index2 = s.find_first_of(')');

    /* find index of opening curly brace */
    index3 = s.find_first_of('{');

    /*
    * take expression on the basis of index
    */
    if(index2 != -1)
        expression = s.substr(index + 1, index2 - index -1);

    else if(index3 != -1) {
        cout << "Line " << line << " :\tinsert a ')' token before '{'\n" << endl;
        expression = s.substr(index + 1, index3 - index -1);
    }

    else {
        expression = s.substr(index + 1);
        cout << "Line " << line << " :\tinsert a ')' token\n" << endl;
    }

    /*
    * check expression
    */
    expression = erase_first_last_space(expression);
    check_for_expression(line, expression);

    /*
    * if opening brace found then take
    * the portion to check brace
    */
    if(index3 != -1) {
        str = s.substr(index3);
        str = erase_first_last_space(str);
        check_brace(line, str);
    }

    /*
    * check whether there is extra
    * character after closing parenthesis
    */
    if(index2 != -1) {
        /* if opening curly brace exist */
        if(index3 != -1)
            str = s.substr(index2 + 1, index3 - index2 -1);

        /* if { not exist */
        else
            str = s.substr(index2 + 1);

        /* check for extra character */
        str = erase_first_last_space(str);
        if(str != "")
            cout << "Line " << line << " :\tunexpected character after ')' token\n" << endl;
    }
}
