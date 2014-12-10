/* 
 * File:   parser.cpp
 * Author: demiin
 * 
 * Created on December 6, 2014, 1:07 PM
 */

#include <boost/algorithm/string/replace.hpp>

#include "parser.h"

parser::parser() {
    idFilials["ф 1"]        = "1";
    idFilials["ф 2"]        = "2";
    idFilials["ф 3"]        = "3";
    idFilials["ф 4"]        = "4";
    idFilials["ф 5"]        = "5";
    idFilials["ф 6"]        = "6";
    idFilials["ф 7"]        = "7";
    idFilials["ф 8"]        = "8";
    idFilials["ф 9"]        = "9";
    idFilials["ф 10"]       = "10";
    idFilials["ф 11"]       = "11";
    idFilials["ф 14"]       = "14";
    idFilials["ф 15"]       = "15";
    idFilials["ф 22"]       = "22";
    idFilials["ф 23"]       = "23";
    idFilials["ф 24"]       = "24";
    idFilials["ф 25"]       = "25";
    idFilials["ф 26"]       = "11";
    idFilials["ЦГБ ЦОДИ"]   = "26";
    idFilials["ЦГБ АБ"]     = "27";
    idFilials["ЦГБ ЦМООП"]  = "28";
    idFilials["ЦГБ СБО"]    = "29";
    idFilials["ЦГБ ЦКХ"]    = "30";
    idFilials["ЦГБ ОКЛ"]    = "31";
    
    idMonths["январь"]      = "1";
    idMonths["февраль"]     = "2";
    idMonths["февр"]        = "2";
    idMonths["март"]        = "3";
    idMonths["апрель"]      = "4";
    idMonths["апр"]         = "4";
    idMonths["май"]         = "5";
    idMonths["июнь"]        = "6";
    idMonths["июль"]        = "7";
    idMonths["август"]      = "8";
    idMonths["сентябрь"]    = "9";
    idMonths["октябрь"]     = "10";
    idMonths["ноябрь"]      = "11";
    idMonths["декабрь"]     = "12";
}

parser::~parser() {
}

pair<FIELD_CODE, string> parser::checkFld(string line) 
{
    boost::regex re(".*(#200:|#909:|#903:|#933:|#910:|#907:).*");
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
        else
        if (result[1] == "#933:")
            return make_pair(FIELD_CIFER_JUR, line);        
        else
        if (result[1] == "#910:")
            return make_pair(FIELD_910, line);  
        if (result[1] == "#907:")
            return make_pair(FIELD_REMOVE, line);  
        
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

string parser::replaceCodDivision(string line) 
{
    boost::regex re(".*\\^[Bb](\\d{1,2}).*");
    boost::smatch result;
    boost::regex_search(line, result, re);
    string replaceWhat = "^B" + result[1];
    string replaceFor = "^B" + idFilials[getDivision(line)];
    boost::replace_first(line, replaceWhat, replaceFor);
    return line;
}

string parser::getDivision(string line) 
{
    boost::regex re(".*\\^[Dd]([йцукенгшщзхъфывапролджэячсмитьбюЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ0-9\\s]*).*");
    boost::smatch result;
    boost::regex_search(line, result, re);
    
    return result[1];
}
