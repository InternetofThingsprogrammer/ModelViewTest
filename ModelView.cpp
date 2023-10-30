#include "ModelView.h"
#include "ui_ModelView.h"

ModelView::ModelView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelView)
{
    ui->setupUi(this);
    m_model = new QStandardItemModel;
    initModel();

    ui->tableView_1->setModel(m_model);
    ui->tableView_1->setAlternatingRowColors(true);
    ui->tableView_1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_1->horizontalHeader()->setStretchLastSection(true);

    ui->tableView_2->setModel(m_model);
    ui->tableView_2->setAlternatingRowColors(true);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
    //设置不可编辑
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->clearBtn, SIGNAL(clicked(bool)), this, SLOT(onClearBtn()));
    showMaximized();
}

ModelView::~ModelView()
{
    delete ui;
}

void ModelView::initModel()
{
    initModelHeadData();
    setModelHeadData(20, 5, {"Name", "Class", "Age", "Sex", "Grade"});
    initModelData();
}

void ModelView::initModelHeadData()
{
    setModelHeadData(m_row, m_col, QStringList());
}

void ModelView::initModelData(QList<QStringList> data)
{

    for(int row=0; row<data.count(); row++)
    {
         auto list = data[row];
        for(int col=0; col<list.count(); col++)
        {
            auto str = list[col];
            setModelData(row, col, str);
        }
    }
}

void ModelView::setModelHeadData(int row, int col, QStringList headers)
{
    m_model->setRowCount(row);
    m_model->setColumnCount(col);
    m_model->setHorizontalHeaderLabels(headers);
}

void ModelView::addModelDataRow(int col, QStringList list)
{

}

void ModelView::addModelDataCol(int row, QStringList list)
{

}

void ModelView::addModelData(QList<QStringList> data)
{

}

void ModelView::delMolelDataCol(int col)
{

}

void ModelView::delMolelDataRow(int row)
{

}

void ModelView::setModelData(int row, int col, const QString& str)
{
    QStandardItem *item = new QStandardItem(str);
    m_model->setItem(row, col, item);
}

void ModelView::clearModelData()
{
    int rowCount = m_model->rowCount();
    for(int row=rowCount; row>=0; row--)
    {
        m_model->removeRow(row);
    }
    for(int idx=0; idx<rowCount; idx++)
    {
        m_model->insertRow(idx);
    }
}

void ModelView::onClearBtn()
{
    clearModelData();
}

void ModelView::on_updateBtn_clicked()
{
   QList<QStringList> strList = {

                     {"张三", "三班", "12", "男", "13"},
                     {"张三", "三班", "12", "男", "14"},
                     {"张三", "三班", "12", "男", "15"},
                     {"张三", "三班", "12", "男", "16"},
                                };

   initModelData(strList);
}
