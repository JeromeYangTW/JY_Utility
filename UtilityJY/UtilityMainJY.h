#ifndef UTILITYMAINJY_H
#define UTILITYMAINJY_H

#include <QMainWindow>

#include <Tools/UrlGeneratorJY.h>

class UtilityMainJY : public QMainWindow
{
	Q_OBJECT

public:
	UtilityMainJY( QWidget* parent = 0 );
	~UtilityMainJY();

private:
	UrlGeneratorJY* _urlDlg;

private slots:
    void _OnGenUrlDlg();
};

#endif // UTILITYMAINJY_H
