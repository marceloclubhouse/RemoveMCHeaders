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
