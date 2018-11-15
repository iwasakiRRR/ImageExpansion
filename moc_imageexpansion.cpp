/****************************************************************************
** Meta object code from reading C++ file 'imageexpansion.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imageexpansion.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageexpansion.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageExpansion[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   16,   15,   15, 0x0a,
      44,   16,   15,   15, 0x0a,
      66,   16,   15,   15, 0x0a,
      95,   16,   15,   15, 0x0a,
     124,   16,   15,   15, 0x0a,
     152,   16,   15,   15, 0x0a,
     180,   16,   15,   15, 0x0a,
     199,   15,   15,   15, 0x0a,
     209,   15,   15,   15, 0x0a,
     229,   15,   15,   15, 0x0a,
     252,  237,   15,   15, 0x0a,
     302,   15,   15,   15, 0x0a,
     319,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ImageExpansion[] = {
    "ImageExpansion\0\0value\0setValueHueLower(int)\0"
    "setValueHueUpper(int)\0"
    "setValueSaturationLower(int)\0"
    "setValueSaturationUpper(int)\0"
    "setValueLightnessLower(int)\0"
    "setValueLightnessUpper(int)\0"
    "setValueGamma(int)\0setText()\0"
    "makeExpandedImage()\0close()\0path,fileNames\0"
    "search_dir(std::string,std::vector<std::string>&)\0"
    "incrementCount()\0dicrementCount()\0"
};

void ImageExpansion::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImageExpansion *_t = static_cast<ImageExpansion *>(_o);
        switch (_id) {
        case 0: _t->setValueHueLower((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setValueHueUpper((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setValueSaturationLower((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setValueSaturationUpper((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setValueLightnessLower((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setValueLightnessUpper((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setValueGamma((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setText(); break;
        case 8: _t->makeExpandedImage(); break;
        case 9: _t->close(); break;
        case 10: _t->search_dir((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::vector<std::string>(*)>(_a[2]))); break;
        case 11: _t->incrementCount(); break;
        case 12: _t->dicrementCount(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImageExpansion::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImageExpansion::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImageExpansion,
      qt_meta_data_ImageExpansion, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageExpansion::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageExpansion::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageExpansion::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageExpansion))
        return static_cast<void*>(const_cast< ImageExpansion*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImageExpansion::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
static const uint qt_meta_data_MainDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      28,   11,   11,   11, 0x08,
      42,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      74,   11,   11,   11, 0x08,
      87,   81,   11,   11, 0x08,
     119,  113,  108,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainDialog[] = {
    "MainDialog\0\0chooseMakeDir()\0chooseTPath()\0"
    "chooseBPath()\0chooseImageFile()\0next()\0"
    "qstr_\0makeMessage(QString)\0bool\0text_\0"
    "checkText(QString)\0"
};

void MainDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainDialog *_t = static_cast<MainDialog *>(_o);
        switch (_id) {
        case 0: _t->chooseMakeDir(); break;
        case 1: _t->chooseTPath(); break;
        case 2: _t->chooseBPath(); break;
        case 3: _t->chooseImageFile(); break;
        case 4: _t->next(); break;
        case 5: _t->makeMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: { bool _r = _t->checkText((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MainDialog,
      qt_meta_data_MainDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainDialog))
        return static_cast<void*>(const_cast< MainDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MainDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
