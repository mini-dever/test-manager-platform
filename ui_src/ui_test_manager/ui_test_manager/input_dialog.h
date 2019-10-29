#pragma once
#include <QDialog>
#include <QString>
#include <ui_input_dialog.h>
class input_dialog : public QDialog
{
	Q_OBJECT
public:
	input_dialog(QWidget* parent = Q_NULLPTR);
public slots:
	void OnOK();
	void OnCanel();
public:
	bool createFile(QString filePath, QString fileName);
	QString _text;
	QString _cur_path;
private:
	Ui::Dialog ui;
};