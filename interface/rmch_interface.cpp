//
// Created by Marcelo on 9/30/20.
//

#include <fstream>
#include <iostream>
#include <string>
#include <QFileDialog>
#include "rmch_interface.hpp"

RMCHInterface::RMCHInterface(QDialog *parent)
        : QDialog(parent)
{
    ui.setupUi(this);

    // Remove QT's automatic-connection-naming-
    // conventions in favor of manually, explicitly
    // connecting methods to UI elements
    ui.pushButton_browse->setAutoDefault(false);
    ui.pushButton_remove->setAutoDefault(false);

    // Connect buttons to member functions
    connect(ui.pushButton_browse, SIGNAL(clicked()), this, SLOT(selectFile()));
    connect(ui.pushButton_remove, SIGNAL(clicked()), this, SLOT(removeHeaders()));

    // Declare MC Headers criteria
    headers.push_back("<meta charset=\"UTF-8\">");
    headers.push_back("<title>*|MC:SUBJECT|*</title>");
    headers.push_back("<!--*|IF:MC_PREVIEW_TEXT|*-->");
    headers.push_back("*|MC_PREVIEW_TEXT|*");
}

void RMCHInterface::setInputFileLocation()
{
    inputFileLocation = QFileDialog::getOpenFileName(this, tr("Open HTML File"), "", tr("HTML Files (*.html)"));
}

void RMCHInterface::setOutputFileLocation()
{
    outputFileLocation = QFileDialog::getSaveFileName(this, tr("Save HTML File"), "", tr("HTML Files (*.html)"));
}

void RMCHInterface::setStatus(const std::string& status)
{
    ui.label_status->setText(QString::fromStdString(status));
}

void RMCHInterface::selectFile()
{
    this->setInputFileLocation();
    if(inputFileLocation != "") {
        ui.lineEdit_location->setText(inputFileLocation);
        this->setStatus("Click remove headers to save the new file.");
    }
}

void RMCHInterface::removeHeaders()
{
    try
    {
        this->setOutputFileLocation();
        std::ofstream outputFile(outputFileLocation.toStdString());
        std::ifstream inputFile(inputFileLocation.toStdString());
        std::string inputLine;
        bool contains;
        while (std::getline(inputFile, inputLine))
        {
            contains = false;
            for(std::string s : headers)
            {
                if(inputLine.find(s) != std::string::npos)
                {
                    contains = true;
                }
            }
            if(!contains)
            {
                outputFile << inputLine;
            }
        }

        inputFile.close();
        outputFile.close();

        this->setStatus("Headers successfully removed!");
    }
    catch(const std::runtime_error& re)
    {
        std::cerr << "Runtime error: " << re.what() << std::endl;
    }
    catch(const std::exception& ex)
    {
        std::cerr << "Error occurred: " << ex.what() << std::endl;
    }
    catch(...)
    {
        std::cerr << "Unknown failure occurred." << std::endl;
    }

}
