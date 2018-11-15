#include "imageexpansion.h"
#include "ui_imageexpansion.h"
#include <math.h>

std::string IMAGE_FILE_PATH = "/home/ryo/dustbin_of_iwasaki/tm_image_expansion/image/000/";     //to refer several origin images.
std::string IMAGE_FULLPATH_AND_NAME = "/home/ryo/dustbin_of_iwasaki/tm_image_expansion/image/000/qqq.png";    //to refer first origin image
//std::string EXPANDED_IMAGE_PATH = "/home/ryo/tm_imageexpansion";       //to save expanded images
std::string BACKGROUND_IMAGE_PATH = "/home/ryo/dustbin_of_iwasaki/tm_image_expansion/backgroundImage";
std::string LEARNING_PATH = "/home/demulab/src/darknet3/athome_cfg";//fixed!!

/*///############# to create main UI ###############///*/

ImageExpansion::ImageExpansion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageExpansion)
{
    ui->setupUi(this);
    image_count = 0;
    rect_flag = 0;
    cancel_flag = false;
    h = 0;
    s = 255;
    v = 255;
    hue_low=1,hue_up=360;
    saturation_low=0;
    saturation_up=255;
    lightness_low=0;
    lightness_up=255;
    gamma = 1.0;
    gamma_low = 90;
    gamma_up = 110;
    convert_x = 0.0;
    convert_y = 0.0;
    convert_w = 0.0;
    convert_h = 0.0;
    connect(ui->HueBox, SIGNAL(valueChanged(int)), ui->HueBar, SLOT(setValue(int)));
    connect(ui->HueBox_2, SIGNAL(valueChanged(int)), ui->HueBar_2, SLOT(setValue(int)));
    connect(ui->HueBar,SIGNAL(valueChanged(int)),ui->HueBox,SLOT(setValue(int)));
    connect(ui->HueBar_2,SIGNAL(valueChanged(int)),ui->HueBox_2,SLOT(setValue(int)));
    connect(ui->SaturationBox, SIGNAL(valueChanged(int)), ui->SaturationBar, SLOT(setValue(int)));
    connect(ui->SaturationBox_2, SIGNAL(valueChanged(int)), ui->SaturationBar_2, SLOT(setValue(int)));
    connect(ui->SaturationBar,SIGNAL(valueChanged(int)),ui->SaturationBox,SLOT(setValue(int)));
    connect(ui->SaturationBar_2,SIGNAL(valueChanged(int)),ui->SaturationBox_2,SLOT(setValue(int)));
    connect(ui->GammaBar,SIGNAL(valueChanged(int)),ui->GammaBox,SLOT(setValue(int)));
    connect(ui->GammaBox,SIGNAL(valueChanged(int)),ui->GammaBar,SLOT(setValue(int)));
    connect(ui->LightnessBox, SIGNAL(valueChanged(int)), ui->LightnessBar, SLOT(setValue(int)));
    connect(ui->LightnessBox_2, SIGNAL(valueChanged(int)), ui->LightnessBar_2, SLOT(setValue(int)));
    connect(ui->LightnessBar,SIGNAL(valueChanged(int)),ui->LightnessBox,SLOT(setValue(int)));
    connect(ui->LightnessBar_2,SIGNAL(valueChanged(int)),ui->LightnessBox_2,SLOT(setValue(int)));
    connect(ui->HueBox,SIGNAL(valueChanged(int)),this,SLOT(setValueHueLower(int)));
    connect(ui->HueBox_2,SIGNAL(valueChanged(int)),this,SLOT(setValueHueUpper(int)));
    connect(ui->SaturationBox,SIGNAL(valueChanged(int)),this,SLOT(setValueSaturationLower(int)));
    connect(ui->SaturationBox_2,SIGNAL(valueChanged(int)),this,SLOT(setValueSaturationUpper(int)));
    connect(ui->LightnessBox,SIGNAL(valueChanged(int)),this,SLOT(setValueLightnessLower(int)));
    connect(ui->LightnessBox_2,SIGNAL(valueChanged(int)),this,SLOT(setValueLightnessUpper(int)));
    connect(ui->GammaBox,SIGNAL(valueChanged(int)),this,SLOT(setValueGamma(int)));
    connect(ui->RectImageButton,SIGNAL(clicked()),this,SLOT(setText()));
    connect(ui->MakeButton,SIGNAL(clicked()),this,SLOT(makeExpandedImage()));
    connect(ui->nextButton,SIGNAL(clicked()),this,SLOT(incrementCount()));
    connect(ui->previousButton,SIGNAL(clicked()),this,SLOT(dicrementCount()));

    kernel_c1 = cv::Mat::ones(10,10,CV_8U);
    kernel_c2 = cv::Mat::ones(30,30,CV_8U);
    look_up_table = cv::Mat::ones(256,1,CV_8U)*0;

    search_dir(IMAGE_FILE_PATH,IMAGES);
    LineUpImages();
    extractObjectArea();

}

