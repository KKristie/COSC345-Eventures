// Copyright 2023 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

/*!
* @file Map_display.h
* @brief This file contains the declaration of the Map_display class,
* which is responsible for displaying a map on screen at runtime.
*/

#ifndef MAP_DISPLAY_H
#define MAP_DISPLAY_H

namespace Esri::ArcGISRuntime {
class Map;
class MapQuickView;

class GraphicsOverlay;

} // namespace Esri::ArcGISRuntime

#include <QObject>
#include "Point.h"

Q_MOC_INCLUDE("MapQuickView.h")

class Map_display : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Esri::ArcGISRuntime::MapQuickView* mapView READ mapView WRITE setMapView NOTIFY mapViewChanged)

public:
    explicit Map_display(QObject* parent = nullptr);
    ~Map_display() override;
    Q_INVOKABLE void searchHandler(const QString &text);
    Q_INVOKABLE void setZoom(bool magnify);


signals:
    void mapViewChanged();


private:
    Esri::ArcGISRuntime::MapQuickView* mapView() const;
    void setMapView(Esri::ArcGISRuntime::MapQuickView* mapView);
    void setupViewpoint();

    Esri::ArcGISRuntime::Point createGraphics(Esri::ArcGISRuntime::GraphicsOverlay* overlay);
    void transition_coords(Esri::ArcGISRuntime::Point point);

    Esri::ArcGISRuntime::Map* m_map = nullptr;
    Esri::ArcGISRuntime::MapQuickView* m_mapView = nullptr;
};

#endif // MAP_DISPLAY_H
