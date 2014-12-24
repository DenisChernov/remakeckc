/*
 * File:   formCKC.cpp
 * Author: demiin
 *
 * Created on December 6, 2014, 11:27 AM
 */

#include "formCKC.h"
#include "parser.h"

formCKC::formCKC() {
    frmCKC.setupUi(this);
    connect(frmCKC.pbBegin, SIGNAL(clicked()), this, SLOT(slot_pbBegin()));
    connect(frmCKC.pbLeft, SIGNAL(clicked()), this, SLOT(slot_pbLeft()));
    connect(frmCKC.pbRight, SIGNAL(clicked()), this, SLOT(slot_pbRight()));
    connect(frmCKC.pbEnd, SIGNAL(clicked()), this, SLOT(slot_pbEnd()));
    connect(frmCKC.pbFlushJournals, SIGNAL(clicked()), this, SLOT(slot_flushJournals()));
    connect(frmCKC.pbFlushNumbers, SIGNAL(clicked()), this, SLOT(slot_flushNumbers()));
    connect(frmCKC.cbJournals, SIGNAL(currentIndexChanged(QString)), this, SLOT(slot_jrnChoseByTitle(QString)));
    connect(frmCKC.cbJurNums, SIGNAL(currentIndexChanged(QString)), this, SLOT(slot_numsChoseByTitle(QString)));
    connect(frmCKC.lwJournals, SIGNAL(currentRowChanged(int)), this, SLOT(slot_lwrowChanged(int)));
    searchAndLoadBDFiles();

}

formCKC::~formCKC() {
}



void formCKC::searchAndLoadBDFiles() 
{
    
    for (size_t i = 0; i < sizeof(bdFiles) / sizeof(*bdFiles); i++)
    {
        engn.loadBDFile(bdFiles[i]);
    }
    
    frmCKC.leTotalJournals->setText(QString::number(engn.jurs.size()));
    frmCKC.leTotalNums->setText(QString::number(engn.jurnums.size()));
    loadJursList();
}

void formCKC::loadJursList() 
{
    itJurs = engn.jurs.begin();
    while(itJurs != engn.jurs.end())
    {
        frmCKC.cbJournals->addItem(QString::fromStdString(itJurs->title));
        itJurs++;
    }
}


void formCKC::slot_pbBegin() 
{
    engn.msg.print(EINFO, "Начало файла");
    engn.currentRec = 1;
    frmCKC.pbBegin->setEnabled(false);
    frmCKC.pbEnd->setEnabled(true);
    frmCKC.pbLeft->setEnabled(false);
    frmCKC.pbRight->setEnabled(true);
    itJurs_setBegin();
    loadRecord();
    frmCKC.leCurrentJournal->setText("1");
    frmCKC.cbJournals->setCurrentIndex(frmCKC.leCurrentJournal->text().toInt() - 1);
    //doRecord();
}

void formCKC::slot_pbEnd() {
    engn.msg.print(EINFO, "Конец файла");
    engn.currentRec = engn.jurs.size();
    frmCKC.pbBegin->setEnabled(true);
    frmCKC.pbLeft->setEnabled(true);
    frmCKC.pbRight->setEnabled(false);
    frmCKC.pbEnd->setEnabled(false);
    itJurs_setEnd();
    loadRecord();
    frmCKC.leCurrentJournal->setText(QString::number(engn.jurs.size()));
    frmCKC.cbJournals->setCurrentIndex(engn.currentRec-1);
    frmCKC.cbJournals->setCurrentIndex(frmCKC.leCurrentJournal->text().toInt() - 1);
    //doRecord(); 
}

void formCKC::slot_pbLeft() {
    engn.msg.print(EINFO, "Сдвиг влево. Текущая запись: " + QString::number(--engn.currentRec).toStdString());
    if (engn.currentRec < engn.jurs.size())
    {
        frmCKC.pbRight->setEnabled(true);
        frmCKC.pbEnd->setEnabled(true);
    }
    else
        frmCKC.pbEnd->setEnabled(false);
    
    if (engn.currentRec == 1)
    {
        frmCKC.pbLeft->setEnabled(false);
        frmCKC.pbBegin->setEnabled(false);
    }
    itJurs--;
    loadRecord();
    frmCKC.leCurrentJournal->setText(QString::number(frmCKC.leCurrentJournal->text().toInt() - 1));
    frmCKC.cbJournals->setCurrentIndex(frmCKC.leCurrentJournal->text().toInt() - 1);
    //doRecord();   
}