ImageExpansion::~ImageExpansion()
{
    delete ui;
}

void ImageExpansion::LineUpImages(){
    int i = 0,max = IMAGES.size();
    std::string str = "";
std::cout<<"images is "<<IMAGES[i]<<std::endl;
    for(i=0;max>i;i++){
        if(IMAGES[i]==IMAGE_FULLPATH_AND_NAME){
            str = IMAGES[0];
            IMAGES[0] = IMAGE_FULLPATH_AND_NAME;
            IMAGES[i] = str;
        }
    }
}

int ImageExpansion::value() const{
    return h;
}

void ImageExpansion::setValueHueLower(int value){
    hue_low = value * 2;
    ChangeColor();
}

void ImageExpansion::setValueHueUpper(int value){
    hue_up = value * 2;
    ChangeColor();
}

void ImageExpansion::setValueSaturationLower(int value){
    int past = saturation_low;
    saturation_low = value;
    if(saturation_low>=saturation_up){
        saturation_low = saturation_up -1;
        ui->SaturationBar->setValue(saturation_low);
        ui->SaturationBox->setValue(saturation_low);
    }
    if(past != saturation_low){
        ChangeColor();
    }
}

void ImageExpansion::setValueSaturationUpper(int value){
    int past = saturation_up;
    saturation_up = value;
    if(saturation_low>=saturation_up){
        saturation_up = saturation_low +1;
        ui->SaturationBar_2->setValue(saturation_up);
        ui->SaturationBox_2->setValue(saturation_up);
    }
    if(past != saturation_up){
        ChangeColor();
    }
}

void ImageExpansion::setValueLightnessLower(int value){
    int past = lightness_low;
    lightness_low = value;
    if(lightness_low>=lightness_up){
        lightness_low = lightness_up -1;
        ui->LightnessBar->setValue(lightness_low);
        ui->LightnessBox->setValue(lightness_low);
    }
    if(past != lightness_low){
        ChangeColor();
    }
}

void ImageExpansion::setValueLightnessUpper(int value){
    int past = lightness_up;
    lightness_up = value;
    if(lightness_low>=lightness_up){
        lightness_up = lightness_low +1;
        ui->LightnessBar_2->setValue(lightness_up);
        ui->LightnessBox_2->setValue(lightness_up);
    }
    if(past != lightness_up){
        ChangeColor();
    }
}

void ImageExpansion::incrementCount(){
    //std::cout<<"iamges size is "<<IMAGES.size()<<std::endl;
    //std::cout<<"iamge num is "<<image_count<<std::endl;
    int im_size = IMAGES.size();
    if(im_size>image_count+1){
        image_count++;
        ChangeColor();
    }
}

void ImageExpansion::dicrementCount(){
    if(0<image_count){
        image_count--;
        ChangeColor();
    }
}

void ImageExpansion::setValueGamma(int value){
    int past = gamma;
    int lut[256],j=0;
    gamma = double(value)*0.01;
    if(past != gamma){
        cv::LUT(origin_image,cv::Mat(cv::Size(256,1),CV_8U,lut),origin_image);
        double gm = 1.0 / gamma;
        for(j=0;j<256;j++){
            lut[j]=pow(1.0*j/255,gm)*255;
        }
        ChangeColor();
    }
}

void ImageExpansion::setText(){
    QString str = "";
    if(rect_flag == 0){
        rect_flag = 1;
        str = "show rect image";
        ui->RectImageButton->setText(str);
    }
    else{
        rect_flag = 0;
        str = "hidden rect image";
        ui->RectImageButton->setText(str);
    }
    ChangeColor();
}

