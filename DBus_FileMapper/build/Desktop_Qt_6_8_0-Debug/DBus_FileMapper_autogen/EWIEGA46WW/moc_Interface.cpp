/****************************************************************************
** Meta object code from reading C++ file 'Interface.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Interface.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSFormatMapperDBusServiceENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSFormatMapperDBusServiceENDCLASS = QtMocHelpers::stringData(
    "FormatMapperDBusService",
    "D-Bus Interface",
    "org.artem.Service11",
    "RegisterApplication",
    "",
    "appName",
    "supportedFormats",
    "OpenFileWithRegisteredApp",
    "filePath",
    "RegisterDefaultApplication",
    "format",
    "defaultApp",
    "GetDefaultApplication",
    "extension",
    "GetRegisteredApplications",
    "GetRegisteredFormats",
    "QMap<QString,QStringList>"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFormatMapperDBusServiceENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
       6,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    2,   52,    4, 0x0a,    1 /* Public */,
       7,    1,   57,    4, 0x0a,    4 /* Public */,
       9,    2,   60,    4, 0x0a,    6 /* Public */,
      12,    1,   65,    4, 0x0a,    9 /* Public */,
      14,    0,   68,    4, 0x0a,   11 /* Public */,
      15,    0,   69,    4, 0x0a,   12 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::QString, QMetaType::QString,   13,
    QMetaType::QStringList,
    0x80000000 | 16,

       0        // eod
};

Q_CONSTINIT const QMetaObject FormatMapperDBusService::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSFormatMapperDBusServiceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFormatMapperDBusServiceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSFormatMapperDBusServiceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FormatMapperDBusService, std::true_type>,
        // method 'RegisterApplication'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'OpenFileWithRegisteredApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'RegisterDefaultApplication'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'GetDefaultApplication'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'GetRegisteredApplications'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'GetRegisteredFormats'
        QtPrivate::TypeAndForceComplete<QMap<QString,QStringList>, std::false_type>
    >,
    nullptr
} };

void FormatMapperDBusService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormatMapperDBusService *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->RegisterApplication((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 1: _t->OpenFileWithRegisteredApp((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->RegisterDefaultApplication((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: { QString _r = _t->GetDefaultApplication((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QStringList _r = _t->GetRegisteredApplications();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 5: { QMap<QString,QStringList> _r = _t->GetRegisteredFormats();
            if (_a[0]) *reinterpret_cast< QMap<QString,QStringList>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *FormatMapperDBusService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormatMapperDBusService::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFormatMapperDBusServiceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QDBusContext"))
        return static_cast< QDBusContext*>(this);
    return QObject::qt_metacast(_clname);
}

int FormatMapperDBusService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
