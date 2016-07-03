#ifndef URLGENERATORJY_H
#define URLGENERATORJY_H

#include <QDialog>

class QDateTimeEdit;
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QRadioButton;
class QSpinBox;
class QTextEdit;
class QTextCodec;
class QTimeEdit;


class UrlGeneratorJY : public QDialog
{
	Q_OBJECT

public:
	UrlGeneratorJY( QWidget* parent=0 );
	~UrlGeneratorJY();

private:
	QDateTimeEdit* _dtStart;
	QDateTimeEdit* _dtEnd;
    QGroupBox*     _gpDef;
	QGroupBox*     _gpMove;
	QLabel*        _lblRef;
	QLineEdit*     _edFav;
	QLineEdit*     _edWidth;
	QLineEdit*     _edHeight;
	QLineEdit*     _edRefresh;
	QPushButton*   _btnGen;
	QRadioButton*  _rbMin;
	QRadioButton*  _rbHr;
	QRadioButton*  _rbDay;
	QRadioButton*  _rbWeek;
	QRadioButton*  _rbMon;
	QRadioButton*  _rbQtr;
	QRadioButton*  _rbLine;
	QRadioButton*  _rbCol;
	QRadioButton*  _rbPie;
	QRadioButton*  _rbStack;
	QRadioButton*  _rbDef;
	QRadioButton*  _rbMove;
	QRadioButton*  _rbRefM;
	QRadioButton*  _rbRefH;
	QRadioButton*  _rbFwd;
	QRadioButton*  _rbBack;
	QSpinBox*      _spBack;
	QSpinBox*      _spBase;
	QTextEdit*     _txtLoc;
	QTextEdit*     _txtUrl;
	QTextCodec*    _txtCodec;
	QTimeEdit*     _teBack;
	QTimeEdit*     _teBase;

	bool _IsValidForm();

private slots:
    void _OnGen();
	void _OnClickedMode();
	void _OnClickedRefresh();
};

#endif // URLGENERATORJY_H
