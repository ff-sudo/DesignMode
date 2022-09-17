#include "DesignMode.h"
#include "./src/observer/pagesubject.hpp"
DesignMode::DesignMode(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	ui.wgObserve->layout()->addWidget(new SubjectA(this));
}

DesignMode::~DesignMode()
{}
