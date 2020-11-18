/*
* This program check the scanf() function
* Input: line number, line
* Output: report error
* Line: 110
*/

void check_scanf(int line, string s)
{
    int index, index2, index3, index4;
    string str;
    string token[10], token2[10];

    /* search for opening parenthesis */
    index = s.find('(');
    if(index == -1) {
        cout << "Line " << line << " :\tinsert '(' token after 'scanf'\n" << endl;
        return;
    }


    /* search for closing parenthesis */
    index2 = s.find(')');
    if(index2 == -1) {
        cout << "Line " << line << " :\tinsert ')' token\n" << endl;
        return;
    }


    /* search for opening quotation */
    index3 = s.find_first_not_of(' ', index + 1);
    if(s[index3] != '"') {
        cout << "Line " << line << " :\tinsert '\"' token after '('\n" << endl;
        return;
    }


    /* search for closing quotation */
    index4 = s.find('"', index3 + 1);
    if(index4 == -1) {
        cout << "Line " << line << " :\tinsert '\"' token before ')'\n" << endl;
        return;
    }


    /* check the variable portion */
    str = s.substr(index4 + 1, index2 - index4 -1);
    str = erase_first_last_space(str);

    if(str != "") {
        if(str[0] != ',') {
            cout << "Line " << line << " :\tinsert ',' token after '\"'\n" << endl;
            return;
        }
        else {
            if(str[1] == '\0') {
                cout << "Line " << line << " :\tunexpected ',' token after '\"'\n" << endl;
                return;
            }
        }

        /* check for comma */
        int n = token_number(str, ',');
        tokenize(str, ',', token);

        for(int i = 1; i < n; i++) {

            token[i] = erase_first_last_space(token[i]);

            if(token[i] != "") {

                int m = token_number(token[i], ' ');
                tokenize(token[i], ' ', token2);

                for(int j = 1; j < m; j++) {

                    token2[j] = erase_first_last_space(token2[j]);
                    if(token2[j] != "")
                        cout << "Line " << line << " :\tinsert ',' token after '" << token2[j-1] << "'\n" << endl;
                }
            }

            else {
                cout << "Line " << line << " :\tunexpected ',' token after '" << token[i-1] << "'\n" << endl;
            }
        }
    }

    /* check for semicolon */
    index = s.find(';', index2 + 1);
    if(index == -1)
        cout << "Line " << line << " :\tinsert ';' token after ')'\n" << endl;

    else {

        /* check between ')' and ';' */
        str = s.substr(index2 + 1, index - index2 - 1);
        str = erase_first_last_space(str);

        if(str != "")
            cout << "Line " << line << " :\tunexpected character after ')' token\n" << endl;

        /* check after ';' */
        str = s.substr(index + 1);
        str = erase_first_last_space(str);

        if(str != "")
            cout << "Line " << line << " :\tunexpected character after ';' token\n" << endl;
    }
}
