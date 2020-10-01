/*
 * Remove MC Headers
 * Copyright (c) 2020 Marcelo Cubillos
 * Licensed under the GPLv3, view LICENSE.txt for more information.
 *
 * 2020/09/30 - First revision
 * 2020/10/01 - Placed I/O within try and catch blocks, added conditionals to
 *              prevent misuse/crashing of software if it isn't used right.
 *
 * rmch_interface.hpp - The main interface object that inherits the QT-generated
 *                      UI and links the elements to methods.
 */

#ifndef REMOVEMCHEADERS_RMCH_INTERFACE_HPP
#define REMOVEMCHEADERS_RMCH_INTERFACE_HPP

#include "../qt/main_window.hpp"

class RMCHInterface : public QDialog
{
    Q_OBJECT

public:
    explicit RMCHInterface(QDialog *parent = nullptr);

private:
    Ui::Dialog ui;
    QString inputFileLocation;
    QString outputFileLocation;
    std::vector<std::string> headers;

private:
    void selectInputFileLocation();
    void selectOutputFileLocation();
    void setStatus(const std::string& status);

private slots:
    void selectFile();
    void removeHeaders();

};


#endif //REMOVEMCHEADERS_RMCH_INTERFACE_HPP
