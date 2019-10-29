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
	//��ʱ�������ǰ·��
	QString currentDir = tempDir.currentPath();
	//���filePath·�������ڣ�������
	if (!tempDir.exists(filePath))
	{
		qDebug() << QObject::tr("�����ڸ�·��") << endl;
		tempDir.mkpath(filePath);
	}
	QFile* tempFile = new QFile;
	//�������ִ��·�����õ�filePath��
	tempDir.setCurrent(filePath);
	qDebug() << tempDir.currentPath();
	//���filePath·�����Ƿ�����ļ�fileName,���ֹͣ������
	if (tempFile->exists(fileName))
	{
		qDebug() << QObject::tr("�ļ�����");
		return false;
	}
	//��ʱ��·����û��fileName�ļ���ʹ����������ڵ�ǰ·���´����ļ�
	tempFile->setFileName(fileName);
	if (!tempFile->open(QIODevice::WriteOnly | QIODevice::Text))
	{
		qDebug() << QObject::tr("��ʧ��");
	}
	tempFile->close();
	//������ǰ·������Ϊԭ����·��
	tempDir.setCurrent(currentDir);
	qDebug() << tempDir.currentPath();

	return true;
}
