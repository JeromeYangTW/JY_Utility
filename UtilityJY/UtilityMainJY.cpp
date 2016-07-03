#include <QAction>
#include <QApplication>
#include <QDebug>
#include <QMenu>
#include <QMenuBar>
#include <QTextCodec>

#include "Tools/UrlGeneratorJY.h"
#include "UtilityMainJY.h"

UtilityMainJY::UtilityMainJY( QWidget* parent )
	: QMainWindow(parent)
	, _urlDlg((UrlGeneratorJY*)0)
{
    QTextCodec* txtCodec = QTextCodec::codecForName("Big5-ETen");
	setWindowTitle( txtCodec->toUnicode("DIA SIS 泛用工具") );

	QMenuBar* mBar = menuBar();
	QMenu* toolsMenu = mBar->addMenu( txtCodec->toUnicode("功能") );
	QAction* urlgenAct = toolsMenu->addAction( txtCodec->toUnicode("URL 產生器") );
	connect( urlgenAct, SIGNAL(triggered()), this, SLOT(_OnGenUrlDlg()) );
	toolsMenu->addSeparator();
	QAction* quitAct = toolsMenu->addAction( txtCodec->toUnicode("結束") );
	connect( quitAct, SIGNAL(triggered()), qApp, SLOT(quit()) );
	
	QMenu* aboutMenu = mBar->addMenu( txtCodec->toUnicode("說明") );
    QAction* aboutAct = aboutMenu->addAction( txtCodec->toUnicode("關於 Qt") );
	connect( aboutAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()) );

	resize( 400, 300 );
	setMinimumSize( 400, 300 );
	setMaximumSize( 600, 450 );
}

UtilityMainJY::~UtilityMainJY()
{
}

void UtilityMainJY::_OnGenUrlDlg()
{
	if ( _urlDlg )  { delete _urlDlg; _urlDlg = (UrlGeneratorJY*)0; }

    _urlDlg = new UrlGeneratorJY();
	_urlDlg->setModal( true );
	_urlDlg->show();
}