void formCKC::slot_pbRight() 
{
    engn.msg.print(EINFO, "Сдвиг вправо. Текущая запись: " + QString::number(++engn.currentRec).toStdString());
    if (engn.currentRec == engn.jurs.size())
    {
        frmCKC.pbRight->setEnabled(false);
        frmCKC.pbEnd->setEnabled(false);
    }
    else
    {
        frmCKC.pbLeft->setEnabled(true);
        frmCKC.pbBegin->setEnabled(true);
    }  
    itJurs++;
    loadRecord();    
    //doRecord();
    frmCKC.leCurrentJournal->setText(QString::number(frmCKC.leCurrentJournal->text().toInt() + 1));
    frmCKC.cbJournals->setCurrentIndex(frmCKC.leCurrentJournal->text().toInt() - 1);
}

void formCKC::loadRecord() 
{
    frmCKC.lwJournals->clear();
    vector<string>::const_iterator itJurs_fld = itJurs->restFields.begin();
    while (itJurs_fld != itJurs->restFields.end())
    {
        frmCKC.lwJournals->addItem(QString::fromStdString(itJurs_fld->data()));
        itJurs_fld++;
    }
    itJurs_fld = itJurs->fld_v909.begin();
    while (itJurs_fld != itJurs->fld_v909.end())
    {
        frmCKC.lwJournals->addItem("#909: " + QString::fromStdString(itJurs_fld->data()));
        itJurs_fld++;
    }
}

void formCKC::slot_jrnChoseByTitle(QString title)
{
    itJurs_setBegin();
    engn.currentRec = 1;
    while (itJurs != engn.jurs.end())
    {
        if (itJurs->title == title.toStdString())
        {
            loadRecord();
            break;
        }
        engn.currentRec++;
        itJurs++;
    }
    frmCKC.leCurrentJournal->setText(QString::number(engn.currentRec));
    loadNumsList();
}

void formCKC::loadNumsList() 
{
    frmCKC.cbJurNums->clear();
    itJursNums = engn.jurs.begin();
    while (itJursNums != engn.jurs.end())
    {
        if (frmCKC.cbJournals->currentText().toStdString() == itJursNums->title)
        {
           
            vector<jurnum>::const_iterator  itNums = engn.jurnums.begin();
            while (itNums != engn.jurnums.end())
            {
                if (itNums->cifer == itJursNums->cifer)
                {
                    frmCKC.cbJurNums->addItem(QString::fromStdString(itNums->cifer_jurnum));
                }
                itNums++;
            }
            break;
        }
        
        itJursNums++;
    }
}

void formCKC::slot_numsChoseByTitle(QString title) 
{
    itNums = engn.jurnums.begin();
    while (itNums != engn.jurnums.end())
    {
        if (itNums->cifer_jurnum == title.toStdString())
        {
            loadNum();
            break;
        }
        itNums++;
    }
    
//    loadNum_Before();
}

