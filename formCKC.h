/* 
 * File:   formCKC.h
 * Author: demiin
 *
 * Created on December 6, 2014, 11:27 AM
 */

#ifndef _FORMCKC_H
#define	_FORMCKC_H

#include <iostream>

#include "ui_formCKC.h"
#include "fOper.h"
#include "msgs.h"
#include "boost/thread.hpp"
#include "boost/lexical_cast.hpp"
#include "engine.h"

using namespace std;

class formCKC : public QMainWindow {
    Q_OBJECT
public:
    formCKC();
    virtual ~formCKC();
    
    void searchAndLoadBDFiles();
    
    
    
    fOper f;
    string bdFiles[2] = {"jur.txt", "jurnum.txt"};
    engine engn;
    void itJurs_setBegin(){itJurs = engn.jurs.begin();};
    void itJurs_setEnd(){itJurs = engn.jurs.end();};
    
private:
    Ui::formCKC frmCKC;
    vector<jur>::const_iterator itJurs;
    vector<jurnum>::const_iterator itNums;
    vector<jur>::const_iterator itJursNums;
    
    
    void loadJursList();
    void loadNumsList();
    void loadNum_Before();
    void loadRecord();
    void loadRecord_num();
    

private slots:
    void slot_pbBegin();
    void slot_pbLeft();
    void slot_pbRight();
    void slot_pbEnd();
    void slot_jrnChoseByTitle(QString);
    void slot_numsChoseByTitle(QString);
};

#endif	/* _FORMCKC_H */
