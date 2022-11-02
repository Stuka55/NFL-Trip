/****************************************************************************
** Meta object code from reading C++ file 'tripplanner.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../tripplanner.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tripplanner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_tripPlanner_t {
    QByteArrayData data[17];
    char stringdata0[401];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tripPlanner_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tripPlanner_t qt_meta_stringdata_tripPlanner = {
    {
QT_MOC_LITERAL(0, 0, 11), // "tripPlanner"
QT_MOC_LITERAL(1, 12, 12), // "refreshLists"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 31), // "on_preset_checkBox_stateChanged"
QT_MOC_LITERAL(4, 58, 4), // "arg1"
QT_MOC_LITERAL(5, 63, 39), // "on_starting_comboBox_currentT..."
QT_MOC_LITERAL(6, 103, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 125, 31), // "on_listWidget_itemDoubleClicked"
QT_MOC_LITERAL(8, 157, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(9, 174, 4), // "item"
QT_MOC_LITERAL(10, 179, 33), // "on_listWidget_2_itemDoubleCli..."
QT_MOC_LITERAL(11, 213, 27), // "on_close_pushButton_clicked"
QT_MOC_LITERAL(12, 241, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(13, 273, 5), // "index"
QT_MOC_LITERAL(14, 279, 40), // "on_custom2_optionsList_itemDo..."
QT_MOC_LITERAL(15, 320, 37), // "on_custom2_selected_itemDoubl..."
QT_MOC_LITERAL(16, 358, 42) // "on_startingTeam_combo_2_curre..."

    },
    "tripPlanner\0refreshLists\0\0"
    "on_preset_checkBox_stateChanged\0arg1\0"
    "on_starting_comboBox_currentTextChanged\0"
    "on_pushButton_clicked\0"
    "on_listWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0"
    "on_listWidget_2_itemDoubleClicked\0"
    "on_close_pushButton_clicked\0"
    "on_comboBox_currentIndexChanged\0index\0"
    "on_custom2_optionsList_itemDoubleClicked\0"
    "on_custom2_selected_itemDoubleClicked\0"
    "on_startingTeam_combo_2_currentTextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tripPlanner[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    1,   70,    2, 0x08 /* Private */,
       5,    1,   73,    2, 0x08 /* Private */,
       6,    0,   76,    2, 0x08 /* Private */,
       7,    1,   77,    2, 0x08 /* Private */,
      10,    1,   80,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    1,   84,    2, 0x08 /* Private */,
      14,    1,   87,    2, 0x08 /* Private */,
      15,    1,   90,    2, 0x08 /* Private */,
      16,    1,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void tripPlanner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<tripPlanner *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refreshLists(); break;
        case 1: _t->on_preset_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_starting_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->on_listWidget_2_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->on_close_pushButton_clicked(); break;
        case 7: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_custom2_optionsList_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->on_custom2_selected_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->on_startingTeam_combo_2_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject tripPlanner::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_tripPlanner.data,
    qt_meta_data_tripPlanner,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *tripPlanner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tripPlanner::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tripPlanner.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int tripPlanner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
