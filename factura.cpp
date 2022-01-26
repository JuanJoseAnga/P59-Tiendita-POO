#include "factura.h"
#include "ui_factura.h"

Factura::Factura(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Factura)
{
    ui->setupUi(this);
}

Factura::~Factura()
{
    delete ui;
}

void Factura::setDetalles(const QString &newdetalles)
{
    m_detalles = newdetalles;

}

Ui::Factura *Factura::getUi() const
{
    return ui;
}

void Factura::setUi(Ui::Factura *newUi)
{
    ui = newUi;
}

const QString &Factura::detalles() const
{
    return m_detalles;
}

const QString &Factura::nobre() const
{
    return m_nobre;
}

void Factura::setNobre(const QString &newNobre)
{
    m_nobre = newNobre;
}

const QString &Factura::cedula() const
{
    return m_cedula;
}

void Factura::setCedula(const QString &newCedula)
{
    m_cedula = newCedula;
}

const QString &Factura::correo() const
{
    return m_correo;
}

void Factura::setCorreo(const QString &newCorreo)
{
    m_correo = newCorreo;
}

const QString &Factura::telefono() const
{
    return m_telefono;
}

void Factura::setTelefono(const QString &newTelefono)
{
    m_telefono = newTelefono;
}

const QString &Factura::direccion() const
{
    return m_direccion;
}

void Factura::setDireccion(const QString &newDireccion)
{
    m_direccion = newDireccion;
}

void Factura::insertarDatos(QString nombre, QString cedula, QString telefono, QString correo, QString direccion )
{
    setNobre(nombre);
    setCedula(cedula);
    setTelefono(telefono);
    setCorreo(correo);
    setDireccion(direccion);
    muestra();

}

void Factura::muestra()
{







}
