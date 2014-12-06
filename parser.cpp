/* 
 * File:   parser.cpp
 * Author: demiin
 * 
 * Created on December 6, 2014, 1:07 PM
 */

#include "parser.h"

parser::parser() {
}

parser::~parser() {
}

pair<FIELD_CODE, string> parser::checkFld(string line) 
{
    boost::regex re(".*(#200:|#909:|#903:).*");
    boost::smatch result;
    boost::regex_search(line ,result, re);
    if (result[1] != "")
    {
        if (result[1] == "#200:")
            return make_pair(FIELD_TITLE, line);
        else
        if (result[1] == "#909:")
            return make_pair(FIELD_909, line);
        else
        if (result[1] == "#903:")
            return make_pair(FIELD_CIFER, line);
        
    }
    
    return make_pair(REST_FIELD, line);
}

string parser::getTitle(string line) 
{
    boost::regex re("#200: \\^A([\\(\\)\\?\\-\"'+&a-zA-ZйцукенгшщзхъфывапролджэячсмитьбюЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ0-9\\s/,\\.;]*).*");
    boost::smatch result;
    boost::regex_search(line, result, re);
    return result[1];
}

string parser::getAccum_jur(string line) 
{
    boost::regex re("#909: (.*)");
    boost::smatch result;
    boost::regex_search(line, result, re);
    return result[1];
}

string parser::getAccum_num(string line) 
{
    boost::regex re("#910: (.*)");
    boost::smatch result;
    boost::regex_search(line, result, re);
    return result[1];
}

string parser::getCifer(string line) 
{
    boost::regex re("#903: (.*)");
    boost::smatch result;
    boost::regex_search(line, result, re);
    return result[1];
}

string parser::getCifer_jur(string line) 
{
    boost::regex re("#933: (.*)");
    boost::smatch result;
    boost::regex_search(line, result, re);
    return result[1];
}


