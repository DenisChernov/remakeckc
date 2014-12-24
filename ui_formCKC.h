/********************************************************************************
** Form generated from reading UI file 'formCKC.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCKC_H
#define UI_FORMCKC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formCKC
{
public:
    QWidget *centralwidget;
    QGroupBox *gbJournalBefore2013;
    QListWidget *lwJournals;
    QComboBox *cbJournals;
    QGroupBox *gbJurNumsBefore2013;
    QComboBox *cbJurNums;
    QGroupBox *groupBox_3;
    QListWidget *lwJurNums_Before;
    QGroupBox *groupBox_4;
    QListWidget *lwJurNums_After;
    QGroupBox *gbControl;
    QLineEdit *leTotalJournals;
    QLabel *lblTotalJournals;
    QLabel *lblCurrentJournal;
    QLineEdit *leCurrentJournal;
    QPushButton *pbBegin;
    QPushButton *pbLeft;
    QPushButton *pbRight;
    QPushButton *pbEnd;
    QLineEdit *leTotalNums;
    QGroupBox *gbFlush;
    QPushButton *pbFlushJournals;
    QPushButton *pbFlushNumbers;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *formCKC)
    {
        if (formCKC->objectName().isEmpty())
            formCKC->setObjectName(QStringLiteral("formCKC"));
        formCKC->resize(1361, 775);
        centralwidget = new QWidget(formCKC);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gbJournalBefore2013 = new QGroupBox(centralwidget);
        gbJournalBefore2013->setObjectName(QStringLiteral("gbJournalBefore2013"));
        gbJournalBefore2013->setGeometry(QRect(10, 10, 521, 581));
        lwJournals = new QListWidget(gbJournalBefore2013);
        lwJournals->setObjectName(QStringLiteral("lwJournals"));
        lwJournals->setGeometry(QRect(10, 70, 501, 491));
        cbJournals = new QComboBox(gbJournalBefore2013);
        cbJournals->setObjectName(QStringLiteral("cbJournals"));
        cbJournals->setGeometry(QRect(10, 30, 501, 24));
        QFont font;
        font.setPointSize(8);
        cbJournals->setFont(font);
        gbJurNumsBefore2013 = new QGroupBox(centralwidget);
        gbJurNumsBefore2013->setObjectName(QStringLiteral("gbJurNumsBefore2013"));
        gbJurNumsBefore2013->setGeometry(QRect(540, 10, 811, 581));
        cbJurNums = new QComboBox(gbJurNumsBefore2013);
        cbJurNums->setObjectName(QStringLiteral("cbJurNums"));
        cbJurNums->setGeometry(QRect(20, 30, 781, 24));
        groupBox_3 = new QGroupBox(gbJurNumsBefore2013);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 70, 391, 501));
        lwJurNums_Before = new QListWidget(groupBox_3);
        lwJurNums_Before->setObjectName(QStringLiteral("lwJurNums_Before"));
        lwJurNums_Before->setGeometry(QRect(10, 30, 371, 461));
        groupBox_4 = new QGroupBox(gbJurNumsBefore2013);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(400, 70, 401, 501));
        lwJurNums_After = new QListWidget(groupBox_4);
        lwJurNums_After->setObjectName(QStringLiteral("lwJurNums_After"));
        lwJurNums_After->setGeometry(QRect(10, 30, 381, 461));
        gbControl = new QGroupBox(centralwidget);
        gbControl->setObjectName(QStringLiteral("gbControl"));
        gbControl->setGeometry(QRect(10, 600, 521, 101));
        leTotalJournals = new QLineEdit(gbControl);
        leTotalJournals->setObjectName(QStringLiteral("leTotalJournals"));
        leTotalJournals->setGeometry(QRect(73, 20, 113, 23));
        lblTotalJournals = new QLabel(gbControl);
        lblTotalJournals->setObjectName(QStringLiteral("lblTotalJournals"));
        lblTotalJournals->setGeometry(QRect(10, 24, 59, 15));
        lblCurrentJournal = new QLabel(gbControl);
        lblCurrentJournal->setObjectName(QStringLiteral("lblCurrentJournal"));
        lblCurrentJournal->setGeometry(QRect(190, 24, 71, 16));
        leCurrentJournal = new QLineEdit(gbControl);
        leCurrentJournal->setObjectName(QStringLiteral("leCurrentJournal"));
        leCurrentJournal->setGeometry(QRect(260, 20, 113, 23));
        pbBegin = new QPushButton(gbControl);
        pbBegin->setObjectName(QStringLiteral("pbBegin"));
        pbBegin->setGeometry(QRect(160, 70, 71, 24));
        pbLeft = new QPushButton(gbControl);
        pbLeft->setObjectName(QStringLiteral("pbLeft"));
        pbLeft->setGeometry(QRect(230, 70, 71, 24));
        pbRight = new QPushButton(gbControl);
        pbRight->setObjectName(QStringLiteral("pbRight"));
        pbRight->setGeometry(QRect(300, 70, 71, 24));
        pbEnd = new QPushButton(gbControl);
        pbEnd->setObjectName(QStringLiteral("pbEnd"));
        pbEnd->setGeometry(QRect(370, 70, 71, 24));
        leTotalNums = new QLineEdit(gbControl);
        leTotalNums->setObjectName(QStringLiteral("leTotalNums"));
        leTotalNums->setGeometry(QRect(73, 40, 113, 23));
        gbFlush = new QGroupBox(centralwidget);
        gbFlush->setObjectName(QStringLiteral("gbFlush"));
        gbFlush->setGeometry(QRect(540, 600, 401, 91));
        pbFlushJournals = new QPushButton(gbFlush);
        pbFlushJournals->setObjectName(QStringLiteral("pbFlushJournals"));
        pbFlushJournals->setGeometry(QRect(30, 40, 151, 24));
        pbFlushNumbers = new QPushButton(gbFlush);
        pbFlushNumbers->setObjectName(QStringLiteral("pbFlushNumbers"));
        pbFlushNumbers->setGeometry(QRect(220, 40, 151, 24));
        formCKC->setCentralWidget(centralwidget);
        menubar = new QMenuBar(formCKC);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1361, 21));
        formCKC->setMenuBar(menubar);
        statusbar = new QStatusBar(formCKC);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        formCKC->setStatusBar(statusbar);

        retranslateUi(formCKC);

        QMetaObject::connectSlotsByName(formCKC);
    } // setupUi

    void retranslateUi(QMainWindow *formCKC)
    {
        formCKC->setWindowTitle(QApplication::translate("formCKC", "\320\237\321\200\320\270\320\262\320\265\320\264\320\265\320\275\320\270\320\265 \320\241\320\232\320\241 \320\272 \320\275\320\276\320\262\320\276\320\274\321\203 \320\262\320\270\320\264\321\203", 0));
        gbJournalBefore2013->setTitle(QApplication::translate("formCKC", "\320\226\321\203\321\200\320\275\320\260\320\273\321\213 \320\264\320\276 2013\320\263", 0));
        gbJurNumsBefore2013->setTitle(QApplication::translate("formCKC", "\320\241\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\321\203\321\216\321\211\320\270\320\265 \320\275\320\276\320\274\320\265\321\200\320\260", 0));
        groupBox_3->setTitle(QApplication::translate("formCKC", "\320\224\320\276", 0));
        groupBox_4->setTitle(QApplication::translate("formCKC", "\320\237\320\276\321\201\320\273\320\265", 0));
        gbControl->setTitle(QApplication::translate("formCKC", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", 0));
        lblTotalJournals->setText(QApplication::translate("formCKC", "\320\222\321\201\320\265\320\263\320\276:", 0));
        lblCurrentJournal->setText(QApplication::translate("formCKC", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271:", 0));
        pbBegin->setText(QApplication::translate("formCKC", "\320\235\320\260\321\207\320\260\320\273\320\276", 0));
        pbLeft->setText(QApplication::translate("formCKC", "<==", 0));
        pbRight->setText(QApplication::translate("formCKC", "==>", 0));
        pbEnd->setText(QApplication::translate("formCKC", "\320\232\320\276\320\275\320\265\321\206", 0));
        gbFlush->setTitle(QApplication::translate("formCKC", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273\321\213", 0));
        pbFlushJournals->setText(QApplication::translate("formCKC", "\320\226\321\203\321\200\320\275\320\260\320\273\321\213", 0));
        pbFlushNumbers->setText(QApplication::translate("formCKC", "\320\235\320\276\320\274\320\265\321\200\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class formCKC: public Ui_formCKC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCKC_H
