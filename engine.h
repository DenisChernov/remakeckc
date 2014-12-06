/* 
 * File:   engine.h
 * Author: demiin
 *
 * Created on December 6, 2014, 11:53 AM
 */

#ifndef ENGINE_H
#define	ENGINE_H

#include <iostream>
#include <vector>
#include "fOper.h"
#include "msgs.h"

using namespace std;

struct jur
{
    vector<string> restFields;
    vector<string> fld_v909;
    vector<string> cifer_month_jurnum;
    string cifer;
    string title;
};

struct jurnum
{
    string cifer;
    string cifer_jurnum;
    vector<string> fld_v910;
    vector<string> restFields;
};


class engine {
public:
    engine();
    virtual ~engine();
    void processBD();
    void loadBDFile(string filename);
    vector<jur> jurs;
    vector<jurnum> jurnums;
    size_t currentRec = 1;
    size_t total = 0;
    
    fOper f;
    msgs msg;
    
    
private:
    vector<string> readRecord();
    void getTotal(string filename);
};

#endif	/* ENGINE_H */

