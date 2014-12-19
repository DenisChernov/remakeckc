/*
 * File:   main.cpp
 * Author: demiin
 *
 * Created on December 4, 2014, 4:43 PM
 */

#include <QApplication>
#include "formCKC.h"
#include "parser.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    
    std::ios::sync_with_stdio(false);
    QApplication app(argc, argv);
    
    // create and show your widgets here

    formCKC ckc;
    ckc.show();
    
    parser pars;
    //cout << "7- 12           ->           " << pars.remakeRange("7- 12") << endl;;
    //cout << "1-7,1 -2   (с/в)        ->   " << pars.remakeRange("1-7,1 -2   (с/в)") << endl;
    //cout << "1-12,6с/в,1с/в-3с/в,2с/в,4с/в        ->   " << pars.remakeRange("1-12,6с/в,1с/в-3с/в,2с/в,4с/в") << endl;
    //cout << "4,5,7-8,11,12,11 спец. № 3-4        ->   " << pars.remakeRange("4,5,7-8,11,12,11 спец. № 3-4") << endl;

    
    return app.exec();
}
