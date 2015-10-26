#ifndef _CSCREENSHOTVIEW_H_
#define _CSCREENSHOTVIEW_H_

#include <QGraphicsView>

#include "cscreenpublic.h"
#include "cscreeneditortoolbaritem.h"
#include "clogsetting.h"

class CScreenShotScene;
class CScreenSelectRectItem;
class CScreenEditorWidget;
class CScreenEditorToolbarItem;
class CScreenRectItem;
class CScreenTooltipItem;

class CScreenShotView : public QGraphicsView
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER

public:
    CScreenShotView(QScreen *screen,QWidget *parent = 0);
    ~CScreenShotView();
    void startSCreenShot();
    void setLocked(bool locked);
    QPixmap getPixmap();
    void setPreviewItemHidden(bool isHidden);

protected:
    bool event(QEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void leaveEvent(QEvent *event);
    CScreenRectItem *createRectItem();

private:
    void drawPixmap(const QPixmap &pixmap);
    QPointF getPointToSelectedItem(const QPointF &point);
    QPointF getPointFromSelectedItem(const QPointF &point);
    QRect getPositiveRect(const QPointF &startPoint,const QPointF &endPoint);
    void updateToolbarPosition();
    void updateTooltipItem();
    void updatePreviewItem(const QPoint &pos);
    void setShotStatus(CScreenShotStatus status);
    QPixmap createPixmap();
    QString getSizeString(const QSize &size) const;
    QRgb getPixmapPosRgb(const QPixmap &pixmap,const QPoint &pos);
    void doFinished();

private slots:
    void onButtonClicked(CScreenButtonType type);
    void onFinishTimerOut();

signals:
    void sigStatusChanged(CScreenShotStatus status);
    void sigPreviewItemShow();

private:
    QScreen *m_desktopScreen;
    CScreenShotScene *m_screen;
    QGraphicsPixmapItem *m_backgroundItem;
    CScreenSelectRectItem *m_selectRectItem;
    CScreenEditorToolbarItem *m_toolbarItem;
    CScreenRectItem *m_currentRectItem;
    CScreenTooltipItem *m_tooltipSizeItem;
    QGraphicsPixmapItem *m_previewItem;

    CScreenPositionType m_positionType;
    CScreenShotStatus m_shotStatus;
    Qt::WindowFlags m_flags;
    //====
    bool m_isPressed;
    bool m_isLocked;
    QPoint m_startPoint;
    QPoint m_endPoint;
    QPixmap m_backgroundPixmap;
    QPixmap m_desktopPixmap;
    qreal m_sx;
    qreal m_sy;
    QRectF m_selectRect;
    QPixmap m_pixmap;
//    QList<QGraphicsRectItem*> m_editorItemList;
    static const int m_marginSelectedWidthToolbar = 4;
    static const int m_marginSelectedWidthTooltip = 4;
    static const int m_minSelectSize = 1;
    static const int m_previewItemWidth = 101;
    static const int m_previewItemPixmapHeight = 83;
    static const int m_previewItemTextHeight = 32;
    static const int m_previewPointSize = 11;
    static const int m_previewLineWidth = 5;
    static const int m_previewItemDx = 20;
    static const int m_previewItemDy = 20;
};

#endif // _CSCREENSHOTVIEW_H_