void ImageExpansion::search_dir(std::string path,std::vector<std::string> &fileNames){

    int i, dirElements;
    std::string search_path;
    struct stat stat_buf;
    struct dirent **namelist=NULL;
    char path_back = path.back();
    if(path_back!='/'){
        path+="/";
    }
    dirElements = scandir(path.c_str(), &namelist, NULL, NULL);//dirElements にはディレクトリ内の要素数が入る
    if(dirElements == -1) {
        std::cout<<"ERROR"<<std::endl;
    }
    else{
        //ディレクトリかファイルかを順番に識別
        for (i=0;i<dirElements;i+=1) {
        // "." と ".." を除く
            if( (std::strcmp(namelist[i]->d_name , ".\0") != 0) && (std::strcmp(namelist[i]->d_name , "..\0") != 0) ){
                //search_pathには検索対象のフルパスを格納する
                search_path = path + std::string(namelist[i] -> d_name);
                // ファイル情報の取得の成功
                if(stat(search_path.c_str(), &stat_buf) == 0){
                    // ディレクトリだった場合の処理
                    if((stat_buf.st_mode & S_IFMT) == S_IFDIR){
                        // 再帰によりディレクトリ内を探索
                        //search_dir(path + std::string(namelist[i] -> d_name) + "/", fileNames);
                    }
                //ファイルだった場合の処理
                    else {
                        fileNames.push_back(search_path);
                    }
                }
                // ファイル情報の取得の失敗
                else{
                    std::cout << "ERROR" <<  std::endl << std::endl;
                }
            }
        }
    }
    free(namelist);
    return;
}

int ImageExpansion::MessageIndicater(QString qstr){
    int res;
    QMessageBox *qmsg = new QMessageBox;
    qmsg->setWindowTitle("Message");
    qmsg->setText(qstr);
    qmsg->addButton(QMessageBox::Yes);
    qmsg->addButton(QMessageBox::No);
    res = qmsg->exec();
    return res;

}

void ImageExpansion::SetObject_dir_number(int &directry_number_, int &object_number_,int &it){
    QDialog *dialog = new QDialog;
    QGridLayout *layout = new QGridLayout;
    QSpinBox *qspin1 = new QSpinBox;
    QSpinBox *qspin2 = new QSpinBox;
    QSpinBox *qspin3 = new QSpinBox;
    QSpinBox *qspin4 = new QSpinBox;//gamma lower min 5(0.05)
    QSpinBox *qspin5 = new QSpinBox;//gamma upper max 500(5.0)
    QLabel *lab1 = new QLabel;
    QLabel *lab2 = new QLabel;
    QLabel *lab3 = new QLabel;
    QLabel *lab4 = new QLabel;
    QLabel *lab5 = new QLabel;
    QLabel *lab6 = new QLabel;//gamma lower
    QLabel *lab7 = new QLabel;//gamma upper
    //QLineEdit *line = new QLineEdit;
    QPushButton *pushOK = new QPushButton(tr("OK"));
    QPushButton *pushCancel = new QPushButton(tr("Cancel"));
    lab1->setText("set directy number");
    lab2->setText("set object number");
    lab3->setText("example \n./image/000/0_0_0.png\n/./image/(directy number)/(directry_number)_(object nuber)_(background number).jpg");
    lab4->setText("please set directry to save expanded images.");
    lab5->setText("number of images to create ");
    lab6->setText("gamma lower :min 5");
    lab7->setText("gamma upper :max 500");
    //line->setText(QString::fromStdString(EXPANDED_IMAGE_PATH));
    qspin1->setMaximum(999);
    qspin1->setMinimum(0);
    qspin1->setValue(directry_number_);
    qspin2->setMaximum(999);
    qspin2->setMinimum(0);
    qspin2->setValue(object_number_);
    qspin3->setMaximum(600);//Maximum(Number of images) depends on personal computer specification
    qspin3->setMinimum(1);
    qspin3->setValue(600);
    qspin4->setMaximum(499);
    qspin4->setMinimum(5);
    qspin4->setValue(90);
    qspin5->setMaximum(500);
    qspin5->setMinimum(6);
    qspin5->setValue(110);
    layout->addWidget(lab1,0,0);
    layout->addWidget(lab2,1,0);
    layout->addWidget(lab5,2,0);
    layout->addWidget(lab6,3,0);
    layout->addWidget(lab7,4,0);
    layout->addWidget(lab3,5,0);
    layout->addWidget(qspin1,0,2);
    layout->addWidget(qspin2,1,2);
    layout->addWidget(qspin3,2,2);
    layout->addWidget(qspin4,3,2);
    layout->addWidget(qspin5,4,2);
    layout->addWidget(pushOK,6,2);//4->6
    layout->addWidget(pushCancel,6,1);//4->6
    dialog->setLayout(layout);
    dialog->connect(pushOK,SIGNAL(clicked()),dialog,SLOT(close()));
    dialog->connect(pushCancel,SIGNAL(clicked()),this,SLOT(close()));
    dialog->exec();
    directry_number_ = qspin1->value();
    object_number_ = qspin2->value();
    it = qspin3->value();
    gamma_low = qspin4->value();
    gamma_up = qspin5->value();
    delete dialog;

}

