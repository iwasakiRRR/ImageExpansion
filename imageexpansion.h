#ifndef IMAGEEXPANSION_H
#define IMAGEEXPANSION_H
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QMainWindow>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QPaintEvent>
#include <QImage>
#include <QColor>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QMenuBar>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <QStyle>
#include <QFileDialog>
#include <QMessageBox>
#include <QToolButton>
#include <random>
//include opencv lib
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
//include os lib
#include <sys/stat.h>
#include <bits/stdc++.h>
#include <dirent.h>
#include <unistd.h>
#include <random>

namespace Ui {
class ImageExpansion;
class ImageProcessing;
}

class ImageExpansion : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ImageExpansion)


public:
    explicit ImageExpansion(QWidget *parent = 0);
    ~ImageExpansion();
    int value() const;
    void ChangeColor();
    int MessageIndicater(QString qstr_);
    void SetObject_dir_number(int &directry_number_,int &object_number_,int &it);
    std::vector<int> generateUniqueRandomIntegers(size_t max_, int num_);

    //opencv
    cv::Mat image;
    cv::Mat origin_image;
    cv::Mat whiteback_image;
    cv::Mat output_image;
    cv::Mat object_image;
    cv::Mat mask_image;
    cv::Mat closed_image;
    cv::Mat reverced_image;
    cv::Mat buleback_image;
    cv::Mat blackback_image_copy;
    cv::Mat kernel_c1;
    cv::Mat kernel_c2;
    cv::Mat look_up_table;

    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    std::vector<std::string> IMAGES;
    int image_count;

    float convert_x;
    float convert_y;
    float convert_w;
    float convert_h;
    bool rect_flag;
    bool cancel_flag;
    bool lightness_low_ber_flag;

    QDialog dia;

    void extractObjectArea();
    void LineUpImages();
    bool checkDir(int dir_num_,std::string &string_dir_,std::string &current_dir_,std::string &string_number_);

public slots:
    void setValueHueLower(int value);
    void setValueHueUpper(int value);
    void setValueSaturationLower(int value);
    void setValueSaturationUpper(int value);
    void setValueLightnessLower(int value);
    void setValueLightnessUpper(int value);
    void setValueGamma(int value);
    void setText();
    void makeExpandedImage();
    void close();
    void search_dir(std::string path,std::vector<std::string> &fileNames);
    void incrementCount();
    void dicrementCount();
private:
    Ui::ImageExpansion *ui;

    int hue_low,hue_up;//default 0,360
    int saturation_low,saturation_up;//default 0,255
    int lightness_low,lightness_up;//default 0,255
    int h,s,v;
    double gamma;
    int gamma_low,gamma_up;//default 90,110
protected:
    void paintEvent(QPaintEvent *e);
};

class MainDialog : public QDialog
{
    Q_OBJECT
public:
    MainDialog(QWidget* parent = 0);
    ~MainDialog();
    bool checkFileExistence(const std::string& str);
private slots:
    void chooseMakeDir();
    void chooseTPath();
    void chooseBPath();
    void chooseImageFile();
    void next();
    void makeMessage(QString qstr_);
    bool checkText(QString text_);
private:
    bool quit;
    QGridLayout* layout;
    QString fullpathname;
    QLabel* label1;
    QLabel* label2;
    QLabel* label3;
    QLabel* label4;
    QLabel* errorlabel;
    QPushButton* pushButton1;
    QPushButton* pushButton2;
    QPushButton* pushButton3;
    QPushButton* pushButton4;
    QPushButton* pushButton_set;
    QLineEdit* lineEdit1;
    QLineEdit* lineEdit2;
    QLineEdit* lineEdit3;
    QLineEdit* lineEdit4;
    QMessageBox* msgBox;
protected:
    void closeEvent(QCloseEvent *c);

};
#endif // IMAGEEXPANSION_H
#endif // MAINWINDOW_H
