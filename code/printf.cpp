/*
** This program check printf function
** Input: line number, line
** Output: report the error if found
** Line: 105
*/

void check_printf(int line, string s)
{
    int index, index2, index3, index4;
    string str;

    /* search for opening parenthesis */
    index = s.find('(');
    index2 = s.find(')');

    if(index == -1) {
        cout << "Line " << line << " :\tinsert '(' token after 'printf'\n" << endl;
        return;
    }

    if(index2 == -1) {
        cout << "Line " << line << " :\tinsert ')' token\n" << endl;
        return;
    }

    if(index != -1 && index2 != -1 && index > index2) {
        cout << "Line " << line << " :\tparenthesis are in disorder\n" << endl;
        return;
    }


    /* check the portion between "printf" and '(' */
    str = s.substr(6, index - 6);
    str = erase_first_last_space(str);

    if(str != "")
        cout << "Line " << line << " :\t unexpected character before '(' token\n" << endl;


    /* search for opening quotation */
    index3 = s.find('"', index + 1);
    if(index3 == -1) {
        cout << "Line " << line << " :\tinsert a '\"' token after '('\n" << endl;
        return;
    }
    else {
        str = s.substr(index + 1, index3 - index - 1);
        str = erase_first_last_space(str);

        if(str != "") {
            cout << "Line " << line << " :\tinsert a '\"' token after '('\n" << endl;
            return;
        }
    }


    /* search for closing quotation */
    index4 = s.find('"',index3 + 1);
    if(index4 == -1) {
        cout << "Line " << line << " :\tinsert '\"' token before ')'\n" << endl;
        return ;
    }

    else {
        /* if closing quotation found then check the variable portion */
        str = s.substr(index4 + 1, index2 - index4 - 1);
        str = erase_first_last_space(str);

        if(str != "") {

            if(str[0] != ',') {
                cout << "Line " << line << " :\tinsert a ',' token after '\"'\n" << endl;
                return;
            }
            else {
                if(str[1] == '\0')
                    cout << "Line " << line << " :\tunexpected ',' token before ')'\n" << endl;
            }
        }
    }

    /* check after closing parenthesis */
    index = s.find(';', index2 + 1);
    if(index == -1) {
        cout << "Line " << line << " :\tinsert ';' token after ')'\n" << endl;
        return;
    }

    else {

        str = s.substr(index2 + 1, index - index2 -1);
        str = erase_first_last_space(str);

        if(str != "")
            cout << "Line " << line << " :\tunexpected character before ';' token\n" << endl;

        str = s.substr(index + 1);
        str = erase_first_last_space(str);

        if(str != "")
            cout << "Line " << line << " :\tunexpected character after ';' token\n" << endl;
    }
}
