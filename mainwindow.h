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
 * \file   mainwindow.h
 *         Implements the equalizer H(w) computation
 * \author Pablo Alvarado/Jose Miguel Barboza
 * \date   2010.12.12/2017.05.26
 *
 * $Id: mainwindow.h $
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QCategoryAxis>

#include "dspsystem.h"

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    /**
      *Tolerance value
      */
    static const float Epsilon;

     /**
      * Verbose flag
      */
     bool verbose_;

     /**
      * Timer used to recompute the filter once the user changes the
      * values
      */
     QTimer *timer_;

     /**
      * List of selected files so far
      */
     QStringList selectedFiles_;

     /**
      * Pointer to an inherited class of processor, which does
      * all the real work.
      */
     dspSystem* dsp_;

     /**
      *DSP change
      */
     bool dspChanged_;

     QLineSeries* series;
     QChart* chart;
     QCategoryAxis* axisX;
     QCategoryAxis* axisY;
     
   private slots:
     void on_fileEdit_returnPressed();
     void on_fileButton_clicked();
     void on_volumeSlider_valueChanged(int value);
     void on_filtro31HzSlider_valueChanged(int value);
     void on_filtro63HzSlider_valueChanged(int value);
     void on_filtro125HzSlider_valueChanged(int value);
     void on_filtro250HzSlider_valueChanged(int value);
     void on_filtro500HzSlider_valueChanged(int value);
     void on_filtro1kHzSlider_valueChanged(int value);
     void on_filtro2kHzSlider_valueChanged(int value);
     void on_filtro4kHzSlider_valueChanged(int value);
     void on_filtro8kHzSlider_valueChanged(int value);
     void on_filtro16kHzSlider_valueChanged(int value);

     void update();
     void on_presetsComboBox_currentIndexChanged(const QString &arg1);
     void updateFTChart();
};




#endif // MAINWINDOW_H
