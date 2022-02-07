#include "principal.h"
#include "ui_principal.h"

#include <QDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    ui->inTelefono->setValidator(new QIntValidator(0, 999999999, this));
    //Lista de productos
    cargarProducto();
    //Mostrar los productos del combo
    foreach (Producto *p, m_productos){
        ui->inProducto->addItem((p->nombre()));
    }
    //Configurar cabecera de la tabla
    QStringList cabecera = {tr("Cantidad"), tr("Producto"), tr("P. unitario"),tr("Subtotal")};
    ui->outDetalle->setColumnCount(4);
    ui->outDetalle->setHorizontalHeaderLabels(cabecera);
    //Establecer el subtotal a 0
    m_subtotal=0;
}

Principal::~Principal()
{
    delete ui;
}

bool Principal::verCedula(QString as)
{
    bool est = true;
        int vcedula[10];
        int vPar[4];
        int vImpar[5]={0};
        int sumaPar=0;
        int sumaImpar=0;
        int total;
        int nveri;

        double nu;

        if(as=="9999999999"){
            return true;
        }

        do
        {

            nu=as.toInt();
            if(nu<100000000 || nu>9999999999)
            {

                est=false;
                break;
            }
            //Separar string
            QString p1=as.mid(0,1);
            QString p2=as.mid(1,1);
            QString p3=as.mid(2,1);
            QString p4=as.mid(3,1);
            QString p5=as.mid(4,1);
            QString p6=as.mid(5,1);
            QString p7=as.mid(6,1);
            QString p8=as.mid(7,1);
            QString p9=as.mid(8,1);
            QString p10=as.mid(9,1);

            //Transformar string
            vcedula[0]=p1.toInt();
            vcedula[1]=p2.toInt();
            vcedula[2]=p3.toInt();
            vcedula[3]=p4.toInt();
            vcedula[4]=p5.toInt();
            vcedula[5]=p6.toInt();
            vcedula[6]=p7.toInt();
            vcedula[7]=p8.toInt();
            vcedula[8]=p9.toInt();
            vcedula[9]=p10.toInt();

            if(vcedula[0]>2)
            {

                est = false;
                break;
            }

            //Pares
            vPar[0]=vcedula[1];
            vPar[1]=vcedula[3];
            vPar[2]=vcedula[5];
            vPar[3]=vcedula[7];
            //Impares
            vImpar[0]=vcedula[0];
            vImpar[1]=vcedula[2];
            vImpar[2]=vcedula[4];
            vImpar[3]=vcedula[6];
            vImpar[4]=vcedula[8];


            //Punto 2. Multiplicacion impar
            for(int i=0; i<5; i++)
            {
                vImpar[i]=vImpar[i]*2;
                if(vImpar[i]>9)
                {
                    vImpar[i]=vImpar[i]-9;
                }
                sumaImpar += vImpar[i];
            }
            //Punto 3. Sumar los pares
            for(int i=0; i<4; i++)
            {
                sumaPar += vPar[i];
            }

            total = sumaPar + sumaImpar;

            //Punto 4. Se obtiene el modulo;

            nveri = total%10;


            //Punto 5. Numero verificador
            if(nveri==0)
            {
                if(nveri==vcedula[9])
                {
                    est=true;
                    break;
                }else
                {
                    est=false;
                    break;
                }
            }else if(nveri !=0)
            {
                nveri=10-nveri;

                if(nveri==vcedula[9])
                {
                    est=true;
                    break;
                }else
                {

                    est=false;
                    break;
                }
            }

        }while(nu<100000000 || nu>9999999999 || vcedula[0]>2);
        return est;
}

bool Principal::checkDatos()
{
    bool auba = true;
    //cedula de identidad
    if(ui->inCedula->text().isEmpty()||!verCedula(ui->inCedula->text())){
        ui->inCedula->setStyleSheet("background-color:rgb(184,32,0);");
        auba = false;
    }
    else{
        ui->inCedula->setStyleSheet("background-color:rgb(98,184,0);");
    }


    //Nombre
    if(ui->inNombre->text().isEmpty()){
        ui->inNombre->setStyleSheet("background-color:rgb(98,184,0);");
        auba = false;
    }
    else{
        ui->inNombre->setStyleSheet("background-color:rgb(98,184,0);");
    }


    //telefono
    if(ui->inTelefono->text().isEmpty()){
        ui->inTelefono->setStyleSheet("background-color:rgb(98,184,0);");
        auba = false;
    }
    else{
        ui->inTelefono->setStyleSheet("background-color:rgb(98,184,0);");
    }


    //correo
    if(ui->inCorreo->text().isEmpty()){
        ui->inCorreo->setStyleSheet("background-color:rgb(98,184,0);");
        auba = false;
    }
    else{
        ui->inCorreo->setStyleSheet("background-color:rgb(98,184,0);");
    }


    //direccion
    if(ui->inDireccion->toPlainText().isEmpty()){
        ui->inDireccion->setStyleSheet("background-color:rgb(98,184,0);");
        auba = false;
    }
    else{
        ui->inDireccion->setStyleSheet("background-color:rgb(98,184,0);");
    }
    return auba;
}



