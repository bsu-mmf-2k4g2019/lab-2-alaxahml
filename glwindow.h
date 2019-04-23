#ifndef WIDGET_H
#define WIDGET_H

#include <QtOpenGL>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = nullptr);
    ~GLWidget() override;

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
protected:
    void timerEvent(QTimerEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    // Shader programms
    QOpenGLShaderProgram m_prog_container;
    QOpenGLShaderProgram m_prog_triangle;
    QOpenGLShaderProgram m_prog_pyramide;

    // VAOs
    GLuint m_vao_container_id;
    GLuint m_vao_pyramide_id;

    // Textures
    GLuint m_texture_bg_id;
    GLuint m_texture_smile_id;
    GLuint m_texture_petr_id;
    GLuint m_texture_cat_id;
    GLuint m_texture_nigga_id;

    // Uniforms
    GLint  m_pyramide_color_id;

    QVector3D camera_pos;
    QVector3D camera_up;
    QVector3D camera_front;

    QTime frame_delta_time;
    QTime last_frame_time;

    QPoint m_lastPos;
    int m_xRot;
    int m_yRot;
    int m_zRot;

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);
};

#endif // WIDGET_H
