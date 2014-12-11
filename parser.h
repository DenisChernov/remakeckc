/* 
 * File:   parser.h
 * Author: demiin
 *
 * Created on December 6, 2014, 1:07 PM
 */

#ifndef PARSER_H
#define	PARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <boost/regex.hpp>
#include "msgs.h"


using namespace std;

enum FIELD_CODE {REST_FIELD, FIELD_909, FIELD_910, FIELD_CIFER, FIELD_CIFER_NUM, FIELD_CIFER_JUR, FIELD_TITLE, FIELD_REMOVE};

class parser {
public:
    parser();
    virtual ~parser();
    
    msgs msg;
    
    pair<FIELD_CODE, string> checkFld(string line);
    string getTitle(string line);
    string getAccum_jur(string line);
    string getAccum_jur_h(string line);
    string getAccum_num(string line);
    string getCifer(string line);
    string getCifer_jur(string line);
    
    
    string getNumber(string line);
    string getDivision(string line);
    string getYear(string line);
    string getRange(string line);
    
    string replaceCodDivision(string line);
    string remakeRange(string line);

    
private:
    map<string, string> idFilials;
    map<string, string> idMonths;
    map<string, string> idChars;
    
    void printRange(vector<string> range);
};



#endif	/* PARSER_H */

