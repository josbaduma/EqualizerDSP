/*
 * DSP Example is part of the DSP Lecture at TEC-Costa Rica
 * Copyright (C) 2010  Pablo Alvarado
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * \file   mainwindow.cpp
 *         Implements the equalizer H(w) computation
 * \author Pablo Alvarado
 * \date   2010.12.12
 *
 * $Id: equalizer.cpp $
 */


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jack.h"
#include <string>


#undef _DSP_DEBUG
#define _DSP_DEBUG

#ifdef _DSP_DEBUG
#define _debug(x) std::cerr << x
#include <iostream>
#else
#define _debug(x)
#endif


/**
 * Precision used by trimming
 */
const float MainWindow::Epsilon = 0.001;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    series(new QLineSeries),
    chart(new QChart),
    axisX(new QCategoryAxis()),
    axisY(new QCategoryAxis()),
    verbose_(false),
    dspChanged_(true)
{
    ui->setupUi(this);
    /*
     * Set up a timer 4 times in a second to check if the user
     * changed the equalizer values, and if so, then create a new
     * filter response
     */
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(update()));
    timer_->start(250);

    //Fondo de grafica
    QLinearGradient backgroundGradient;
    backgroundGradient.setStart(QPointF(0, 0));
    backgroundGradient.setFinalStop(QPointF(0, 1));
    backgroundGradient.setColorAt(0.0, QRgb(0xd2d0d1));
    backgroundGradient.setColorAt(1.0, QRgb(0x4c4547));
    backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    chart->setBackgroundBrush(backgroundGradient);

    //colocacion de ajuste de valores de la grafica
    series->append(0,24);
    series->append(0,0);
    series->append(0,ui->filtro31HzSlider->value());
    series->append(3,ui->filtro31HzSlider->value());
    series->append(6,ui->filtro63HzSlider->value());
    series->append(9,ui->filtro125HzSlider->value());
    series->append(12,ui->filtro250HzSlider->value());
    series->append(15,ui->filtro500HzSlider->value());
    series->append(18,ui->filtro1kHzSlider->value());
    series->append(21,ui->filtro2kHzSlider->value());
    series->append(24,ui->filtro4kHzSlider->value());
    series->append(27,ui->filtro8kHzSlider->value());
    series->append(30,ui->filtro16kHzSlider->value());
    chart->addSeries(series);
    //Ajuste de Rangos
    axisX->setRange(0,30);
    axisY->setRange(0,30);
    // puntero para la visualizacion
    QChartView *chartView = new QChartView(chart);
    chart->legend()->hide();
    //Labels del eje x
    axisX->append("31.5",3);
    axisX->append("63",6);
    axisX->append("125",9);
    axisX->append("250",12);
    axisX->append("500",15);
    axisX->append("1K",18);
    axisX->append("2K",21);
    axisX->append("4K",24);
    axisX->append("8K",27);
    axisX->append("16K",30);
    //Ajuste de ejes
    chart->setAxisX(axisX,series);
    chart->setAxisY(axisY,series);
    chart->setTitle("Función de Transferencía");
    //Colocacion en el layout recrear un layout
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->adjustSize();
    ui->chartsLayout->addWidget(chartView);


    dsp_ = new dspSystem;
    jack::init(dsp_);

    // parse some command line arguments
    QStringList argv(QCoreApplication::arguments());

    QStringList::const_iterator it(argv.begin());
    while(it!=argv.end()) {
        if ((*it)=="-v" || (*it)=="--verbose") {
            verbose_=true;
        } else if ((*it).indexOf(".wav",0,Qt::CaseInsensitive)>0) {
            ui->fileEdit->setText(*it);
            std::string tmp(qPrintable(*it));
            jack::playAlso(tmp.c_str());
        }
        ++it;
    }

}


MainWindow::~MainWindow()
{
    jack::close();
    delete timer_;
    delete ui;
    delete dsp_;
}

void MainWindow::update() {
    if(dspChanged_){
        _debug("Updating" << std::endl);

        dspChanged_=false;
    }
    
}


void MainWindow::on_volumeSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolume(value);
    ;
}

void MainWindow::on_filtro31HzSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->update31HzFilter(value - 12);
    this->updateFTChart();
    ;
}

void MainWindow::on_filtro63HzSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->update63HzFilter(value - 12);
    this->updateFTChart();
    ;
}

void MainWindow::on_filtro125HzSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->update125HzFilter(value - 12);
    this->updateFTChart();
    ;
}

