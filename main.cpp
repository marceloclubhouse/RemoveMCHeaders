/*
 * Remove MC Headers
 * Copyright (c) 2020 Marcelo Cubillos
 * Licensed under the GPLv3, view LICENSE.txt for more information.
 *
 * 2020/09/30 - First revision
 *
 * main.cpp - Launches an instance of the RMCH interface and sets
 *            the style to OS-agnostic.
 */

#include <QQuickStyle>
#include <QStyleFactory>
#include "interface/rmch_interface.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDialog *widget = new RMCHInterface;

    // Set the GUI to be OS-agnostic
    widget->setStyle(QStyleFactory::create("Fusion"));
    // Unless a stylesheet is specified (as a non-empty string),
    // the fusion style won't activate
    widget->setStyleSheet(" ");

    widget->show();
    return app.exec();
}
