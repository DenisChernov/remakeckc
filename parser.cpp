/* 
 * File:   parser.cpp
 * Author: demiin
 * 
 * Created on December 6, 2014, 1:07 PM
 */

#include <boost/algorithm/string/replace.hpp>
#include <boost/lexical_cast.hpp>

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
    
    /* оооочень плохое решение */
    idChars["А"] = "а"; idChars["А"] = "а"; idChars["А"] = "а"; idChars["А"] = "а"; 
    idChars["А"] = "а"; idChars["А"] = "а"; idChars["А"] = "а"; idChars["А"] = "а";
    idChars["А"] = "а"; idChars["А"] = "а"; idChars["А"] = "а"; idChars["А"] = "а";
    idChars["А"] = "а"; idChars["А"] = "а"; idChars["А"] = "а"; 
    idChars["А"] = "а"; idChars["А"] = "а"; idChars["А"] = "а";
    idChars["А"] = "а"; idChars["А"] = "а"; idChars["А"] = "а";
    idChars["А"] = "а"; idChars["А"] = "а"; idChars["А"] = "а";
    idChars["А"] = "а"; idChars["А"] = "а"; idChars["А"] = "а";
    idChars["А"] = "а"; idChars["А"] = "а"; idChars["А"] = "а"; 
    idChars["А"] = "а"; idChars["А"] = "а"; idChars["А"] = "а";
    
}

parser::~parser() {
}

pair<FIELD_CODE, string> parser::checkFld(string line) 
{
    boost::regex re(".*(#200:|#909:|#903:|#933:|#910:|#907:|#1005:).*");
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
        if (result[1] == "#907:" || result[1] == "#1005:")
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

string parser::getNumber(string line) 
{
    //#903: Сме/2009/3
    boost::regex re(".*/*/(\\d{1,3})");
    boost::smatch result;
    boost::regex_search(line, result, re);
            
    return result[1];
}

string parser::getYear(string line) 
{
    boost::regex re(".*(C|Q)(\\d{4}).*");
    boost::smatch result;
    boost::regex_search(line, result, re);
    
    return result[2];
}

string parser::getRange(string line) 
{
    boost::regex re("");
    boost::smatch result;
    boost::regex_search(line, result, re);
    
    return result[1];
}

void parser::printRange(vector<string> range) 
{
    vector<string>::const_iterator it = range.begin();
    while (it != range.end())
    {
        cout << it->data() << ", ";
        it++;
    }
    cout << endl;
}


string parser::remakeRange(string line) 
{
    vector<string> range;
    vector<string> tmpRange;
    string newRange = line;
    cout << "исходный: " << newRange << endl;
    boost::replace_all(newRange, " ", "");
    boost::replace_all(newRange, "(с/в)", "");
    boost::replace_all(newRange, "с/в", "");
    boost::replace_all(newRange, "спец.", "");        
    boost::replace_all(newRange, "№", ",");
    cout << "после замены: " << newRange << endl;    
    // объединение диапозонов

    
    boost::regex re_range("(\\d{1,3})-(\\d{1,3})");
    boost::smatch result;
    boost::regex_search(newRange, result, re_range);
    range.clear();
    for (size_t i = boost::lexical_cast<size_t>(result[1]); i <= boost::lexical_cast<size_t>(result[2]); i++)
    {
        range.push_back(boost::lexical_cast<string>(i));
    }

    cout<< "reparsed: " << range.front().data() << "-" << range.back().data() << endl;
    printRange(range);
    cout << "******" <<endl;
    string::const_iterator start = newRange.begin();
    string::const_iterator stop =  newRange.end();
    while (boost::regex_search(start, stop, result, re_range))
    {
        tmpRange.clear();
        cout << result[1] << " : " << result[2] << endl;
        for (size_t i = boost::lexical_cast<size_t>(result[1]); i <= boost::lexical_cast<size_t>(result[2]); i++)
        {
            vector<string>::const_iterator it = range.begin();
            bool inRange = false;
            cout << i << endl;
            while (it != range.end())
            {
                
                if (boost::lexical_cast<string>(i) == it->data())
                {
                    inRange = true;
                    break;
                }
                
                it++;
            }
            if (!inRange)
            {
                
                tmpRange.push_back(boost::lexical_cast<string>(i));
            }
            
        }
        cout << "tmpRange: "; printRange(tmpRange); cout<< endl;
        
        
        for (size_t pos = 0; pos < tmpRange.size(); pos++)
            range.push_back(tmpRange.at(pos));
        
        printRange(range);
        
        start = result[2].second;        
    }
   
    start = newRange.begin();
    stop =  newRange.end();
    boost::regex re_single("([0-9\\-]*)(,)");
    tmpRange.clear();
    while (boost::regex_search(start, stop, result, re_single))
    {
        start = result[2].second;     
        if (boost::lexical_cast<string>(result[1]).find_first_of("-", 0) != string::npos)
            continue;

        vector<string>::const_iterator it = range.begin();
        bool inRange = false;
        while (it != range.end())
        {
              
            if (boost::lexical_cast<string>(result[1]) == it->data())
            {
                inRange = true;
                break;
            }
                
            it++;
        }
        if (!inRange)
        {
            tmpRange.push_back(boost::lexical_cast<string>(result[1]));
        }
           
    }    
    for (size_t pos = 0; pos < tmpRange.size(); pos++)
    {
        vector<string>::const_iterator it = range.begin();
        bool dublicate = false;
        while (it != range.end())
        {
            if (it->data() == tmpRange.at(pos))
            {
                dublicate = true;
                break;
            }
            it++;
        }
        if (!dublicate)
            range.push_back(tmpRange.at(pos));
    }
    
    
    newRange = "";
    vector<string>::const_iterator it = range.begin();
    while (it != range.end())
    {
        newRange += it->data();
        it++;
        if (it != range.end())
            newRange += ",";
    }
    
    return newRange;
}

string parser::replaceMonthByNumbers(string line) 
{
    boost::regex re(".*(#909:).*");
    boost::smatch result;
    boost::regex_search(line ,result, re);
    if (result[1] != "")
    {
        
        map<string, string>::const_iterator it = idMonths.begin();
        while (it != idMonths.end())
        {
            boost::replace_all(line, it->first, it->second);
            it++;
        }
    }
    return line;
}

string parser::to_lower(string line) 
{
    
    
    return line;
}
