#ifndef FACTURA_H
#define FACTURA_H

#include <QDialog>
#include <QtDebug>
#include <QDateTime>
#include <QFile>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
class Factura;
}

class Factura : public QDialog
{
    Q_OBJECT

public:
    explicit Factura(QWidget *parent = nullptr);
    ~Factura();

    void setDetalles(const QString &newdetalles);
    Ui::Factura *getUi() const;
    void setUi(Ui::Factura *newUi);
    const QString &detalles() const;
    const QString &nobre() const;
    void setNobre(const QString &newNobre);
    const QString &cedula() const;
    void setCedula(const QString &newCedula);
    const QString &correo() const;
    void setCorreo(const QString &newCorreo);
    const QString &telefono() const;
    void setTelefono(const QString &newTelefono);
    const QString &direccion() const;
    void setDireccion(const QString &newDireccion);

    void insertarDatos(QString nombre, QString cedula, QString telefono, QString correo, QString direccion );

    void setProducts(const QString &newProducts);

    void totales(QString subTotal, QString iva, QString total);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Factura *ui;
    QString m_detalles;
    QString m_nombre;
    QString m_cedula;
    QString m_correo;
    QString m_telefono;
    QString m_direccion;

    QString m_products;


    void impresion();

};

#endif // FACTURA_H