/**
 * @brief Principal::cargarProducto Cargar la lista de productos de la tienda
 */
void Principal::cargarProducto()
{
    //Crear productos "quemados" en el codigo
    m_productos.append(new Producto(1, tr("Arroz/lb"), 0.40));
    m_productos.append(new Producto(2, tr("Huevos/u"), 0.15));
    m_productos.append(new Producto(3, tr("Leche/u"), 0.80));
    m_productos.append(new Producto(4, tr("Pan/u"), 0.15));
    m_productos.append(new Producto(5, tr("Queso/u"), 2.50));

}

void Principal::limpiar()
{
    ui->inCedula->setText("");
    ui->inCorreo->setText("");
    ui->inNombre->setText("");
    ui->inTelefono->setText("");
    ui->outIva->setText("0.00");
    ui->outPrecio->setText("0.00");
    ui->outSubtotal->setText("0.00");
    ui->outTotal->setText("0.00");
    int rows=ui->outDetalle->rowCount();
    while(rows!=-1){
        ui->outDetalle->removeRow(rows);
        rows--;
    }
    ui->inDireccion->clear();


}

void Principal::calcular(float stProducto)
{
    // Calcular valores
    m_subtotal += stProducto;
    float iva = m_subtotal * IVA / 100;
    float total = m_subtotal + iva;
    // Mostrar valores en GUI
    ui->outSubtotal->setText("$ " + QString::number(m_subtotal, 'f', 2));
    ui->outIva->setText("$ " + QString::number(iva, 'f', 2));
    ui->outTotal->setText("$ " + QString::number(total, 'f', 2));
}


void Principal::on_inProducto_currentIndexChanged(int index)
{
    // Obtener el precio del producto actual seleccionado
    float precio = m_productos.at(index)->precio();
    // Mostrar el precio del product en la etiqueta
    ui->outPrecio->setText("$ " + QString::number(precio,'f',2));
    // Resetear el spinbox de cantidad
    ui->inCantidad->setValue(0);
}


void Principal::on_btnAgregar_released()
{
    // Validar que no se agregen productos cpn 0 cantidad
    int cantidad = ui->inCantidad->value();
    if (cantidad == 0){
        return;
    }
    // Obtener los datos de la GUI
    int i = ui->inProducto->currentIndex();
    Producto *p = m_productos.at(i);

    // Calcular el subrotal del producto
    float subtotal = p->precio() * cantidad;

    // Agregar los datos a la tabla
    int fila = ui->outDetalle->rowCount();
    ui->outDetalle->insertRow(fila);
    ui->outDetalle->setItem(fila, 0, new QTableWidgetItem(QString::number(cantidad)));
    ui->outDetalle->setItem(fila, 1, new QTableWidgetItem(p->nombre()));
    ui->outDetalle->setItem(fila, 2, new QTableWidgetItem(QString::number(p->precio(),'f',2)));
    ui->outDetalle->setItem(fila, 3, new QTableWidgetItem(QString::number(subtotal,'f',2)));

    // Limpiar datos
    ui->inCantidad->setValue(0);
    ui->inProducto->setFocus();

    // Actualizar subtotales
    calcular(subtotal);
}


void Principal::on_btnLimpiar_released()
{
    limpiar();
}

void Principal::on_btnFinalizar_released()
{
    QString descripcion= "";
    int row = ui->outDetalle->rowCount(), contador =0;
    while(contador!=row){
        descripcion += "\t     " + ui->outDetalle->item(contador,0)->text() + "                     " +
                       ui->outDetalle->item(contador,1)->text() + "                  " +
                       ui->outDetalle->item(contador,2)->text() + "                    " +
                       ui->outDetalle->item(contador,3)->text() + "\n" ;
        contador++;
    }

    if(checkDatos()){
    Factura *factura=new Factura(this);
    factura->setProducts(descripcion);
    factura->insertarDatos(ui->inCedula->text(),
                           ui->inNombre->text(),
                           ui->inTelefono->text(),
                           ui->inCorreo->text(),
                           ui->inDireccion->toPlainText());
    factura->totales(ui->outSubtotal->text(),
                     ui->outIva->text(),
                     ui->outTotal->text());
    factura->exec();
    }

}

void Principal::on_actionAcerca_de_2_triggered()
{
    // Crear un objeto de la ventana que queremos invocar
    Acerca *dialogo = new Acerca(this);
    // Enviar parámetro a la ventana
    dialogo->setVersion(VERSION);
    // Mostrar la ventana (diálogo) MODAL
    dialogo->exec();
    // Obtener datos de la ventana
    qDebug() << dialogo->valor();
}