//####################################################################################################################################

void ImageExpansion::makeExpandedImage(){
    QString qstr = "It takes a little time, is it okay for you?";
    std::string image_name;
    std::string text_name;
    std::string learning_name;
    std::string string_number;
    std::string current_dir;
    std::string contents;
    std::vector<std::string> filenames;
    std::vector<int> random_num;
    std::vector<int> random_num_gamma;
    std::ofstream learningfile;
    //cv::Mat background_image;
    //cv::Mat image_;
    int i,j,directry_number=0,object_number=0,it=1,res=0,im_size=IMAGES.size();
    uchar lut[256];
    double random_gamma;
    struct stat st;
    std::string string_dir;

    search_dir(BACKGROUND_IMAGE_PATH,filenames);
    res = MessageIndicater(qstr);
    if(res == QMessageBox::No){return;}
    SetObject_dir_number(directry_number,object_number,it);
    if(cancel_flag == true){
        cancel_flag = false;
        return;
    }
    if(int(filenames.size())<it){
        qstr = "background images < make images\nPlease reduce the number of images to create.\nOK?  ";
        res = MessageIndicater(qstr);
        if(res == QMessageBox::No){
            qstr = "reset number.";
            MessageIndicater(qstr);
            makeExpandedImage();
            return;
        }
    }
    if(checkDir(directry_number,string_dir,current_dir,string_number)==true){
        //std::cout<<"file exsits"<<std::endl;
        qstr = "file already extit.\nYou add images in this directry ?";
        res = MessageIndicater(qstr);
        if(res == QMessageBox::No){
            qstr = "reset directry number and object number.";
            MessageIndicater(qstr);
            makeExpandedImage();
            return;
        }
    }
    else{
        qstr = "file is not exist. make directry.";
        MessageIndicater(qstr);
        //make directry code.
        char* dir = new char[string_dir.size() + 1];
        std::strcpy(dir,string_dir.c_str());
        if(stat(dir,&st) != 0){
            mkdir(dir,0755);
            //std::cout<<"directry is "<<dir<<std::endl;
            delete[] dir;
        }
        else{
            delete[] dir;
        }

    }
    if(filenames.size() == 0){return;}
    qstr = "Do you write test.txt ?\nYes -> write test.txt.\nNo -> write train.txt";
    if(MessageIndicater(qstr) == QMessageBox::Yes){
        learning_name = current_dir + "/test.txt";
    }
    else{
        learning_name = current_dir + "/train.txt";
    }
    qstr = "Would you over write ?\nYes -> over writing.\nNo -> emptying.";
    if(MessageIndicater(qstr) == QMessageBox::Yes){
        learningfile.open(learning_name,std::ios::app);
    }
    else{
        learningfile.open(learning_name,std::ios::out);
    }
    random_num = generateUniqueRandomIntegers(filenames.size()-1,it);
    std::srand(std::time(NULL));
    //std::cout<<"it is "<<it<<std::endl;
    cv::Mat *background_image = new cv::Mat;
    for(i=0;i<it;i++){
        cv::Mat *image_ = new cv::Mat;
        //std::cout<<" file name is "<<filenames[random_num[i]]<<std::endl;
        *background_image = cv::imread(filenames[random_num[i]],1);
        background_image->resize(480,640);
        //std::cout<<" file size is "<<background_image->total()<<std::endl;
        cv::cvtColor(*background_image,*background_image,cv::COLOR_BGR2HSV);
        cv::bitwise_and(*background_image,*background_image,*image_,closed_image);
        cv::cvtColor(*image_,*image_,cv::COLOR_HSV2BGR);
        cv::bitwise_or(*image_,blackback_image_copy,*image_);
        image_name = string_dir + "/" + std::to_string(directry_number) + "_" + std::to_string(object_number) + "_" + std::to_string(i) + ".jpg";
        text_name = string_dir + "/" + std::to_string(directry_number) + "_" + std::to_string(object_number) + "_" + std::to_string(i) + ".txt";
        random_gamma = 1.0/(double(gamma_low+std::rand()%(gamma_up-gamma_low))*0.01);
        //std::cout<<"random gamma is "<<random_gamma<<std::endl;
        for(j=0;j<256;j++){
            lut[j]=pow(1.0*j/255,random_gamma)*255;
        }
        cv::LUT(*image_,cv::Mat(cv::Size(256,1),CV_8U,lut),*image_);
        //cv::LUT(*image_,cv::Mat(cv::Size(256,1),CV_32SC1,lut),*image_);
        cv::imwrite(image_name,*image_);
        std::ofstream outputfile(text_name,std::ios::out);
        contents = std::to_string(directry_number) + " " +  std::to_string(convert_x) + " " + std::to_string(convert_y) + " " + std::to_string(convert_w) + " " + std::to_string(convert_h);
        outputfile<<contents;
        learningfile<<LEARNING_PATH + string_number + "/" + std::to_string(directry_number) + "_" + std::to_string(object_number) + "_" + std::to_string(i) + ".jpg\n";
        outputfile.close();
        //std::cout<<" file size is "<<background_image->total()<<std::endl;
        background_image->release();
        //std::cout<<" file size is "<<background_image->total()<<std::endl;

    }
    learningfile.close();
    if (im_size>image_count+1){
        image_count++;
    }
    else{
        image_count=0;
    }
    ChangeColor();
}

