/*
** Input: header file line
** Output: check and report errors
** Line: 80
*/

void check_header(int line, string s)
{
    string headers[9] = {"stdio.h", "string.h", "math.h",
                            "stdlib.h", "time.h", "ctype.h",
                            "float.h", "limits.h", "locale.h"};

    int index, index2;
    string str;

    /* search for opening angle bracket */
    index = s.find('<');

    if(index != -1) {

        str = s.substr(1, index - 1);
        str = erase_first_last_space(str);

        /* check the 'include' */
        if(str == "")
            cout << "Line " << line << " :\tinsert 'include' after '#'\n" << endl;

        else if(str != "include")
            cout << "Line " << line << " :\tspelling mistake of 'include'\n" << endl;
    }

    else {
        cout << "Line " << line << " :\ttoken '<' missing\n" << endl;
        return;
    }


    /* search for closing angle bracket */
    index2 = s.find('>');

    if(index2 != -1) {

        str = s.substr(index + 1, index2 - index - 1);

        if(str[0] == ' ')
            cout << "Line " << line << " :\tunexpected space after '<' token\n" << endl;

        else {
            str = erase_first_last_space(str);

            for(int i = 0; i < 9; i++) {

                if(str == headers[i])
                    break;

                if(i == 8)
                    cout << "Line " << line << " :\t'" << str << "' is not a header file\n" << endl;
            }
        }
    }

    else {
        cout << "Line " << line << " :\ttoken '>' missing\n" << endl;
        return;
    }


    /* check the order of angle bracket */
    if(index > index2) {
        cout << "Line " << line << " :\tangle brackets are in disorder\n" << endl;
        return;
    }

    /* check after closing angle bracket*/
    str = s.substr(index2 + 1);
    str = erase_first_last_space(str);

    if(str != "")
        cout << "Line " << line << " :\tunexpected character after '>' token\n" << endl;
}
