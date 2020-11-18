/*
* This program check do statement
* Input: line number, string
* Output: report error
* Line: 45
*/

void check_do(int line, string s)
{
    int index;
    string str;

    /* search for '{' */
    index = s.find('{', 2);

    if(index != -1) {
        mystack.push('{');

        /* check the portion between do and '{' */
        str = s.substr(2, index - 2);
        str = erase_first_last_space(str);

        if(str != "")
            cout << "Line " << line << " :\tunexpected character before '{' token\n" << endl;

        /* check the portion after '{' */
        str = s.substr(index + 1);
        str = erase_first_last_space(str);

        if(str != "")
            cout << "Line " << line << " :\tunexpected character after '{' token\n" << endl;
    }

    /*
    * if '{' not found then check
    * the portion after do
    */
    else {
        str = s.substr(2);
        str = erase_first_last_space(str);

        if(str != "")
            cout << "Line " << line << " :\tunexpected character after 'do'\n" << endl;
    }
}