void ImageExpansion::ChangeColor(){
    extractObjectArea();
    this->repaint();
}

bool ImageExpansion::checkDir(int dir_num,std::string &directry ,std::string &current_dir_,std::string &string_number_){
    char dir[255];
    std::string str;
    std::string num ="";
    getcwd(dir,255);
    current_dir_ = dir;
    if(dir_num <10){
        num = "/00"+ std::to_string(dir_num);
    }
    else if(dir_num>=10&&dir_num<100){
        num = "/0" + std::to_string(dir_num);
    }
    else{
        num = "/" + std::to_string(dir_num);
    }
    string_number_ = num;
    str = dir;
    str += num;
    std::ifstream ifs(str);
    directry = str;
    return ifs.is_open();
}

void ImageExpansion::close(){
    cancel_flag = true;
    dia.close();
}

std::vector<int> ImageExpansion::generateUniqueRandomIntegers(size_t max, int num)
{
  std::random_device rnd;
  std::mt19937 mt(rnd());
  std::vector<int> v(max+1); // CAUTION "max+1" !!
  std::iota(v.begin(), v.end(), 0);
  std::shuffle(v.begin(), v.end(), mt);
  v.erase(v.begin()+num, v.end());
  return v;
}

void ImageExpansion::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QLinearGradient linearGrad(QPointF(0, 180), QPointF(180, 180));
    QConicalGradient conicalGradient(200, 200, 0);
    QRadialGradient  radialGradient(400,400,200,400,200);
    double ratio_low = double(hue_low)/(double(hue_up)+double(hue_low));
    int w_pos=790,h_pos=10;//default 790,10
    int i=0,j=0;
    QColor *qcolor = new QColor(2);
    QRect rect_linear(0,0,360,255);
    QLinearGradient hoge(0,0,rect_linear.width(),rect_linear.height());

    QPoint draw_point(0,0);
    QImage QT_object_image((uchar *)object_image.data, object_image.cols, object_image.rows,(int)object_image.step, QImage::Format_RGB888);
    painter.drawImage(draw_point,QT_object_image);
    for (i=0;i<rect_linear.width();i++){
        if(hue_low <= hue_up){
            for(j=0;j<rect_linear.height();j++){
                qcolor->setHsv(hue_low + i*((hue_up - hue_low)/360.0),saturation_up-j*((saturation_up-saturation_low)/255.0),255);
                painter.setPen(qcolor->toRgb());
                painter.drawPoint(w_pos+i,h_pos+j);
                qcolor->setHsv(hue_low + i*((hue_up - hue_low)/360.0),255,lightness_up-j*((lightness_up-lightness_low)/255.0));
                painter.setPen(qcolor->toRgb());
                painter.drawPoint(w_pos+i,h_pos+j+300);
            }
        }
        else{
            for(j=0;j<rect_linear.height();j++){
                  if(i*(360 - hue_up + hue_low) < ratio_low){
                      qcolor->setHsv(hue_up + i*((360 + hue_up - hue_low)/360.0),saturation_up-j*((saturation_up-saturation_low)/255.0),255);
                      painter.setPen(qcolor->toRgb());
                      painter.drawPoint(w_pos+i,h_pos+j);
                      qcolor->setHsv(hue_up + i*((360 + hue_up - hue_low)/360.0),255,lightness_up-j*((lightness_up-lightness_low)/255.0));
                      painter.setPen(qcolor->toRgb());
                      painter.drawPoint(w_pos+i,h_pos+j+300);

                  }
                  else{
                      qcolor->setHsv(hue_low+ i*(360 + hue_up - hue_low)/360.0,saturation_up-j*((saturation_up-saturation_low)/255.0),255);
                      painter.setPen(qcolor->toRgb());
                      painter.drawPoint(w_pos+i,h_pos+j);
                      qcolor->setHsv(hue_low + i*(360 + hue_up - hue_low)/360.0,255,lightness_up-j*((lightness_up-lightness_low)/255.0));
                      painter.setPen(qcolor->toRgb());
                      painter.drawPoint(w_pos+i,h_pos+j+300);
                  }
            }
        }
    }
}

