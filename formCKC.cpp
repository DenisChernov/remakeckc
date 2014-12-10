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
    connect(frmCKC.cbJournals, SIGNAL(currentIndexChanged(QString)), this, SLOT(slot_jrnChoseByTitle(QString)));
    connect(frmCKC.cbJurNums, SIGNAL(currentIndexChanged(QString)), this, SLOT(slot_numsChoseByTitle(QString)));
    
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
    
    
    
    vector<string>::const_iterator it = itNums->fld_v910.begin();
    while (it != itNums->fld_v910.end())
    {
        frmCKC.lwJurNums_Before->addItem("#910: " + QString::fromStdString(it->data()));
        frmCKC.lwJurNums_After->addItem("#910: " + QString::fromStdString(pars.replaceCodDivision(it->data())));
        
        
        vector<string>::const_iterator it909 = itJurs->fld_v909.begin();
        while (it909 != itJurs->fld_v909.end())
        {
//            cout << pars.getNumber(itNums->cifer_jurnum) << endl;
//            cout << pars.getDivision(it->data()) << endl;
//            cout << pars.getYear(it->data()) << endl;
//            cout << pars.getYear(it909->data()) << endl;
        
            it909++;
        }

        
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