void formCKC::loadNum() 
{
    parser pars;
    frmCKC.lwJurNums_Before->clear();
    frmCKC.lwJurNums_After->clear();
    frmCKC.lwJurNums_Before->addItem("#933: " + QString::fromStdString(itNums->cifer));
    frmCKC.lwJurNums_After->addItem("#933: " + QString::fromStdString(itNums->cifer));
    frmCKC.lwJurNums_Before->addItem("#903: " + QString::fromStdString(itNums->cifer_jurnum));
    frmCKC.lwJurNums_After->addItem("#903: " + QString::fromStdString(itNums->cifer_jurnum));
    
    if (itNums->fld_v910.size() == 0)
    {
//        cout << "заполняем" << endl;
        vector<string>::const_iterator it909 = itJurs->fld_v909.begin();
        while (it909 != itJurs->fld_v909.end())
        {
//            cout << pars.getYear(it909->data()) << "              " << pars.getYear(itNums->cifer_jurnum) << endl;
                if (pars.getYear(it909->data()) == pars.getYear(itNums->cifer_jurnum))
                {
                        vector<string> range = pars.remakeRange(pars.getAccum_jur_h(it909->data()));
                        vector<string>::const_iterator itRange = range.begin();
                        bool inRange = false;
                        while (itRange != range.end())
                        {
                                if (itRange->data() == pars.getNumber(itNums->cifer_jurnum))
                                {
                                        inRange = true;
                                        break;
                                }
                                itRange++;
                        }
                        if (inRange)
                        {
                            string line = "#910: ^A0^B" + pars.filialToNumber(pars.getYear(itNums->cifer_jurnum)) +"^C" + pars.getYear(it909->data()) + "^D" + pars.getDivision(it909->data());
                            frmCKC.lwJurNums_After->addItem(QString::fromStdString("add - " + line));
                        }
                }
            
            it909++;
        }
    }        
        
    
    vector<string>::const_iterator it = itNums->fld_v910.begin();
    while (it != itNums->fld_v910.end())
    {
        frmCKC.lwJurNums_Before->addItem("#910: " + QString::fromStdString(it->data()));
        frmCKC.lwJurNums_After->addItem("#910: " + QString::fromStdString(pars.replaceCodDivision(it->data())));
        vector<string>::const_iterator it909 = itJurs->fld_v909.begin();
        bool alreadyIn = false;
        string line = "#910: ^A0^B" + pars.filialToNumber(pars.getDivision(it->data())) +
                                "^C" + pars.getYear(it->data()) + "^D" + pars.getDivision(it->data());        
        while (it909 != itJurs->fld_v909.end())
        {

            vector<string> range = pars.remakeRange(pars.getAccum_jur_h(it909->data()));
            vector<string>::const_iterator itRange = range.begin();

            
            if (pars.getYear(it909->data()) == pars.getYear(it->data()))
            {
                bool inRange = false;
                while (itRange != range.end())
                {
                    if (itRange->data() == pars.getNumber(itNums->cifer_jurnum))
                    {
                        inRange = true;
                        break;
                     }
                     itRange++;
                }
                if (inRange)
               {

//                    cout << "----- из журнала: " << it909->data() << "\nиз номера: " << pars.getNumber(itNums->cifer_jurnum) << "                       строка в номере: " << it->data() << endl;
                    string jrnLine = "^A0^B" + pars.filialToNumber(pars.getDivision(it909->data()))  + "^C" + pars.getYear(it909->data()) + "^D" + pars.getDivision(it909->data());
//                    cout << jrnLine << "                           " << it->data() << endl;
                    if (jrnLine == it->data())
                        alreadyIn = true;
                    
                }
            
            }        
 //           cout << "******" << endl;

            it909++;

        }
        if (!alreadyIn)
                        frmCKC.lwJurNums_After->addItem(QString::fromStdString("add - " + line));

        it++;
        
    }
    
    it = itNums->restFields.begin();
    while (it != itNums->restFields.end())
    {
        frmCKC.lwJurNums_Before->addItem(QString::fromStdString(it->data()));
        frmCKC.lwJurNums_After->addItem(QString::fromStdString(it->data()));
        it++;
    }

}

void formCKC::slot_lwrowChanged(int row) 
{
 /*   parser pars;
    pair<FIELD_CODE, string> result = pars.checkFld(frmCKC.lwJournals->item(row)->text().toStdString());
    switch (result.first)
    {
        case  FIELD_909:
        {
            //cout << result.second << endl;
            //TODO:
            // какую нить обработку и действие на это
            
            break;
        }
        default:
        {
            break;
        }
        
    }
  */ 
}

void formCKC::slot_flushJournals() 
{
    msgs msg;
    parser pars;
    msg.print(EINFO, "Начинаю сбрасывать журналы");
    f.fWOpen("jrn_new.txt");
    vector<jur>::const_iterator itFlush =  engn.jurs.begin();
    while (itFlush != engn.jurs.end())
    {
        f.writeLine("#200: ^A" + itFlush->title + "\r");
        f.writeLine("#903: " + itFlush->cifer + "\r");
        vector<string>::const_iterator it = itFlush->cifer_month_jurnum.begin();
        while(it != itFlush->cifer_month_jurnum.end())
        {
            f.writeLine(string(it->data()) + "\r");
            it++;
        }

        it = itFlush->restFields.begin();
        while(it != itFlush->restFields.end())
        {
            f.writeLine(string(it->data()) + "\r");
            it++;
        }
        
        it = itFlush->fld_v909.begin();
        while(it != itFlush->fld_v909.end())
        {
            //cout << it->data();
            f.writeLine("#909: " + pars.replaceRange(it->data()) + "\r");
            it++;
        }
        
        f.writeLine("*****\r");
        itFlush++;
    }
    msg.print(EINFO, "Окончание сброса журналов");
    f.fClose();
}