/*///############# image processing ###############///*/

void ImageExpansion::extractObjectArea(){
    //std::cout<<"IMAGES is "<<IMAGES[image_count]<<std::endl;
    origin_image = cv::imread(IMAGES[image_count],1);
    whiteback_image = cv::imread("./white_back.jpg",1);
    origin_image.resize(480,640);
    cv::resize(whiteback_image,whiteback_image,cv::Size(),1.333,1);
    int j=0,i=0,max=0;
    cv::Mat mask1;
    cv::Mat mask2;
    cv::Mat background_image;
    cv::Mat copy_mat;
    cv::Rect rect;
    cv::Size size(640,480);
    cv::Mat closed_copy;
    uchar lut[256];
    double gm = 1.0 /gamma;
    for(j=0;j<256;j++){
        lut[j]=pow(1.0*j/255,gm)*255;
    }
    cv::cvtColor(origin_image,origin_image,cv::COLOR_BGR2HSV);
    //std::cout<<"hue up is "<<hue_up<<" _low is "<<hue_low<<std::endl;
    //std::cout<<"saturation_up is "<<saturation_up<<" raturation_low is "<<saturation_low<<std::endl;
    //std::cout<<"lightness_up is "<<lightness_up<<" lightness_low is "<<lightness_low<<std::endl;
    if(hue_low > hue_up){
        cv::inRange(origin_image,cv::Scalar(hue_low/2,saturation_low,lightness_low),cv::Scalar(180,saturation_up,lightness_up),mask1);
        cv::inRange(origin_image,cv::Scalar(0,saturation_low,lightness_low),cv::Scalar(hue_up/2,saturation_up,lightness_up),mask2);//koko
        cv::bitwise_or(mask1,mask2,image);
    }
    else{
            cv::inRange(origin_image,cv::Scalar(hue_low/2,saturation_low,lightness_low),cv::Scalar(hue_up/2,saturation_up,lightness_up),image);
    }
    for(j=0;j<256;j++){
        lut[j]=pow(1.0*j/255,gm)*255;
    }
    cv::cvtColor(origin_image,origin_image,cv::COLOR_HSV2BGR);
    cv::LUT(origin_image,cv::Mat(cv::Size(256,1),CV_8U,lut),origin_image);
    cv::cvtColor(origin_image,origin_image,cv::COLOR_BGR2HSV);
    cv::morphologyEx(image,closed_image,cv::MORPH_CLOSE,kernel_c1,cv::Point(-1,-1),1,0);//make closed image
    cv::bitwise_not(closed_image,reverced_image);//make reverced_image
    cv::bitwise_and(origin_image,origin_image,object_image,reverced_image);//make object image
    cv::cvtColor(object_image,object_image,cv::COLOR_HSV2BGR);//transform color coordinate
    reverced_image.copyTo(copy_mat);
    cv::morphologyEx(reverced_image,reverced_image,cv::MORPH_CLOSE,kernel_c2,cv::Point(-1,-1),1,0);
    cv::bitwise_not(reverced_image,closed_image);
    cv::bitwise_and(origin_image,origin_image,object_image,reverced_image);
    cv::cvtColor(object_image,object_image,cv::COLOR_HSV2BGR);//BGR
    object_image.copyTo(blackback_image_copy);
    cv::resize(closed_image,closed_image,size);
    cv::resize(reverced_image,reverced_image,size);
    cv::cvtColor(whiteback_image,whiteback_image,cv::COLOR_BGR2HSV);//BGR
    cv::bitwise_and(whiteback_image,whiteback_image,background_image,closed_image);
    cv::cvtColor(background_image,background_image,cv::COLOR_HSV2BGR);
    cv::bitwise_or(object_image,background_image,object_image);
    cv::bitwise_and(whiteback_image,whiteback_image,whiteback_image,closed_image);
    cv::bitwise_or(whiteback_image,object_image,object_image,closed_image);
    cv::cvtColor(object_image,object_image,cv::COLOR_BGR2RGB);
    cv::findContours(copy_mat,contours,hierarchy,cv::RETR_TREE,cv::CHAIN_APPROX_SIMPLE,cv::Point(-1,-1));//received_image
    if(contours.size()>0){
        for(i=0;i<int(contours.size()-1);i++){
            if(contours[max].size()<contours[i+1].size()){
                max = i+1;
            }
        }
        rect = cv::boundingRect(contours[max]);
        if(rect_flag == 1){
            cv::rectangle(object_image,cv::Point(rect.x,rect.y),cv::Point((rect.x+rect.width),(rect.y+rect.height)),cv::Scalar(0,255,0),10);
        }
        convert_x = float(rect.x+rect.x+rect.width)/2.0/float(object_image.cols);
        convert_y = float(rect.y+rect.y+rect.height)/2.0/float(object_image.rows);
        convert_w = float(rect.width)/float(object_image.cols);
        convert_h = float(rect.height)/float(object_image.rows);
        //std::cout<<"x is "<<convert_x<<" y is "<<convert_y<<" w is "<<convert_w<<" h is "<<convert_h<<std::endl;
    }
}

