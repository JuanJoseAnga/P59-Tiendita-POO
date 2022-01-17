#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

#include "producto.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private:
    Ui::Principal *ui;
    QList <Producto*> m_productos;
    void cargarProducto();
};
#endif // PRINCIPAL_H
