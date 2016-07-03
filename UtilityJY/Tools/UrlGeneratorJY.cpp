#include <QDateTimeEdit>
#include <QDebug>
#include <QFrame>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QRadioButton>
#include <QSpinBox>
#include <QString>
#include <QTextCodec>
#include <QTextEdit>
#include <QTimeEdit>
#include <QUrl>
#include <QUrlQuery>
#include <QVBoxLayout>

#include "UrlGeneratorJY.h"

UrlGeneratorJY::UrlGeneratorJY( QWidget* parent )
	: QDialog(parent)
{
	_txtCodec = QTextCodec::codecForName("Big5-ETen");
	setWindowTitle( _txtCodec->toUnicode("URL 產生器") );
	
	QVBoxLayout* vl = new QVBoxLayout;
    vl->setContentsMargins( 4, 4, 4, 4 );
    vl->setSpacing( 4 );
	/* Location IP */
	QHBoxLayout* hl = new QHBoxLayout;
    hl->setContentsMargins( 2, 2, 2, 2 );
    hl->setSpacing( 2 );
	QLabel* lbl = new QLabel( _txtCodec->toUnicode("位置 IP:"), this );
	lbl->setFixedSize( 75, 22 );
	hl->addWidget( lbl );
	hl->addSpacing( 2 );
	_txtLoc = new QTextEdit( this );
	_txtLoc->setMinimumWidth( 200 );
	_txtLoc->setFixedHeight( 40 );
	hl->addWidget( _txtLoc );
	hl->addStretch();
	vl->addLayout( hl );
	/* Location IP */
    hl = new QHBoxLayout;
    hl->setContentsMargins( 2, 2, 2, 2 );
    hl->setSpacing( 2 );
	lbl = new QLabel( _txtCodec->toUnicode("我的最愛 ID:"), this );
	lbl->setFixedSize( 75, 22 );
	hl->addWidget( lbl );
	hl->addSpacing( 2 );
	_edFav = new QLineEdit( this );
	_edFav->setFixedWidth( 40 );
	hl->addWidget( _edFav );
	hl->addStretch();
	vl->addLayout( hl );
	/* Chart Related */
	QGroupBox* gpBox = new QGroupBox( _txtCodec->toUnicode("[圖樣相關]"), this );
	gpBox->setAlignment( Qt::AlignHCenter );
	QVBoxLayout* vlayout = new QVBoxLayout;
    vlayout->setContentsMargins( 0, 0, 0, 0 );
    vlayout->setSpacing( 2 );
	hl = new QHBoxLayout;
    hl->setContentsMargins( 2, 2, 2, 2 );
    hl->setSpacing( 2 );
	lbl = new QLabel( _txtCodec->toUnicode("類型:"), gpBox );
	lbl->setFixedSize( 75, 22 );
	hl->addWidget( lbl );
	hl->addSpacing( 2 );
	_rbLine = new QRadioButton( _txtCodec->toUnicode("趨勢圖"), gpBox );
	_rbLine->setChecked( true );
	hl->addWidget( _rbLine );
	hl->addSpacing( 2 );
	_rbCol = new QRadioButton( _txtCodec->toUnicode("直方圖"), gpBox );
	hl->addWidget( _rbCol );
	hl->addSpacing( 2 );
	_rbPie = new QRadioButton( _txtCodec->toUnicode("圓餅圖"), gpBox );
	hl->addWidget( _rbPie );
	hl->addSpacing( 2 );
	_rbStack = new QRadioButton( _txtCodec->toUnicode("堆疊圖"), gpBox );
	hl->addWidget( _rbStack );
	hl->addStretch();
	vlayout->addLayout( hl );
	hl = new QHBoxLayout;
    hl->setContentsMargins( 2, 2, 2, 2 );
    hl->setSpacing( 2 );
	lbl = new QLabel( _txtCodec->toUnicode("大小:"), gpBox );
	lbl->setFixedSize( 75, 22 );
	hl->addWidget( lbl );
	hl->addSpacing( 2 );
	lbl = new QLabel( _txtCodec->toUnicode("(寬)"), gpBox );
	lbl->setFixedSize( 20, 22 );
	hl->addWidget( lbl );
	hl->addSpacing( 2 );
	_edWidth = new QLineEdit( this );
	_edWidth->setFixedWidth( 80 );
	_edWidth->setText( "640" );
	hl->addWidget( _edWidth );
	hl->addSpacing( 2 );
	lbl = new QLabel( tr("px"), this );
	lbl->setFixedSize( 20, 22 );
	hl->addWidget( lbl );
	hl->addStretch();
	lbl = new QLabel( _txtCodec->toUnicode("(高)"), gpBox );
	lbl->setFixedSize( 20, 22 );
	hl->addWidget( lbl );
	hl->addSpacing( 2 );
	_edHeight = new QLineEdit( this );
	_edHeight->setFixedWidth( 80 );
	_edHeight->setText( "480" );
	hl->addWidget( _edHeight );
	hl->addSpacing( 2 );
	lbl = new QLabel( tr("px"), this );
	lbl->setFixedSize( 20, 22 );
	hl->addWidget( lbl );
	hl->addStretch();
	vlayout->addLayout( hl );
	gpBox->setLayout( vlayout );
	vl->addWidget( gpBox );
	/* Time Related */
	gpBox = new QGroupBox( _txtCodec->toUnicode("[時間相關]"), this );
	gpBox->setAlignment( Qt::AlignHCenter );
	vlayout = new QVBoxLayout;
    vlayout->setContentsMargins( 0, 0, 0, 0 );
    vlayout->setSpacing( 2 );
    QWidget* twid = new QWidget( this );
	hl = new QHBoxLayout;
    hl->setContentsMargins( 2, 2, 2, 2 );
    hl->setSpacing( 2 );
	lbl = new QLabel( _txtCodec->toUnicode("時間區間:"), twid );
	lbl->setFixedSize( 75, 22 );
	hl->addWidget( lbl );
	hl->addSpacing( 2 );
    _rbMin = new QRadioButton( _txtCodec->toUnicode("分"), twid );
	hl->addWidget( _rbMin );
	hl->addSpacing( 2 );
    _rbHr = new QRadioButton( _txtCodec->toUnicode("時"), twid );
	hl->addWidget( _rbHr );
	hl->addSpacing( 2 );
    _rbDay = new QRadioButton( _txtCodec->toUnicode("日"), twid );
	_rbDay->setChecked( true );
	hl->addWidget( _rbDay );
	hl->addSpacing( 2 );
    _rbWeek = new QRadioButton( _txtCodec->toUnicode("週"), twid );
	hl->addWidget( _rbWeek );
	hl->addSpacing( 2 );
    _rbMon = new QRadioButton( _txtCodec->toUnicode("月"), twid );
	hl->addWidget( _rbMon );
	hl->addSpacing( 2 );
    _rbQtr = new QRadioButton( _txtCodec->toUnicode("季"), twid );
	hl->addWidget( _rbQtr );
	hl->addStretch();
	twid->setLayout( hl );
    vlayout->addWidget( twid );
	twid = new QWidget( this );
	hl = new QHBoxLayout;
    hl->setContentsMargins( 2, 2, 2, 2 );
    hl->setSpacing( 2 );
    _rbDef = new QRadioButton( _txtCodec->toUnicode("固定式"), twid );
	_rbDef->setFixedWidth( 200 );
	_rbDef->setChecked( true );
	connect( _rbDef, SIGNAL(clicked()), this, SLOT(_OnClickedMode()) );
	hl->addWidget( _rbDef );
	hl->addStretch();
    _rbMove = new QRadioButton( _txtCodec->toUnicode("移動式"), twid );
	_rbMove->setFixedWidth( 300 );
	connect( _rbMove, SIGNAL(clicked()), this, SLOT(_OnClickedMode()) );
	hl->addWidget( _rbMove );
	hl->addStretch();
	twid->setLayout( hl );
	vlayout->addWidget( twid );
	/* Group Box: Pre-defined */
	hl = new QHBoxLayout;
    hl->setContentsMargins( 2, 2, 2, 2 );
    hl->setSpacing( 2 );
	_gpDef = new QGroupBox( gpBox );
	_gpDef->setAlignment( Qt::AlignHCenter );
    _gpDef->setFixedWidth( 200 );
	QVBoxLayout* vlgp = new QVBoxLayout;
    vlgp->setContentsMargins( 0, 0, 0, 0 );
    vlgp->setSpacing( 2 );
	QHBoxLayout* hlgp = new QHBoxLayout;
    hlgp->setContentsMargins( 2, 2, 2, 2 );
    hlgp->setSpacing( 2 );
	_dtStart = new QDateTimeEdit( QDateTime::currentDateTime().addDays(-1), _gpDef );
	_dtStart->setDisplayFormat( "yyyy-MM-dd HH:mm:ss" );
	_dtStart->setFixedWidth( 120 );
	hlgp->addWidget( _dtStart );
	hlgp->addSpacing( 2 );
	lbl = new QLabel( _txtCodec->toUnicode("至"), _gpDef );
	lbl->setFixedSize( 20, 22 );
	hlgp->addWidget( lbl );
	hlgp->addStretch();
	vlgp->addLayout( hlgp );
    hlgp = new QHBoxLayout;
    hlgp->setContentsMargins( 2, 2, 2, 2 );
    hlgp->setSpacing( 2 );
	_dtEnd = new QDateTimeEdit( QDateTime::currentDateTime(), _gpDef );
    _dtEnd->setDisplayFormat( "yyyy-MM-dd HH:mm:ss" );
	_dtEnd->setFixedWidth( 120 );
	hlgp->addWidget( _dtEnd );
	hlgp->addStretch();
	vlgp->addLayout( hlgp );
	_gpDef->setLayout( vlgp );
	hl->addWidget( _gpDef );
	hl->addStretch();
	/* Group Box: Moving-Time-Axis */
	_gpMove = new QGroupBox( gpBox );
	_gpMove->setAlignment( Qt::AlignHCenter );
	_gpMove->setFixedWidth( 300 );
	_gpMove->setEnabled( false );
    vlgp = new QVBoxLayout;
    vlgp->setContentsMargins( 0, 0, 0, 0 );
    vlgp->setSpacing( 2 );
	hlgp = new QHBoxLayout;
    hlgp->setContentsMargins( 2, 2, 2, 2 );
    hlgp->setSpacing( 2 );
	lbl = new QLabel( _txtCodec->toUnicode("基準點: 今日起"), _gpMove );
	lbl->setFixedSize( 135, 22 );
	hlgp->addWidget( lbl );
	hlgp->addSpacing( 2 );
    _rbFwd = new QRadioButton( _txtCodec->toUnicode("前"), _gpMove );
	_rbFwd->setChecked( true );
	hlgp->addWidget( _rbFwd );
    hlgp->addSpacing( 2 );
	_rbBack = new QRadioButton( _txtCodec->toUnicode("後"), _gpMove );
	hlgp->addWidget( _rbBack );
	hlgp->addSpacing( 2 );
	_spBase = new QSpinBox( _gpMove );
	hlgp->addWidget( _spBase );
	hlgp->addSpacing( 2 );
	lbl = new QLabel( _txtCodec->toUnicode("日"), _gpMove );
	lbl->setFixedSize( 20, 22 );
	hlgp->addWidget( lbl );
	hlgp->addSpacing( 2 );
	_teBase = new QTimeEdit( _gpMove );
	_teBase->setDisplayFormat( "HH:mm" );
	hlgp->addWidget( _teBase );
	hlgp->addStretch();
	vlgp->addLayout( hlgp );
	hlgp = new QHBoxLayout;
    hlgp->setContentsMargins( 2, 2, 2, 2 );
    hlgp->setSpacing( 2 );
	lbl = new QLabel( _txtCodec->toUnicode("回溯點: 基準點往前"), _gpMove );
	lbl->setFixedSize( 135, 22 );
	hlgp->addWidget( lbl );
	hlgp->addSpacing( 2 );
	_spBack = new QSpinBox( _gpMove );
	hlgp->addWidget( _spBack );
	hlgp->addSpacing( 2 );
	lbl = new QLabel( _txtCodec->toUnicode("日"), _gpMove );
	lbl->setFixedSize( 20, 22 );
	hlgp->addWidget( lbl );
	hlgp->addSpacing( 2 );
	_teBack = new QTimeEdit( _gpMove );
    _teBack->setDisplayFormat( "HH:mm" );
	hlgp->addWidget( _teBack );
	hlgp->addStretch();
	vlgp->addLayout( hlgp );
	_gpMove->setLayout( vlgp );
	hl->addWidget( _gpMove );
	hl->addStretch();
	vlayout->addLayout( hl );
    twid = new QWidget( gpBox );
	hl = new QHBoxLayout;
    hl->setContentsMargins( 2, 2, 2, 2 );
    hl->setSpacing( 2 );
	hl = new QHBoxLayout;
    hl->setContentsMargins( 2, 2, 2, 2 );
    hl->setSpacing( 2 );
	lbl = new QLabel( _txtCodec->toUnicode("更新率:"), gpBox );
	lbl->setFixedSize( 75, 22 );
	hl->addWidget( lbl );
	hl->addSpacing( 2 );
    _rbRefM = new QRadioButton( _txtCodec->toUnicode("分"), gpBox );
	_rbRefM->setChecked( true );
	connect( _rbRefM, SIGNAL(clicked()), this, SLOT(_OnClickedRefresh()) );
	hl->addWidget( _rbRefM );
	hl->addSpacing( 2 );
    _rbRefH = new QRadioButton( _txtCodec->toUnicode("時"), gpBox );
	connect( _rbRefH, SIGNAL(clicked()), this, SLOT(_OnClickedRefresh()) );
	hl->addWidget( _rbRefH );
	hl->addSpacing( 2 );
	_edRefresh = new QLineEdit( gpBox );
	_edRefresh->setFixedWidth( 40 );
	_edRefresh->setText( "10" );
	hl->addWidget( _edRefresh );
	hl->addSpacing( 2 );
	_lblRef = new QLabel( _txtCodec->toUnicode("分"), gpBox );
	_lblRef->setFixedSize( 20, 22 );
	hl->addWidget( _lblRef );
	hl->addStretch();
	twid->setLayout( hl );
	vlayout->addWidget( twid );
	gpBox->setLayout( vlayout );
	vl->addWidget( gpBox );
	_txtUrl = new QTextEdit( this );
	_txtUrl->setReadOnly( true );
	vl->addWidget( _txtUrl );
    QFrame* frmSep = new QFrame( this );
    frmSep->setFrameShape( QFrame::HLine );
    frmSep->setFrameShadow( QFrame::Sunken );
	vl->addWidget( frmSep );

	hl = new QHBoxLayout;
    hl->setContentsMargins( 2, 2, 2, 2 );
    hl->setSpacing( 2 );
	hl->addStretch();
	_btnGen = new QPushButton( _txtCodec->toUnicode("產生 URL"), this );
	_btnGen->setFixedSize( 80, 22 );
	_btnGen->setFocusPolicy( Qt::NoFocus );
	connect( _btnGen, SIGNAL(clicked()), this, SLOT(_OnGen()) );
	hl->addWidget( _btnGen );
	QPushButton* btn = new QPushButton( _txtCodec->toUnicode("關閉"), this );
	btn->setFixedSize( 60, 22 );
	btn->setFocusPolicy( Qt::NoFocus );
	connect( btn, SIGNAL(clicked()), this, SLOT(close()) );
	hl->addWidget( btn );
	vl->addLayout( hl );
	vl->addStretch();
	setLayout( vl );

	resize( 520, 250 );
	setMaximumSize( 750, 250 );
}