void formCKC::slot_flushNumbers() 
{
    msgs msg;
    parser pars;
    msg.print(EINFO, "Начинаю сбрасывать номера журналов");
    f.fWOpen("jurnum_new.txt");
    vector<jurnum>::const_iterator itFlush =  engn.jurnums.begin();
    while (itFlush != engn.jurnums.end())
    {
        f.writeLine("#933: " + itFlush->cifer + "\r");
        f.writeLine("#903: " + itFlush->cifer_jurnum + "\r");
        vector<string>::const_iterator it = itFlush->restFields.begin();
        while (it != itFlush->restFields.end())
        {
            f.writeLine(string(it->data()) + "\r");
            it++;
        }
       
        vector<jur>::const_iterator itJurs = engn.jurs.begin();
        while (itJurs != engn.jurs.end())
        {
            if (itJurs ->cifer == itFlush->cifer)
                break;
            itJurs++;
        }
        
    if (itFlush->fld_v910.size() == 0)
        {
//        cout << "заполняем" << endl;
        vector<string>::const_iterator it909 = itJurs->fld_v909.begin();
        while (it909 != itJurs->fld_v909.end())
        {
//            cout << pars.getYear(it909->data()) << "              " << pars.getYear(itNums->cifer_jurnum) << endl;
                if (pars.getYear(it909->data()) == pars.getYear(itNums->cifer_jurnum))
                {
                        vector<string> range = pars.remakeRange(pars.getAccum_jur_h(it909->data()));
                        vector<string>::const_iterator itRange = range.begin();
                        bool inRange = false;
                        while (itRange != range.end())
                        {
                                if (itRange->data() == pars.getNumber(itNums->cifer_jurnum))
                                {
                                        inRange = true;
                                        break;
                                }
                                itRange++;
                        }
                        if (inRange)
                        {
                            string line = "#910: ^A0^B" + pars.filialToNumber(pars.getYear(itNums->cifer_jurnum)) +"^C" + pars.getYear(it909->data()) + "^D" + pars.getDivision(it909->data());
                            f.writeLine(line + "\r");
                        }
                }
            
            it909++;
        }
    }        
        

        
    it = itFlush->fld_v910.begin();
    while (it != itFlush->fld_v910.end())
    {
        vector<string>::const_iterator it909 = itJurs->fld_v909.begin();
        string line = "#910: ^A0^B" + pars.filialToNumber(pars.getDivision(it->data())) +
                                "^C" + pars.getYear(it->data()) + "^D" + pars.getDivision(it->data());        
        while (it909 != itJurs->fld_v909.end())
        {

            vector<string> range = pars.remakeRange(pars.getAccum_jur_h(it909->data()));
            vector<string>::const_iterator itRange = range.begin();

//          cout << pars.getYear(it909->data()) << "       " << pars.getYear(it->data()) << endl;
            if (pars.getYear(it909->data()) == pars.getYear(it->data()))
            {
/*                cout << it909->data() << endl;
                cout << it->data() << endl;
                cout << "bingo" << endl;*/
                bool inRange = false;
                while (itRange != range.end())
                {
                    if (itRange->data() == pars.getNumber(itFlush->cifer_jurnum))
                    {
                        inRange = true;
                        break;
                     }
                     itRange++;
                }
                if (inRange)
               {
//                    cout << "in range!" << endl;
                    string jrnLine = "^A0^B" + pars.filialToNumber(pars.getDivision(it909->data()))  + "^C" + pars.getYear(it909->data()) + "^D" + pars.getDivision(it909->data());
//                    cout << pars.getYear(it909->data())<< "   " << pars.getYear(it->data()) << "                       " <<  pars.getDivision(it909->data()) << "    " << pars.getDivision(it->data()) << endl;
                    if ((pars.getYear(it909->data()))== pars.getYear(it->data()) && (pars.getDivision(it909->data()) == pars.getDivision(it->data())))
                    {
                        f.writeLine(line + "\r");
 //                       cout << "will add" << endl;
                    }
                }
            }        
            it909++;

        }
//        if (!alreadyIn)
//            f.writeLine("#910: " + line);

        it++;
        
    }

        
        f.writeLine("*****\r");
        itFlush++;
    }
    msg.print(EINFO, "Окончание сброса  номеров журналов");
    f.fClose();
}

