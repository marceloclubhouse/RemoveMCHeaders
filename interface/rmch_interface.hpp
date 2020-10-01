//
// Created by Marcelo on 9/30/20.
//

#ifndef REMOVEMCHEADERS_RMCH_INTERFACE_HPP
#define REMOVEMCHEADERS_RMCH_INTERFACE_HPP

#include <string>
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
    void setInputFileLocation();
    void setOutputFileLocation();
    void setStatus(const std::string& status);

private slots:
    void selectFile();
    void removeHeaders();

};


#endif //REMOVEMCHEADERS_RMCH_INTERFACE_HPP
