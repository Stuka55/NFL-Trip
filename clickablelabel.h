#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QObject>
#include <QWidget>
#include <Qt>

/*!
 * \brief The ClickableLabel class:
 * This class is used to implement the clickable images at the top of Main Window.
 *
 * Public Members:
 *     ClickableLabel  : Default Constructor
 *     ~ClickableLabel : Destructor
 *
 * Protected:
 *      mousePressEvent : event handler for when a user presses the image.
 *
 */
class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    /*!
     * \brief team is default constructor
     * \param takes QWidget as a parent
     * \param takes Qt Window Flag
     *
     * This constructor initializes the clickable labels (which can be seen at the top of mainWindow).
     */
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());


    /*!
     * \brief ~ClickableLabel() is a destructor for ClickableLabel
     *
     * This destructor destroys the object.
     */
    ~ClickableLabel(){}

public slots: signals:

    void clicked();

protected:
    /*!
     * \brief mousePressEvent emits the signal (clicked) and triggers a separate window to appear
     * \param takes a QMouseEvent (a click)
     *
     * Emits a signal (clicked).
     */
    void mousePressEvent(QMouseEvent* event);
};

#endif // CLICKABLELABEL_H