void MainWindow::on_filtro250HzSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->update250HzFilter(value - 12);
    this->updateFTChart();
    ;
}

void MainWindow::on_filtro500HzSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->update500HzFilter(value - 12);
    this->updateFTChart();
    ;
}

void MainWindow::on_filtro1kHzSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->update1kHzFilter(value - 12);
    this->updateFTChart();
    ;
}

void MainWindow::on_filtro2kHzSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->update2kHzFilter(value - 12);
    this->updateFTChart();
    ;
}

void MainWindow::on_filtro4kHzSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->update4kHzFilter(value -12);
    this->updateFTChart();
    ;
}

void MainWindow::on_filtro8kHzSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->update8kHzFilter(value - 12);
    this->updateFTChart();
    ;
}

void MainWindow::on_filtro16kHzSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->update16kHzFilter(value - 12);
    this->updateFTChart();
    ;
}


void MainWindow::on_fileButton_clicked() {
    selectedFiles_ =
            QFileDialog::getOpenFileNames(this,
                                          "Select one or more audio files to open",
                                          ui->fileEdit->text(),
                                          "WAV Files (*.wav)");

    if (!selectedFiles_.empty()) {
        ui->fileEdit->setText(*selectedFiles_.begin());

        jack::stopFiles();
        QStringList::iterator it;
        for (it=selectedFiles_.begin();it!=selectedFiles_.end();++it) {
            std::string tmp(qPrintable(*it));
            jack::playAlso(tmp.c_str());
        }
    }
}


void MainWindow::on_fileEdit_returnPressed() {
    jack::stopFiles();
    std::string tmp(qPrintable(ui->fileEdit->text()));
    if (!tmp.empty()) {
        jack::playAlso(tmp.c_str());
    }
}

