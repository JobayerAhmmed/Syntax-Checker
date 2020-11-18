/*
** Input: header file line
** Output: check and report errors
** Line: 70
*/
#include<iostream>
#include<string>

using namespace std;

std::string check_header( std::string s)
{
    std::string header_name;
    std::string headers[6] = {"stdio.h", "string.h", "math.h", "stdlib.h", "time.h", "ctype.h"};
    int include_index, first_angle_index, last_angle_index;
    int other_index;

    s.erase(0, 1);  // erase #
    if(s[0] == ' ')
        s.erase(0,s.find_first_not_of(' '));    // erase spaces after #

    include_index = s.find("include"); // find include
    if(include_index == -1)
       return  "spelling mistake of include\n"; 

    if(include_index != -1) {
        s.erase(0, 7);  // erase "include"
        if(s[0] == ' ')
            s.erase(0,s.find_first_not_of(' '));    // erase spaces after "include"

        first_angle_index = s.find('<');
        last_angle_index = s.find('>');
        if(first_angle_index == -1 || last_angle_index == -1) {
              
            return "angle bracket missing\n";
        }

        if(first_angle_index != 0) {
            return "unexpected character after \"include\n" ;
            s.erase(0, first_angle_index); // erase extra character after include
        }

        s.erase(0, 1);  // erase <
        if(s[0] == ' ') {
            return "unexpected space after <\n";
            
        }

        last_angle_index = s.find('>');

        header_name = s.substr(0, last_angle_index);    // copy the header name including space if found

        other_index = header_name.find(' ');   // index of space in the header
        if(other_index != -1)
            header_name = header_name.substr(0, other_index);   // copy the header file name

        int i = 0;
        while(i < 6) {
            if(!header_name.compare(headers[i]))
                break;
            i++;
        }
        if(i == 5)  // if not matched
            return " is not a header file\n";
        s.erase(0, last_angle_index + 1); // erase all characters to >

        other_index = s.find_first_not_of(' ');     // index of extra character after >
        if(other_index > -1)
            return "unexpected character after >\n" ;
    }
	return " ";
}
