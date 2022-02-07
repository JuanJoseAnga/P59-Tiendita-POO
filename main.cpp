#include "principal.h"

#include <QApplication>

#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator traducion;
    // Solicitando al usuario que seleccione un idioma
    QStringList idiomas;
    idiomas << "Catalán"<<"Italiano"<< "Español";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                                       "Idioma",
                                                       "Seleccione un idioma",
                                                       idiomas);
    // Dependiendo del idioma seleccionado, carga el archivo de rtaducción
    if (idiomaSeleccionado == "Catalán"){
        traducion.load(":/principal_ca.qm");
    }
    // Dependiendo del idioma seleccionado, carga el archivo de rtaducción
    else if (idiomaSeleccionado == "Italiano"){
        traducion.load(":/principal_it.qm");
    }


    // Si es diferente de español, se instala la traducción en TODA la aplicación
    if (idiomaSeleccionado != "Español"){
        a.installTranslator(&traducion);
    }

    Principal w;
    w.show();

    return a.exec();
}