void MainWindow::on_presetsComboBox_currentIndexChanged(const QString &arg1)
{

    if (ui->presetsComboBox->currentText()=="Default"){
        ui->filtro31HzSlider->setValue(12);
        ui->filtro63HzSlider->setValue(12);
        ui->filtro125HzSlider->setValue(12);
        ui->filtro250HzSlider->setValue(12);
        ui->filtro500HzSlider->setValue(12);
        ui->filtro1kHzSlider->setValue(12);
        ui->filtro2kHzSlider->setValue(12);
        ui->filtro4kHzSlider->setValue(12);
        ui->filtro8kHzSlider->setValue(12);
        ui->filtro16kHzSlider->setValue(12);
    }
    if (ui->presetsComboBox->currentText()=="Classical"){
        ui->filtro31HzSlider->setValue(12);
        ui->filtro63HzSlider->setValue(12);
        ui->filtro125HzSlider->setValue(12);
        ui->filtro250HzSlider->setValue(12);
        ui->filtro500HzSlider->setValue(12);
        ui->filtro1kHzSlider->setValue(12);
        ui->filtro2kHzSlider->setValue(8);
        ui->filtro4kHzSlider->setValue(8);
        ui->filtro8kHzSlider->setValue(8);
        ui->filtro16kHzSlider->setValue(6);
    }
    if (ui->presetsComboBox->currentText()=="Club"){
        ui->filtro31HzSlider->setValue(12);
        ui->filtro63HzSlider->setValue(12);
        ui->filtro125HzSlider->setValue(16);
        ui->filtro250HzSlider->setValue(15);
        ui->filtro500HzSlider->setValue(15);
        ui->filtro1kHzSlider->setValue(15);
        ui->filtro2kHzSlider->setValue(14);
        ui->filtro4kHzSlider->setValue(12);
        ui->filtro8kHzSlider->setValue(12);
        ui->filtro16kHzSlider->setValue(12);
    }
    if (ui->presetsComboBox->currentText()== "Dance"){
        ui->filtro31HzSlider->setValue(17);
        ui->filtro63HzSlider->setValue(16);
        ui->filtro125HzSlider->setValue(13);
        ui->filtro250HzSlider->setValue(12);
        ui->filtro500HzSlider->setValue(12);
        ui->filtro1kHzSlider->setValue(9);
        ui->filtro2kHzSlider->setValue(8);
        ui->filtro4kHzSlider->setValue(8);
        ui->filtro8kHzSlider->setValue(12);
        ui->filtro16kHzSlider->setValue(12);
    }
    if (ui->presetsComboBox->currentText()== "Full Bass & Trebble"){
        ui->filtro31HzSlider->setValue(16);
        ui->filtro63HzSlider->setValue(15);
        ui->filtro125HzSlider->setValue(12);
        ui->filtro250HzSlider->setValue(8);
        ui->filtro500HzSlider->setValue(9);
        ui->filtro1kHzSlider->setValue(13);
        ui->filtro2kHzSlider->setValue(17);
        ui->filtro4kHzSlider->setValue(18);
        ui->filtro8kHzSlider->setValue(19);
        ui->filtro16kHzSlider->setValue(19);
    }
    if (ui->presetsComboBox->currentText()== "Full Treble"){
        ui->filtro31HzSlider->setValue(7);
        ui->filtro63HzSlider->setValue(7);
        ui->filtro125HzSlider->setValue(7);
        ui->filtro250HzSlider->setValue(10);
        ui->filtro500HzSlider->setValue(13);
        ui->filtro1kHzSlider->setValue(18);
        ui->filtro2kHzSlider->setValue(21);
        ui->filtro4kHzSlider->setValue(21);
        ui->filtro8kHzSlider->setValue(21);
        ui->filtro16kHzSlider->setValue(22);
    }
    if (ui->presetsComboBox->currentText()=="Pop"){
        ui->filtro31HzSlider->setValue(13);
        ui->filtro63HzSlider->setValue(15);
        ui->filtro125HzSlider->setValue(16);
        ui->filtro250HzSlider->setValue(17);
        ui->filtro500HzSlider->setValue(15);
        ui->filtro1kHzSlider->setValue(12);
        ui->filtro2kHzSlider->setValue(11);
        ui->filtro4kHzSlider->setValue(11);
        ui->filtro8kHzSlider->setValue(13);
        ui->filtro16kHzSlider->setValue(13);
    }
    if (ui->presetsComboBox->currentText()=="Reggae"){
        ui->filtro31HzSlider->setValue(12);
        ui->filtro63HzSlider->setValue(12);
        ui->filtro125HzSlider->setValue(12);
        ui->filtro250HzSlider->setValue(9);
        ui->filtro500HzSlider->setValue(12);
        ui->filtro1kHzSlider->setValue(15);
        ui->filtro2kHzSlider->setValue(15);
        ui->filtro4kHzSlider->setValue(12);
        ui->filtro8kHzSlider->setValue(12);
        ui->filtro16kHzSlider->setValue(12);
    }
    if (ui->presetsComboBox->currentText()=="Rock"){
        ui->filtro31HzSlider->setValue(16);
        ui->filtro63HzSlider->setValue(15);
        ui->filtro125HzSlider->setValue(9);
        ui->filtro250HzSlider->setValue(8);
        ui->filtro500HzSlider->setValue(11);
        ui->filtro1kHzSlider->setValue(14);
        ui->filtro2kHzSlider->setValue(17);
        ui->filtro4kHzSlider->setValue(18);
        ui->filtro8kHzSlider->setValue(18);
        ui->filtro16kHzSlider->setValue(18);
    }
    if (ui->presetsComboBox->currentText()=="Techno"){
        ui->filtro31HzSlider->setValue(16);
        ui->filtro63HzSlider->setValue(15);
        ui->filtro125HzSlider->setValue(12);
        ui->filtro250HzSlider->setValue(9);
        ui->filtro500HzSlider->setValue(10);
        ui->filtro1kHzSlider->setValue(12);
        ui->filtro2kHzSlider->setValue(17);
        ui->filtro4kHzSlider->setValue(18);
        ui->filtro8kHzSlider->setValue(18);
        ui->filtro16kHzSlider->setValue(17);
    }

}

void MainWindow::updateFTChart() {
    chart->removeSeries(series);
    series->removePoints(0,13);

    series->append(0,24);
    series->append(0,0);
    series->append(0,ui->filtro31HzSlider->value());
    series->append(3,ui->filtro31HzSlider->value());
    series->append(6,ui->filtro63HzSlider->value());
    series->append(9,ui->filtro125HzSlider->value());
    series->append(12,ui->filtro250HzSlider->value());
    series->append(15,ui->filtro500HzSlider->value());
    series->append(18,ui->filtro1kHzSlider->value());
    series->append(21,ui->filtro2kHzSlider->value());
    series->append(24,ui->filtro4kHzSlider->value());
    series->append(27,ui->filtro8kHzSlider->value());
    series->append(30,ui->filtro16kHzSlider->value());
    chart->addSeries(series);
}
