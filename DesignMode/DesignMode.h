#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DesignMode.h"

class DesignMode : public QMainWindow
{
    Q_OBJECT

public:
    DesignMode(QWidget *parent = nullptr);
    ~DesignMode();

private:
    Ui::DesignModeClass ui;
};
