/*
* This program check a function
* Input: line number and function line
* Output: report errors if found
* Line: 125
*/

void check_function(int line, string s)
{
    string str;
    int index, index2;
    string token[10], token2[10];

    /*
    * erase all previous local variables
    */
    local_var.clear();

    /*
    * check the brace stack
    * if not empty then report error
    */
    while(!mystack.empty()) {
        cout << "Line " << line - 1 << " :\tinsert '}'\n" << endl;
        mystack.top();
        mystack.pop();
    }

    /* set brace flag to 0 */
    brace_flag = 0;

    /* index of first space */
    index2 = s.find_first_of(' ');

    /* index of first parenthesis */
    index = s.find_first_of('(');


    /*
    * examine function name
    */
    /* take function name */
    str = s.substr(index2 + 1, index - index2 - 1);

    /* check validity of function name */
    str = erase_first_last_space(str);
    check_name(line, str);

    /* index of closing parenthesis */
    index2 = s.find_first_of(')');

    if(index2 == -1) {
        cout << "Line " << line << " :\t" << "insert ')' token\n" << endl;
        return;
    }


    /*
    * examine the parameter list
    */
    /* take parameter list */
    str = s.substr(index + 1, index2 - index - 1);
    str = erase_first_last_space(str);

    /* check parameter list */
    if(str != "") {

        /* check whether it is void */
        if(str == "void");

        /* if not then check it */
        else {

            /* take parameters using delimiter comma */
            tokenize(str, ',', token);

            /* parameter number */
            index = token_number(str, ',');

            /* check each parameter */
            for(int i = 0; i < index; i++) {

                /* take type name */
                token[i] = erase_first_last_space(token[i]);
                string type = token[i].substr(0, token[i].find_first_of(' '));
                type = erase_first_last_space(type);

                /* check type name */
                if(check_type(type) == -1)
                    cout << "Line " << line << " :\t\"" << type << "\" is not a type\n" << endl;

                else if(check_type(type) == 4)
                    cout << "Line " << line << " :\t\"void\" can not be a variable type\n" << endl;

                /* take parameter name */
                string name = token[i].substr(token[i].find_first_of(' ') + 1);
                name = erase_first_last_space(name);

                /* check parameter name */
                if(check_name(line, name) != -1) {
                    local_var.push_back(name);
                }
            }
        }
    }


    /*
    * examine the portion after closing parenthesis
    */
    str = s.substr(index2 + 1);
    str = erase_first_last_space(str);

    if(str != "") {

        if(str == "{") {
            mystack.push('{');
            brace_flag = -1;
        }

        else
            cout << "Line " << line << " :\tunqualified character after '{'\n" << endl;
    }
}
