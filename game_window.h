#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class Game_Window;
}

class Game_Window : public QWidget
{
    Q_OBJECT

protected:
        void paintEvent(QPaintEvent *event);

public:
    explicit Game_Window(QWidget *parent = 0);
    ~Game_Window();
        void snakeMove();
        void drawSnake();
        QPainter *painter;

public slots:
        void onSnakeTimer();

private:
    Ui::Game_Window *ui;
    int M = 28, N = 40, Scale = 25, i = 0, snakeLength = 4;
    int width = Scale*N;
    int height = Scale*M;
    int direction;
    struct {
        int x;
        int y;
    } snake[100];
};

#endif // GAME_WINDOW_H
