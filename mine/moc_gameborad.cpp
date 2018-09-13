/****************************************************************************
** GameBoard meta object code from reading C++ file 'gameborad.h'
**
** Created: Thu Dec 21 01:06:41 2006
**      by: The Qt MOC ($Id:  qt/moc_yacc.cpp   3.0.5   edited Jul 8 12:26 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "gameborad.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 19)
#error "This file was generated using the moc from 3.0.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *GameBoard::className() const
{
    return "GameBoard";
}

QMetaObject *GameBoard::metaObj = 0;
static QMetaObjectCleanUp cleanUp_GameBoard;

#ifndef QT_NO_TRANSLATION
QString GameBoard::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "GameBoard", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString GameBoard::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "GameBoard", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* GameBoard::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"NewGame", 0, 0 };
    static const QUMethod slot_1 = {"Difficult", 0, 0 };
    static const QUMethod slot_2 = {"About", 0, 0 };
    static const QUMethod slot_3 = {"MiningTimer", 0, 0 };
    static const QUMethod slot_4 = {"slot_StartMine", 0, 0 };
    static const QUMethod slot_5 = {"slot_StopMine", 0, 0 };
    static const QUMethod slot_6 = {"slot_ClearMineTime", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "NewGame()", &slot_0, QMetaData::Protected },
	{ "Difficult()", &slot_1, QMetaData::Protected },
	{ "About()", &slot_2, QMetaData::Protected },
	{ "MiningTimer()", &slot_3, QMetaData::Protected },
	{ "slot_StartMine()", &slot_4, QMetaData::Protected },
	{ "slot_StopMine()", &slot_5, QMetaData::Protected },
	{ "slot_ClearMineTime()", &slot_6, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ "iTime", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"signals_setTime", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "signals_setTime(int)", &signal_0, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"GameBoard", parentObject,
	slot_tbl, 7,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_GameBoard.setMetaObject( metaObj );
    return metaObj;
}

void* GameBoard::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "GameBoard" ) ) return (GameBoard*)this;
    return QWidget::qt_cast( clname );
}

// SIGNAL signals_setTime
void GameBoard::signals_setTime( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool GameBoard::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: NewGame(); break;
    case 1: Difficult(); break;
    case 2: About(); break;
    case 3: MiningTimer(); break;
    case 4: slot_StartMine(); break;
    case 5: slot_StopMine(); break;
    case 6: slot_ClearMineTime(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool GameBoard::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: signals_setTime((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool GameBoard::qt_property( int _id, int _f, QVariant* _v)
{
    return QWidget::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES
