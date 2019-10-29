#include "input_dialog.h"
#include <QDir>
#include <qDebug>

input_dialog::input_dialog(QWidget* parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	bool c1 = connect(ui.okButton, SIGNAL(clicked()), this, SLOT(OnOK()));
	bool c2 = connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(OnCanel()));
}

void input_dialog::OnOK()
{
	createFile(_cur_path, ui.lineEdit->text() + ".txt");
}

void input_dialog::OnCanel()
{
	_text = "";
}

bool input_dialog::createFile(QString filePath, QString fileName)
{
	QDir tempDir;
	//临时保存程序当前路径
	QString currentDir = tempDir.currentPath();
	//如果filePath路径不存在，创建它
	if (!tempDir.exists(filePath))
	{
		qDebug() << QObject::tr("不存在该路径") << endl;
		tempDir.mkpath(filePath);
	}
	QFile* tempFile = new QFile;
	//将程序的执行路径设置到filePath下
	tempDir.setCurrent(filePath);
	qDebug() << tempDir.currentPath();
	//检查filePath路径下是否存在文件fileName,如果停止操作。
	if (tempFile->exists(fileName))
	{
		qDebug() << QObject::tr("文件存在");
		return false;
	}
	//此时，路径下没有fileName文件，使用下面代码在当前路径下创建文件
	tempFile->setFileName(fileName);
	if (!tempFile->open(QIODevice::WriteOnly | QIODevice::Text))
	{
		qDebug() << QObject::tr("打开失败");
	}
	tempFile->close();
	//将程序当前路径设置为原来的路径
	tempDir.setCurrent(currentDir);
	qDebug() << tempDir.currentPath();

	return true;
}
