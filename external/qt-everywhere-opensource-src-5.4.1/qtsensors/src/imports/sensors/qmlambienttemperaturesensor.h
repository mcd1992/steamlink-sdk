/****************************************************************************
**
** Copyright (C) 2013 Research In Motion
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtSensors module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia. For licensing terms and
** conditions see http://qt.digia.com/licensing. For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights. These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef QMLAMBIENTTEMPERATURESENSOR_H
#define QMLAMBIENTTEMPERATURESENSOR_H

#include "qmlsensor.h"

QT_BEGIN_NAMESPACE

class QAmbientTemperatureSensor;

class QmlAmbientTemperatureSensor : public QmlSensor
{
    Q_OBJECT
public:
    explicit QmlAmbientTemperatureSensor(QObject *parent = 0);
    ~QmlAmbientTemperatureSensor();

private:
    QSensor *sensor() const Q_DECL_OVERRIDE;
    QmlSensorReading *createReading() const Q_DECL_OVERRIDE;

    QAmbientTemperatureSensor *m_sensor;
};

class QmlAmbientTemperatureReading : public QmlSensorReading
{
    Q_OBJECT
    Q_PROPERTY(qreal temperature READ temperature NOTIFY temperatureChanged)
public:
    explicit QmlAmbientTemperatureReading(QAmbientTemperatureSensor *sensor);
    ~QmlAmbientTemperatureReading();

    qreal temperature() const;

Q_SIGNALS:
    void temperatureChanged();

private:
    QSensorReading *reading() const Q_DECL_OVERRIDE;
    void readingUpdate() Q_DECL_OVERRIDE;

    QAmbientTemperatureSensor *m_sensor;
    qreal m_temperature;
};

QT_END_NAMESPACE
#endif