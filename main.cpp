/*
 * File:   main.cpp
 * Author: demiin
 *
 * Created on December 4, 2014, 4:43 PM
 */

#include <QApplication>
#include "formCKC.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    // create and show your widgets here

    formCKC ckc;
    ckc.show();
    
    return app.exec();
}
