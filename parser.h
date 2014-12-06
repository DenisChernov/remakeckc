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

enum FIELD_CODE {REST_FIELD, FIELD_909, FIELD_910, FIELD_CIFER, FIELD_CIFER_NUM, FIELD_TITLE};

class parser {
public:
    parser();
    virtual ~parser();
    
    msgs msg;
    
    pair<FIELD_CODE, string> checkFld(string line);
    string getTitle(string line);
    string getAccum_jur(string line);
    string getAccum_num(string line);
    string getCifer(string line);
    string getCifer_jur(string line);
    
private:

};



#endif	/* PARSER_H */
