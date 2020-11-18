/*
* This program check variable declaration
* Input: line number, statement
* Output: report errors
* Line: 105
*/

void check_declaration(int line, string s)
{
    int index, index2;
    string str;
    string token[20], token2[10];


    /*
    * search for semicolon
    */
    index = s.find_first_of(';');
    index2 = s.find_first_of(' ');  // index of first space in the line

    /* report error if semicolon not found */
    if(index == -1) {
        cout << "Line " << line << " :\tinsert a ';'\n" << endl;

        // take variable portion
        str = s.substr(index2 + 1);
    }

    /* take variable portion */
    else {
        str = s.substr(index2 + 1, index - index2 - 1);

        /* check if there is extra character after semicolon*/
        if(s[index + 1] != '\0')
            cout << "Line " << line << " :\tunqualified character after ';' token\n" << endl;

    }
    str = erase_first_last_space(str);


    /* separate each variable using comma */
    tokenize(str, ',', token);

    /* calculate the number of variable using comma */
    index = token_number(str, ',');

    /* check each variable */
    for(int i = 0; i < index; i++) {

        token[i] = erase_first_last_space(token[i]);

        /* if variable is empty then report error*/
        if(token[i] == "")
            cout << "Line " << line << " :\textra ',' token\n" << endl;

        /*
        * search that there are spaces in each variable
        */
        else {
            int n = token_number(token[i], ' ');
            if(n > 1) {
                tokenize(token[i], ' ', token2);

                for(int j = 0; j < n; j++) {
                    token2[j] = erase_first_last_space(token2[j]);
                    if(token2[j] == "");
                    else {
                        index2 = check_name(line, token2[j]);
                        if(index2 == 0)
                            cout << "Line " << line << " :\t\'" << token2[j] << "\' was not declared\n" << endl;
                    }
                }
            }

            /* if variable is valid then store in vector */
            else {
                index2 = check_name(line, token[i]);
                if(index2 == 0)
                    local_var.push_back(token[i]);
            }
        }
    }

}

/*
* This program verify a variable whether it
* is declared or not
*/

int verify_declaration(string s)
{
    int n = local_var.size();

    for(int i = 0; i < n; i++) {

        /* if found then return 0 */
        if(s == local_var.at(i))
            return 0;
    }

    /* if not found then return -1 */
    return -1;
}
