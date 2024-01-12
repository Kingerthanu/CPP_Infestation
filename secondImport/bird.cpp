#include "bird.h"

bird::bird(int xP, int yP, double set[2], QGraphicsItem *parent)
    : QGraphicsObject(parent)

  {
    this->setPos(xP*750, yP);
    this->setAcceptHoverEvents(true);
    this->setData(77, set[0]);
    this->setData(66, set[1]);
    this->setData(78, 0);
  }

  QRectF bird::boundingRect() const
  {
    return *new QRectF(this->x(), this->y(), 50,50);
  }

  void bird::hoverMoveEvent(QGraphicsSceneHoverEvent *)
  {
    this->setCursor(QCursor(Qt::PointingHandCursor));
  }

  void bird::mousePressEvent(QGraphicsSceneMouseEvent *)
  {
    this->dead = true;
    this->setData(78, 1);
    this->setData(77, 0);
    this->setData(66, 1);
  }

  void bird::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
  {
    if(this->dead){
        rotating.rotate(180);
        this->img = this->img.transformed(rotating);
        this->dead = false;
    }
    painter->drawPixmap(this->x(), this->y(), 50,50, this->img);
  }
