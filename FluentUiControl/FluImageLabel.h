#pragma once

#include <QLabel>
#include <QWidget>
#include <QImage>
#include <QImageReader>
#include <QMovie>
#include <QPainter>
#include <QPainterPath>

class FluImageLabel : public QLabel
{
    Q_OBJECT
    // 构造函数
  public:
    FluImageLabel(QWidget* parent = nullptr) : QLabel(parent)
    {
        m_image = QImage();
        setBorderRadius(0, 0, 0, 0);
        _postInit();
    }

    FluImageLabel(QString image, QWidget* parent = nullptr) : QLabel(parent)
    {
        //  m_image = QImage();
        setBorderRadius(0, 0, 0, 0);
        setImage(image);
        _postInit();
    }

    FluImageLabel(QImage image, QWidget* parent = nullptr) : QLabel(parent)
    {
        setBorderRadius(0, 0, 0, 0);
        setImage(image);
        _postInit();
    }

    FluImageLabel(QPixmap image, QWidget* parent = nullptr) : QLabel(parent)
    {
        setBorderRadius(0, 0, 0, 0);
        setImage(image);
        _postInit();
    }

    void _postInit()
    {
    }

    void setBorderRadius(int topLeft, int topRight, int bottomLeft, int bottmRight)
    {
        m_topLeftRadius = topLeft;
        m_topRightRadius = topRight;
        m_bottomLeftRadius = bottomLeft;
        m_bottomRightRadius = bottmRight;

        update();
    }

    void setImage(QString image)
    {
        QImageReader reader = QImageReader(image);
        if (reader.supportsAnimation())
            setMovie(new QMovie(image));
        else
            m_image = reader.read();
        setFixedSize(m_image.size());
        update();
    }

    void setImage(QPixmap pixmap)
    {
        m_image = pixmap.toImage();
        setFixedSize(m_image.size());
        update();
    }

    void setImage(QImage image)
    {
        m_image = m_image;
        setFixedSize(m_image.size());
        update();
    }

    void setPixmap(QPixmap pixmap)
    {
        setImage(pixmap);
    }

    QPixmap getPixmap()
    {
        return QPixmap::fromImage(m_image);
    }

    void setMovie(QMovie* tmpM)
    {
        QLabel::setMovie(tmpM);
        movie()->start();
        m_image = movie()->currentImage();
        connect(movie(), &QMovie::frameChanged, this, &FluImageLabel::_onFrameChanged);
    }

    void scaledToWidth(int width)
    {
        if (isNull())
            return;

        int h = 1.0 * width / m_image.width() * m_image.height();
        setFixedSize(width, h);

        if (movie())
            movie()->setScaledSize(QSize(width, h));
    }

    void scaledToHeight(int height)
    {
        if (isNull())
            return;

        int w = 1.0 * height / m_image.height() * m_image.width();
        setFixedSize(w, height);
        if (movie())
            movie()->setScaledSize(QSize(w, height));
    }

    bool isNull()
    {
        return m_image.isNull();
    }

  signals:
    void clicked();
  public slots:
    void _onFrameChanged(int index)
    {
        m_image = movie()->currentImage();
        update();
    }

  protected:
    void mouseReleaseEvent(QMouseEvent* ev)
    {
        QLabel::mouseReleaseEvent(ev);
        emit clicked();
    }

    void paintEvent(QPaintEvent* event)
    {
        if (isNull())
            return;

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        QPainterPath path = QPainterPath();
        int w = width();
        int h = height();

        // top line
        path.moveTo(m_topLeftRadius, 0);
        path.lineTo(w - m_topRightRadius, 0);

        // top right arc
        int d = m_topRightRadius * 2;
        path.arcTo(w - d, 0, d, d, 90, -90);

        // right line
        path.lineTo(w, h - m_bottomRightRadius);

        // bottom right arc
        d = m_bottomRightRadius * 2;
        path.arcTo(w - d, h - d, d, d, 0, -90);

        // bottom line
        path.lineTo(m_bottomLeftRadius, h);

        // bottom left arc;
        d = m_bottomLeftRadius * 2;
        path.arcTo(0, h - d, d, d, -90, -90);

        // left line
        path.lineTo(0, m_topLeftRadius);

        // top left arc
        d = m_topLeftRadius * 2;
        path.arcTo(0, 0, d, d, -180, -90);

        // draw image
        QImage img = m_image.scaled(size() * devicePixelRatioF(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        painter.setPen(Qt::NoPen);
        painter.setClipPath(path);
        painter.drawImage(rect(), img);
    }

  private:
    // 成员变量
    QImage m_image;

    //
    int m_topLeftRadius;
    int m_topRightRadius;
    int m_bottomLeftRadius;
    int m_bottomRightRadius;
};