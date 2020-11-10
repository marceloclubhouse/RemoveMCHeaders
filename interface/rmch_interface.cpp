/*
 * Remove MC Headers
 * Copyright (c) 2020 Marcelo Cubillos
 * Licensed under the GPLv3, view LICENSE.txt for more information.
 *
 * 2020/09/30 - First revision
 * 2020/10/01 - Placed I/O within try and catch blocks, added conditionals to
 *              prevent misuse/crashing of software if it isn't used right.
 * 2020/11/03 - Added boolean to correct removal algorithm so files can be
 *              replaced (i.e. input file == output file)
 *
 * rmch_interface.cpp - The main interface object that inherits the QT-generated
 *                      UI and links the elements to methods.
 */

#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
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

void RMCHInterface::selectInputFileLocation()
{
    // Prompt the user to select the input HTML file through
    // a file dialog
    inputFileLocation = QFileDialog::getOpenFileName(this, tr("Open HTML File"), "", tr("HTML Files (*.html)"));
}

void RMCHInterface::selectOutputFileLocation()
{
    // Prompt the user to save a new HTML file with the headers
    // removed, using a file dialog
    outputFileLocation = QFileDialog::getSaveFileName(this, tr("Save HTML File"), "", tr("HTML Files (*.html)"));
}

void RMCHInterface::setStatus(const std::string& status)
{
    // Set the status of the software by changing the text
    // of the status label within the UI
    ui.label_status->setText(QString::fromStdString(status));
}

void RMCHInterface::selectFile()
{
    this->selectInputFileLocation();
    if(inputFileLocation != "") {
        ui.lineEdit_location->setText(inputFileLocation);
        this->setStatus("Click remove headers to save the new file.");
    }
}

void RMCHInterface::removeHeaders()
{
    // Given the file location from ui.lineEdit_location, generate
    // a new file that doesn't contain the MC headers and prompt
    // the user to save that new file.

    inputFileLocation = ui.lineEdit_location->text();

    // Verify that the location specified in ui.lineEdit_location is
    // valid.
    if(inputFileLocation.toStdString() == "")
    {
        this->setStatus("Input file must be specified.");
        return;
    }
    else
    {
        try
        {
            if(inputFileLocation.toStdString().substr(inputFileLocation.toStdString().length() - 5) != ".html")
            {
                this->setStatus("Input file must be HTML");
                return;
            }
        }
        catch(const std::out_of_range&)
        {
            this->setStatus("Input file must be HTML");
            return;
        }
    }

    // Begin I/O
    try
    {
        this->selectOutputFileLocation();
        if(outputFileLocation == "")
        {
            return;
        }

        if(outputFileLocation == inputFileLocation)
        {
            setStatus("New file must have different name than first.");
            return;
        }

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
                outputFile << inputLine + "\n";
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