/*///############# to select file path and image ###############///*/

MainDialog::MainDialog(QWidget* parent)
    : QDialog(parent)
{
    quit = true;
    layout = new QGridLayout;
    label1 = new QLabel(tr("please set first image file") );
    pushButton1 = new QPushButton(tr("choose a file"));
    lineEdit1 = new QLineEdit;
    lineEdit1->setText(QString::fromStdString(IMAGE_FULLPATH_AND_NAME));
    label4 = new QLabel(tr("please set dirctory that owns many background images"));
    pushButton4 = new QPushButton(tr("choose a file"));
    lineEdit4 = new QLineEdit;
    lineEdit4->setText(QString::fromStdString(BACKGROUND_IMAGE_PATH));
    pushButton_set = new QPushButton(tr("set"));
    layout->addWidget(label1,0,0);
    layout->addWidget(lineEdit1,0,1);
    layout->addWidget(pushButton1,0,2);
    layout->addWidget(label4,3,0);
    layout->addWidget(lineEdit4,3,1);
    layout->addWidget(pushButton4,3,2);
    layout->addWidget(pushButton_set,5,2);

    setLayout(layout);
    connect(pushButton1,SIGNAL(clicked()),this,SLOT(chooseImageFile()));
    connect(pushButton4,SIGNAL(clicked()),this,SLOT(chooseBPath()));
    connect(pushButton_set,SIGNAL(clicked()),this,SLOT(next()));
}

MainDialog::~MainDialog(){
    delete layout;
}

void MainDialog::chooseMakeDir()
{
    QString qstr = "if you have not image dir,\nyou had better make new dir now.\n\nname example) 001,002,003 etc..";
    makeMessage(qstr);
    QString fpath = QFileDialog::getExistingDirectory(this,tr("chose a File Path"),"/home/");
    //std::cout<<"file path is"<<fpath.toStdString()<<std::endl;
    lineEdit3->setText(fpath);
}

