#ifndef BIRD_H
#define BIRD_H

#include <QGraphicsItem>
#include <QPen>
#include <QRectF>
#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <Qt>
#include <filesystem>
#include <iostream>
#include <QGraphicsItem>
#include <random>

class bird : public QGraphicsObject
{
  Q_OBJECT

  public:
  bird(int xP, int yP, double set[2], QGraphicsItem *parent = 0);
  int X;
  // Added in; haven't tested compatibility
  QTransform rotating;
  QPixmap img = QPixmap("C:/Users/Daddy/Desktop/The Code Box/CPP Docs/first cpp/Gui/Infestation/imgs/bird1.png");
  int Y;
  bool dead = false;
  QRectF &targetRect = *new QRectF(0,0,0,0);
  protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event);

  void hoverMoveEvent(QGraphicsSceneHoverEvent *event);

  QRectF boundingRect() const;

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


};

#endif // BIRD_H
