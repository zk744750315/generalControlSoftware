#pragma once

#include <QWidget>
#include "ui_CDataShow.h"

class CDataShow : public QWidget
{
	Q_OBJECT

public:
	CDataShow(QWidget *parent = Q_NULLPTR);
	~CDataShow();

private:
	Ui::CDataShow ui;
};
