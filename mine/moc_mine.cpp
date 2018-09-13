/****************************************************************************
** MineField meta object code from reading C++ file 'mine.h'
**
** Created: Thu Dec 21 01:00:15 2006
**      by: The Qt MOC ($Id:  qt/moc_yacc.cpp   3.0.5   edited Jul 8 12:26 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "mine.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 19)
#error "This file was generated using the moc from 3.0.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *MineField::className() const
{
    return "MineField";
}

QMetaObject *MineField::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MineField;

#ifndef QT_NO_TRANSLATION
QString MineField::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MineField", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MineField::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MineField", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MineField::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"NewGame", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "iDifficult", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"Difficult", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "NewGame()", &slot_0, QMetaData::Public },
	{ "Difficult(int)", &slot_1, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "iValue", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"MineNumberValueChange", 1, param_signal_0 };
    static const QUMethod signal_1 = {"StartMineTimer", 0, 0 };
    static const QUMethod signal_2 = {"StopMineTimer", 0, 0 };
    static const QUMethod signal_3 = {"ClearMineTime", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "MineNumberValueChange(int)", &signal_0, QMetaData::Private },
	{ "StartMineTimer()", &signal_1, QMetaData::Private },
	{ "StopMineTimer()", &signal_2, QMetaData::Private },
	{ "ClearMineTime()", &signal_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"MineField", parentObject,
	slot_tbl, 2,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MineField.setMetaObject( metaObj );
    return metaObj;
}

void* MineField::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MineField" ) ) return (MineField*)this;
    return QWidget::qt_cast( clname );
}

// SIGNAL MineNumberValueChange
void MineField::MineNumberValueChange( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL StartMineTimer
void MineField::StartMineTimer()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL StopMineTimer
void MineField::StopMineTimer()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL ClearMineTime
void MineField::ClearMineTime()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

bool MineField::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: NewGame(); break;
    case 1: Difficult((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool MineField::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: MineNumberValueChange((int)static_QUType_int.get(_o+1)); break;
    case 1: StartMineTimer(); break;
    case 2: StopMineTimer(); break;
    case 3: ClearMineTime(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool MineField::qt_property( int _id, int _f, QVariant* _v)
{
    return QWidget::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES
