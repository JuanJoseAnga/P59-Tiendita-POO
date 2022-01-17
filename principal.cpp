#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    //Lista de productos
    cargarProducto();
    //Mostrar los productos del combo
    foreach (Producto *p, m_productos){
        ui->inProducto->addItem((p->nombre()));
    }
    //Configurar cabecera de la tabla
    QStringList cabecera = {"Cantidad", "Producto", "Subtotal"};
    ui->outDetalle->setColumnCount(3);
    ui->outDetalle->setHorizontalHeaderLabels(cabecera);
}

Principal::~Principal()
{
    delete ui;
}
/**
 * @brief Principal::cargarProducto Cargar la lista de productos de la tienda
 */
void Principal::cargarProducto()
{
    //Crear productos "quemados" en el codigo
    m_productos.append(new Producto(1, "Leche", 0.80));
    m_productos.append(new Producto(2, "Pan", 0.15));
    m_productos.append(new Producto(3, "Queso", 2.50));
    m_productos.append(new Producto(1, "Huevos", 0.10));
}

