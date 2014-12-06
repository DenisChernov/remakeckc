/* 
 * File:   engine.cpp
 * Author: demiin
 * 
 * Created on December 6, 2014, 11:53 AM
 */

#include "engine.h"
#include "parser.h"

engine::engine() {
    
}



engine::~engine() {
}

void engine::processBD() 
{

}



void engine::loadBDFile(string filename) {
    vector<string> record;
    parser pars;
    
    getTotal(filename);
    
    f.fROpen(filename);
    if (filename.find("num", 0) != string::npos)
    {
        while (currentRec <= total)
        {
            jurnum nums;
            record = readRecord();
            vector<string>::const_iterator it = record.end();
            while (it != record.end())
            {
                pair<FIELD_CODE, string> result = pars.checkFld(it->data());
                switch (result.first)
                {
                    case FIELD_910:
                    {
                        nums.fld_v910.push_back(pars.getAccum_num(result.second));
                        break;
                    }
                    
                    case FIELD_CIFER:
                    {
                        nums.cifer = pars.getCifer_jur(result.second);
                        break;
                    }
                    
                    case FIELD_CIFER_NUM:
                    {
                        nums.cifer_jurnum = pars.getCifer(result.second);
                        break;
                    }
                    
                    case REST_FIELD:
                    {
                        nums.restFields.push_back(result.second);
                        break;
                    }
                }
                it++;
            }
            jurnums.push_back(nums);
        }
    }
    else
    {
        while (currentRec <= total)
        {
            jur curJur;
            record = readRecord();
            vector<string>::const_iterator it = record.begin();
            while (it != record.end()) 
            {
                pair<FIELD_CODE, string> result = pars.checkFld(it->data());
                switch (result.first)
                {
                    case FIELD_TITLE:
                    {
                        curJur.title = pars.getTitle(result.second);
                        break;
                    }
                    case FIELD_909:
                    {
                        curJur.fld_v909.push_back(pars.getAccum_jur(result.second));
                        break;
                    }
                    case FIELD_CIFER:
                    {
                        curJur.cifer = pars.getCifer(result.second);
                        break;
                    }
                    case REST_FIELD:
                    {
                        curJur.restFields.push_back(result.second);
                        break;
                    }
                }
                it++;
            }
            
            jurs.push_back(curJur);
        }
    }
    f.fClose();
}

vector<string> engine::readRecord() 
{
    vector<string> record;
    string line;
    if (f.isOpen_read())
    {
        f.readline(&line);
        while (line.find("*****") == string::npos)
        {
            
            record.push_back(line.replace(line.length() - 1, 1, ""));
            f.readline(&line);
        }
        
        currentRec++;
    }
    else
        msg.print(EFATAL, "file closed");
    
    return record;
}

void engine::getTotal(string filename) 
{
    f.fROpen(filename);
    string line = "";
    while (!f.atEnd())
    {
        f.readline(&line);
        if (line.find("*****") == 0)
            total++;
    }
    
    f.fClose();
}

