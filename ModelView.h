#ifndef MODELVIEW_H
#define MODELVIEW_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class ModelView;
}

class ModelView : public QWidget
{
    Q_OBJECT

public:
    explicit ModelView(QWidget *parent = 0);
    ~ModelView();

    void initModel();
    void initModelHeadData();
    void initModelData(QList<QStringList> data = QList<QStringList>());

    void setModelHeadData(int row, int col, QStringList headers);

    void addModelDataRow(int row, QStringList list);
    void addModelDataCol(int col, QStringList list);
    void addModelData(QList<QStringList> data);

    void delMolelDataRow(int row);
    void delMolelDataCol(int col);
    void clearModelData();

    void setModelData(int row, int col, const QString& str);

private slots:

    void onClearBtn();
    void on_updateBtn_clicked();

private:
    Ui::ModelView *ui;
    QStandardItemModel* m_model;

    QStringList m_headers;
    const int m_row = 20;
    const int m_col =5;
    QList<QStringList> m_data;
};

#endif // MODELVIEW_H
