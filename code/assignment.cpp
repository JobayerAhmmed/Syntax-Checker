/*
* This program check value assignment
* Input: line number, statement
* Output: report errors
* Line: 60
*/

void check_assignment(int line, string s)
{
    int index, index2;
    string str;

    /* index of = */
    index = s.find_first_of('=');

    /* take variable name */
    str = s.substr(0, index);
    str = erase_first_last_space(str);

    /* check whether it is declared or not */
    if(verify_declaration(str) == -1)
        cout << "Line " << line << " :\t\'" << str << "\' was not declared\n" << endl;

    /* check for semicolon */
    index2 = s.find_first_of(';');

    /* if semicolon not found then report error*/
    if(index2 == -1) {
        cout << "Line " << line << " :\tinsert a semicolon\n" << endl;

        /* take value portion */
        str = s.substr(index + 1);
    }

    /* take value portion */
    else {
        str = s.substr(index + 1, index2 - index -1);
    }
    str = erase_first_last_space(str);

    /*
    * if value portion is empty then report error
    */
    if(str == "")
        cout << "Line " << line << " :\tassign value\n" << endl;

    /*
    * if semicolon found then check whether there is
    * extra character after semicolon
    */
    /* take substring after semicolon */
    if(index2 != -1) {
        str = s.substr(index2 + 1);
        str = erase_first_last_space(str);

        if(str != "") {
            cout << "Line " << line << " :\tunqualified character after ';' token\n" << endl;
        }
    }
}