UrlGeneratorJY::~UrlGeneratorJY()
{
}

bool UrlGeneratorJY::_IsValidForm()
{
	QString msg;
	if ( 0==_txtLoc->toPlainText().trimmed().length() ) msg += _txtCodec->toUnicode("需填入 [位置 IP].\n");
	if ( 0==_edFav->text().trimmed().length() ) msg += _txtCodec->toUnicode("需填入 [我的最愛 ID].\n");
	if ( (0==_edWidth->text().trimmed().length())||(0==_edHeight->text().trimmed().length()) ) {
		msg += _txtCodec->toUnicode("需填入 [寬] 或 [高].\n");
	}
	if ( (0==_edRefresh->text().trimmed().length()) ) msg += _txtCodec->toUnicode("需填入 [更新率].\n");
	if ( msg.length()>0) {
		QMessageBox::critical( this, _txtCodec->toUnicode("錯誤"), msg );
	}
	return ( 0==msg.length() );
}

void UrlGeneratorJY::_OnGen()
{
	if ( !_IsValidForm() )  return;

	QUrl urlBase( _txtLoc->toPlainText() );
	urlBase = urlBase.resolved( QUrl("HistoryMultiTag.aspx") );
    QUrlQuery qrySet;
	qrySet.addQueryItem( "urlmode", "Y" );
	qrySet.addQueryItem( "id", _edFav->text() );
	QString val( "LINE" );
	if ( _rbLine->isChecked() ) {
		val = "LINE";
	}
	else if ( _rbCol->isChecked() ) {
		val = "COLUMN";
	}
	else if ( _rbPie->isChecked() ) {
		val = "PIE";
	}
	else if ( _rbStack->isChecked() ) {
		val = "STACK";
	}
	else {
	}
	qrySet.addQueryItem( "type", val );
	val = "D";
	if ( _rbMin->isChecked() ) {
		val = "MT";
	}
	else if ( _rbHr->isChecked() ) {
		val = "HR";
	}
	else if ( _rbDay->isChecked() ) {
		val = "D";
	}
	else if ( _rbWeek->isChecked() ) {
		val = "W";
	}
	else if ( _rbMon->isChecked() ) {
		val = "M";
	}
	else if ( _rbQtr->isChecked() ) {
		val = "Q";
	}
	else {
	}
	qrySet.addQueryItem( "itvl", val );
	if ( _rbDef->isChecked() ) {
		QString date( _dtStart->date().toString("yyyyMMdd") );
		QString time( _dtStart->time().toString("HHmmss") );
		qrySet.addQueryItem( "start", QString("%1%2").arg(date).arg(time) );
		date = _dtEnd->date().toString("yyyyMMdd");
		time = _dtEnd->time().toString("HHmmss");
		qrySet.addQueryItem( "end", QString("%1%2").arg(date).arg(time) );
	}
	else {
		int factor = (_rbFwd->isChecked()) ? -1 : 1;
		int date = factor*_spBase->text().toInt();
		QString time( _teBase->time().toString("HHmm") );
		qrySet.addQueryItem( "base", QString("%1;%2").arg(date).arg(time) );
		date = (-1)*_spBack->text().toInt();
		time = _teBack->time().toString("HHmm");
		qrySet.addQueryItem( "back", QString("%1;%2").arg(date).arg(time) );
	}
	qrySet.addQueryItem( "width", _edWidth->text() );
	qrySet.addQueryItem( "height", _edHeight->text() );
	QString type = ( _rbRefH->isChecked() ) ? "h" : "m";
	qrySet.addQueryItem( "refresh", _edRefresh->text()+type );
	urlBase.setQuery( qrySet );
    _txtUrl->setText( urlBase.toString() );
}

void UrlGeneratorJY::_OnClickedMode()
{
	_gpDef->setEnabled( _rbDef->isChecked() );
	_gpMove->setEnabled( _rbMove->isChecked() );
}

void UrlGeneratorJY::_OnClickedRefresh()
{
	QRadioButton* rb = (QRadioButton*)sender();
    _lblRef->setText( rb->text() );
}