void MainDialog::chooseTPath()
{
    QString fpath = QFileDialog::getExistingDirectory(this,tr("chose a File Path"),"/home/");
    //std::cout<<"file path is"<<fpath.toStdString()<<std::endl;
    lineEdit2->setText(fpath);
}

void MainDialog::chooseBPath(){
    QString fpath = QFileDialog::getExistingDirectory(this,tr("chose a File Path"),"/home/");
    //std::cout<<"file path is"<<fpath.toStdString()<<std::endl;
    lineEdit4->setText(fpath);
}

void MainDialog::chooseImageFile(){
    int i=0,i_=0,i__=0;
    IMAGE_FILE_PATH = "";
    QString path;
    fullpathname = QFileDialog::getOpenFileName(this,tr("Open a File"), "/home/",tr("png File (*.png);;jpg File (*.jpg);;All Files (*.*)"));
    //std::cout<<fullpathname.toStdString()<<std::endl;
    if(fullpathname == ""){
    }
    else{
        for(i=0;fullpathname.toStdString()[i]!='\0';i++){}
        for(i_=i;fullpathname.toStdString()[i_]!='/';i_--){}
        i_++;
        for(i__=0;i__<i_;i__++){
            path[i__] = fullpathname.toStdString()[i__];
        }
    }
    IMAGE_FILE_PATH = path.toStdString();
    lineEdit1->setText(fullpathname);
}

void MainDialog::next(){
    QString fp = lineEdit1->text();
    QString bp = lineEdit4->text();
    QString qstr = "";
    std::string test;
    std::string train;
    IMAGE_FULLPATH_AND_NAME = fp.toStdString();
    //std::cout<<"full path name is "<<IMAGE_FULLPATH_AND_NAME<<std::endl;
    BACKGROUND_IMAGE_PATH = bp.toStdString();
    if(checkFileExistence(IMAGE_FULLPATH_AND_NAME)&&checkFileExistence(BACKGROUND_IMAGE_PATH)){
        //std::cout<<"all set file exists"<<std::endl;
        //test = TEXT_FILE_PATH;
        //test += "/test.txt";
        //train = TEXT_FILE_PATH;
        //train += "/train.txt";
        //std::cout<<text<<std::endl;
        /*
        if(checkFileExistence(test)&&checkFileExistence(train)){
            qstr += "text file already exists.        \nCan I overwrite text file?\n";
            res = checkText(qstr);
        }
        if(res == true){
            std::remove(test.c_str());
            std::remove(train.c_str());
            if(!std::ofstream(test.c_str())||!std::ofstream(train.c_str())){
                //std::cout<<"you can not make a file"<<std::endl;
                //QDialog::close();
                qstr = "you can not make a text file.\nplease reset file path";
                makeMessage(qstr);
                //MainDialog::show();
            }
            else{
                qstr = "make test.txt       \n          train.txt\n\nin ";
                qstr += QString::fromStdString(TEXT_FILE_PATH);
                //qstr +="\n\nmake expanded images\n\nin ";
                qstr +=QString::fromStdString(EXPANDED_IMAGE_PATH);
                makeMessage(qstr);
                QDialog::close();

            }
        }
        */
        quit = false;
        QDialog::close();

    }
    else{
        qstr = "Invalid path or file name\n\nPlease reset path or file name";
        makeMessage(qstr);
    }
}

bool MainDialog::checkFileExistence(const std::string& str)
{
    std::ifstream ifs(str);
    return ifs.is_open();
}

void MainDialog::makeMessage(QString qstr_){
    msgBox = new QMessageBox;
    msgBox->setWindowTitle("Message");
    msgBox->setText(qstr_);
    msgBox->exec();

}

bool MainDialog::checkText(QString text_){
    int res = 0;
    msgBox = new QMessageBox;
    msgBox->setWindowTitle("Message");
    msgBox->setText(text_);
    msgBox->addButton(QMessageBox::Yes);
    msgBox->addButton(QMessageBox::No);
    res = msgBox->exec();
    if(res == QMessageBox::Yes){
        return true;
    }
    else{
        return false;
    }

}

void MainDialog::closeEvent(QCloseEvent *c){
    if(quit == true){
        exit(0);
    }
}

