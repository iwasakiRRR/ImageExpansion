#include "imageexpansion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainDialog* dialog = new MainDialog;
    dialog->show();
    dialog->exec();//event roop
    ImageExpansion w;
    w.show();
    return app.exec();
}
