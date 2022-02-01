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
    return m_nombre;
}

void Factura::setNobre(const QString &newNobre)
{
    m_nombre = newNobre;
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
    impresion();

}

void Factura::setProducts(const QString &newProducts)
{
    m_products = newProducts;
}

void Factura::totales(QString subTotal, QString iva, QString total)
{
    QString forma= "";
    forma += "\n\t\t\t\tSubTotal:         " + subTotal + "\n"
             "\t\t\t\tIVA (12%):       " + iva + "\n" +
             "\t\t\t\tTOTAL:            " + total;

    ui->outFactura->appendPlainText(forma);

}

void Factura::impresion()
{

    QString ss;
    QString encabezado= " \t //////////////////////////////////////////////////////////////////////////// \n"
                        " \t\tTIENDITA --HASTA LA VUELTA SEÑOR--\n"
                        " \t \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n"
                        " \tRUC: 9999999999\n"
                        " \tDireccion: Humberto Albornoz Oe11-261 y Pasaje Navarro\n"
                        " \tNumero: (02) 320-1833\n"
                        " \t  ---      ---     ---     ---     ---     ---     ---     ---     ---     ---      ---     \n"
                        " \t                                       CLIENTE\n"
                        " \t  ---      ---     ---     ---     ---     ---     ---     ---     ---     ---      ---     \n\n";
    ss=encabezado;
    if(m_cedula!="9999999999"){
        QString name="\tNombre:   "+m_nombre+"\n";
        QString cedu="\tCedula:   "+m_cedula+"\n";
        QString tele="\tTelefono:   "+m_telefono+"\n";
        QString corr="\tCorreo:   "+m_correo+"\n";
        QString dire="\tDirección:   "+m_direccion+"\n" +
                "\n\t  ---      ---     ---     ---     ---     ---     ---     ---     ---     ---      ---     ";

        ss+=name+cedu+tele+corr+dire+"\n"+"\n";
    }
    else {
        QString sd="\t\tCONSUMIDOR FINAL\n\n\t///////////////////////////////////////////////////////////\n";
        ss+=sd;
    }
    QString lol;
    lol="\tCantidad              Producto              P.Unitario              Subtotal\n\n" + m_products;
    ss+=lol;

    ui->outFactura->setPlainText(ss);
}

void Factura::on_buttonBox_accepted()
{
    QString fecha = QDateTime::currentDateTime().toString("ddMMyyyy");
    QFile archivo (fecha+".txt");
    if(archivo.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream datos_Archivo(&archivo);
        datos_Archivo<<ui->outFactura->toPlainText();

    }
    else {
        QMessageBox::warning(this,
                             "Guardar datos",
                             "No se pudo guardar el archivo");
    }
    archivo.close();
}

