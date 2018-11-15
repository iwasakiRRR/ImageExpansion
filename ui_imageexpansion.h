/********************************************************************************
** Form generated from reading UI file 'imageexpansion.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEEXPANSION_H
#define UI_IMAGEEXPANSION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageExpansion
{
public:
    QSlider *SaturationBar;
    QSlider *LightnessBar;
    QSlider *HueBar;
    QPushButton *MakeButton;
    QSpinBox *HueBox;
    QSpinBox *SaturationBox;
    QSpinBox *LightnessBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QSpinBox *HueBox_2;
    QSlider *HueBar_2;
    QSpinBox *SaturationBox_2;
    QSlider *SaturationBar_2;
    QLineEdit *lineEdit_5;
    QSpinBox *LightnessBox_2;
    QLineEdit *lineEdit_6;
    QSlider *LightnessBar_2;
    QPushButton *RectImageButton;
    QLineEdit *lineEdit_7;
    QSlider *GammaBar;
    QSpinBox *GammaBox;
    QPushButton *nextButton;
    QPushButton *previousButton;

    void setupUi(QWidget *ImageExpansion)
    {
        if (ImageExpansion->objectName().isEmpty())
            ImageExpansion->setObjectName(QString::fromUtf8("ImageExpansion"));
        ImageExpansion->resize(1154, 678);
        SaturationBar = new QSlider(ImageExpansion);
        SaturationBar->setObjectName(QString::fromUtf8("SaturationBar"));
        SaturationBar->setGeometry(QRect(159, 590, 321, 21));
        SaturationBar->setCursor(QCursor(Qt::SplitHCursor));
        SaturationBar->setMaximum(254);
        SaturationBar->setOrientation(Qt::Horizontal);
        LightnessBar = new QSlider(ImageExpansion);
        LightnessBar->setObjectName(QString::fromUtf8("LightnessBar"));
        LightnessBar->setGeometry(QRect(159, 620, 321, 21));
        LightnessBar->setCursor(QCursor(Qt::SplitHCursor));
        LightnessBar->setMaximum(254);
        LightnessBar->setOrientation(Qt::Horizontal);
        HueBar = new QSlider(ImageExpansion);
        HueBar->setObjectName(QString::fromUtf8("HueBar"));
        HueBar->setGeometry(QRect(159, 560, 321, 21));
        HueBar->setCursor(QCursor(Qt::SplitHCursor));
        HueBar->setMinimum(0);
        HueBar->setMaximum(180);
        HueBar->setValue(0);
        HueBar->setOrientation(Qt::Horizontal);
        MakeButton = new QPushButton(ImageExpansion);
        MakeButton->setObjectName(QString::fromUtf8("MakeButton"));
        MakeButton->setGeometry(QRect(919, 650, 181, 22));
        HueBox = new QSpinBox(ImageExpansion);
        HueBox->setObjectName(QString::fromUtf8("HueBox"));
        HueBox->setGeometry(QRect(490, 560, 61, 23));
        HueBox->setMinimum(0);
        HueBox->setMaximum(180);
        HueBox->setValue(0);
        SaturationBox = new QSpinBox(ImageExpansion);
        SaturationBox->setObjectName(QString::fromUtf8("SaturationBox"));
        SaturationBox->setGeometry(QRect(490, 590, 61, 23));
        SaturationBox->setMaximum(254);
        SaturationBox->setValue(0);
        LightnessBox = new QSpinBox(ImageExpansion);
        LightnessBox->setObjectName(QString::fromUtf8("LightnessBox"));
        LightnessBox->setGeometry(QRect(490, 620, 61, 23));
        LightnessBox->setMaximum(255);
        LightnessBox->setValue(0);
        lineEdit = new QLineEdit(ImageExpansion);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 560, 131, 22));
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(ImageExpansion);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 590, 131, 22));
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(ImageExpansion);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 620, 131, 22));
        lineEdit_3->setReadOnly(true);
        lineEdit_4 = new QLineEdit(ImageExpansion);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(561, 560, 131, 22));
        lineEdit_4->setReadOnly(true);
        HueBox_2 = new QSpinBox(ImageExpansion);
        HueBox_2->setObjectName(QString::fromUtf8("HueBox_2"));
        HueBox_2->setGeometry(QRect(1041, 560, 61, 23));
        HueBox_2->setMaximum(180);
        HueBox_2->setValue(180);
        HueBar_2 = new QSlider(ImageExpansion);
        HueBar_2->setObjectName(QString::fromUtf8("HueBar_2"));
        HueBar_2->setGeometry(QRect(710, 560, 321, 21));
        HueBar_2->setCursor(QCursor(Qt::SplitHCursor));
        HueBar_2->setMaximum(180);
        HueBar_2->setValue(180);
        HueBar_2->setOrientation(Qt::Horizontal);
        SaturationBox_2 = new QSpinBox(ImageExpansion);
        SaturationBox_2->setObjectName(QString::fromUtf8("SaturationBox_2"));
        SaturationBox_2->setGeometry(QRect(1040, 590, 61, 23));
        SaturationBox_2->setMaximum(255);
        SaturationBox_2->setValue(255);
        SaturationBar_2 = new QSlider(ImageExpansion);
        SaturationBar_2->setObjectName(QString::fromUtf8("SaturationBar_2"));
        SaturationBar_2->setGeometry(QRect(710, 590, 321, 21));
        SaturationBar_2->setCursor(QCursor(Qt::SplitHCursor));
        SaturationBar_2->setMaximum(255);
        SaturationBar_2->setValue(255);
        SaturationBar_2->setOrientation(Qt::Horizontal);
        lineEdit_5 = new QLineEdit(ImageExpansion);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(560, 590, 131, 22));
        lineEdit_5->setReadOnly(true);
        LightnessBox_2 = new QSpinBox(ImageExpansion);
        LightnessBox_2->setObjectName(QString::fromUtf8("LightnessBox_2"));
        LightnessBox_2->setGeometry(QRect(1041, 620, 61, 23));
        LightnessBox_2->setMaximum(255);
        LightnessBox_2->setValue(255);
        lineEdit_6 = new QLineEdit(ImageExpansion);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(561, 620, 131, 22));
        lineEdit_6->setReadOnly(true);
        LightnessBar_2 = new QSlider(ImageExpansion);
        LightnessBar_2->setObjectName(QString::fromUtf8("LightnessBar_2"));
        LightnessBar_2->setGeometry(QRect(710, 620, 321, 21));
        LightnessBar_2->setCursor(QCursor(Qt::SplitHCursor));
        LightnessBar_2->setMaximum(255);
        LightnessBar_2->setValue(255);
        LightnessBar_2->setSliderPosition(255);
        LightnessBar_2->setOrientation(Qt::Horizontal);
        RectImageButton = new QPushButton(ImageExpansion);
        RectImageButton->setObjectName(QString::fromUtf8("RectImageButton"));
        RectImageButton->setGeometry(QRect(730, 650, 141, 22));
        lineEdit_7 = new QLineEdit(ImageExpansion);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(10, 650, 131, 22));
        GammaBar = new QSlider(ImageExpansion);
        GammaBar->setObjectName(QString::fromUtf8("GammaBar"));
        GammaBar->setGeometry(QRect(160, 650, 321, 16));
        GammaBar->setMinimum(5);
        GammaBar->setMaximum(500);
        GammaBar->setValue(100);
        GammaBar->setOrientation(Qt::Horizontal);
        GammaBox = new QSpinBox(ImageExpansion);
        GammaBox->setObjectName(QString::fromUtf8("GammaBox"));
        GammaBox->setGeometry(QRect(490, 650, 61, 23));
        GammaBox->setMinimum(5);
        GammaBox->setMaximum(500);
        GammaBox->setValue(100);
        nextButton = new QPushButton(ImageExpansion);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(620, 480, 21, 21));
        previousButton = new QPushButton(ImageExpansion);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));
        previousButton->setGeometry(QRect(0, 480, 21, 22));

        retranslateUi(ImageExpansion);

        QMetaObject::connectSlotsByName(ImageExpansion);
    } // setupUi

    void retranslateUi(QWidget *ImageExpansion)
    {
        ImageExpansion->setWindowTitle(QApplication::translate("ImageExpansion", "ImageExpansion", 0, QApplication::UnicodeUTF8));
        MakeButton->setText(QApplication::translate("ImageExpansion", "make expanded image", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("ImageExpansion", "Hue_lower", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("ImageExpansion", "Saturation_lower", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QApplication::translate("ImageExpansion", "Lightness_lower", 0, QApplication::UnicodeUTF8));
        lineEdit_4->setText(QApplication::translate("ImageExpansion", "Hue_upper", 0, QApplication::UnicodeUTF8));
        lineEdit_5->setText(QApplication::translate("ImageExpansion", "Saturation_upper", 0, QApplication::UnicodeUTF8));
        lineEdit_6->setText(QApplication::translate("ImageExpansion", "Lightness_upper", 0, QApplication::UnicodeUTF8));
        RectImageButton->setText(QApplication::translate("ImageExpansion", "show rect image", 0, QApplication::UnicodeUTF8));
        lineEdit_7->setText(QApplication::translate("ImageExpansion", "Gamma", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("ImageExpansion", "->", 0, QApplication::UnicodeUTF8));
        previousButton->setText(QApplication::translate("ImageExpansion", "<-", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImageExpansion: public Ui_ImageExpansion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEEXPANSION_H
