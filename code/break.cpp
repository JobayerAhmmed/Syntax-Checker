/*
* This program check break statement
* Input: line number, break statement
* Output: report error
* Line: 40
*/

void check_break(int line, string s)
{
    int index;
    string str;

    /*
    * check spelling of break
    */
    if(s[5] == ' ' || s[5] == ';');
    else
        cout << "Line " << line << " :\tspelling mistake\n" << endl;

    /* search for semicolon */
    index = s.find_first_of(';');

    /* if semicolon not found then report error */
    if(index == -1)
        cout << "Line " << line << " :\tinsert a semicolon\n" << endl;

    /*
    * if semicolon found then check there is extra
    * character after semicolon
    */
    else {

        /* take extra character after semicolon if found */
        str = s.substr(index + 1);
        str = erase_first_last_space(str);

        /* if extra character found then report error */
        if(str != "")
            cout << "Line " << line << " :\tunexpected character after semicolon\n" << endl;
    }
}
