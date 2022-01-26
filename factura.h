#ifndef FACTURA_H
#define FACTURA_H

#include <QDialog>

namespace Ui {
class Factura;
}

class Factura : public QDialog
{
    Q_OBJECT

public:
    explicit Factura(QWidget *parent = nullptr);
    ~Factura();

    void setDetalles(const QString &newdetalles)
    ;
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

private:
    Ui::Factura *ui;
    QString m_detalles;
    QString m_nobre;
    QString m_cedula;
    QString m_correo;
    QString m_telefono;
    QString m_direccion;

    void insertarDatos(QString nombre, QString cedula, QString telefono, QString correo, QString direccion );

    void muestra();

};

#endif // FACTURA_H
