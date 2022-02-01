#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

#include "producto.h"
#include "factura.h"
#include "acerca.h"

#define IVA 12
#define VERSION "1.0"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

    bool verCedula(QString as);

    bool checkDatos();

private slots:

    void on_inProducto_currentIndexChanged(int index);

    void on_btnAgregar_released();

    void on_btnLimpiar_released();

    void on_btnFinalizar_released();

    void on_actionAcerca_de_2_triggered();

private:
    Ui::Principal *ui;
    QList <Producto*> m_productos;
    void cargarProducto();
    void limpiar();

    float m_subtotal;

    void calcular(float stProducto);
};
#endif // PRINCIPAL_H
