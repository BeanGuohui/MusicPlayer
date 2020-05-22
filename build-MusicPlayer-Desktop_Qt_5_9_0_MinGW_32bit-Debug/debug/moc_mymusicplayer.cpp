/****************************************************************************
** Meta object code from reading C++ file 'mymusicplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MusicPlayer/mymusicplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mymusicplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyMusicPlayer_t {
    QByteArrayData data[11];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyMusicPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyMusicPlayer_t qt_meta_stringdata_MyMusicPlayer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MyMusicPlayer"
QT_MOC_LITERAL(1, 14, 10), // "pauseStart"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "addFile"
QT_MOC_LITERAL(4, 34, 8), // "prevSong"
QT_MOC_LITERAL(5, 43, 8), // "nextSong"
QT_MOC_LITERAL(6, 52, 8), // "isVolume"
QT_MOC_LITERAL(7, 61, 14), // "changePlayType"
QT_MOC_LITERAL(8, 76, 12), // "sliderChange"
QT_MOC_LITERAL(9, 89, 19), // "changeSliderProcess"
QT_MOC_LITERAL(10, 109, 18) // "setSliderMaxnumber"

    },
    "MyMusicPlayer\0pauseStart\0\0addFile\0"
    "prevSong\0nextSong\0isVolume\0changePlayType\0"
    "sliderChange\0changeSliderProcess\0"
    "setSliderMaxnumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyMusicPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    1,   65,    2, 0x0a /* Public */,
       9,    1,   68,    2, 0x0a /* Public */,
      10,    1,   71,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,

       0        // eod
};

void MyMusicPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyMusicPlayer *_t = static_cast<MyMusicPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pauseStart(); break;
        case 1: _t->addFile(); break;
        case 2: _t->prevSong(); break;
        case 3: _t->nextSong(); break;
        case 4: _t->isVolume(); break;
        case 5: _t->changePlayType(); break;
        case 6: _t->sliderChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->changeSliderProcess((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->setSliderMaxnumber((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MyMusicPlayer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MyMusicPlayer.data,
      qt_meta_data_MyMusicPlayer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyMusicPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyMusicPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyMusicPlayer.stringdata0))
        return static_cast<void*>(const_cast< MyMusicPlayer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MyMusicPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
