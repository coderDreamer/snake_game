#include "game_window.h"
#include "ui_game_window.h"
#include <QDebug>
#include <QTimer>
#include <iostream>

using namespace std;

Game_Window::Game_Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game_Window)
{
    ui->setupUi(this);
}

Game_Window::~Game_Window()
{
    delete ui;

    QTimer* snakeTimer = new QTimer(this);

    connect(snakeTimer, SIGNAL(timeout()), this, SLOT(onSnakeTimer()));
    snakeTimer->start(50);

    // snake's default dir/ection
        snake[0].x = 10;
        snake[0].y = 10;

}


/* Drawing Method*/
void Game_Window::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this); // Creating an object of QPainter

    // Устанавливаем кисть абриса
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

    for(i = 0; i < width; i += Scale) {
        painter.drawLine(i, 0, i, height);
    }
    for(i = 0; i < height; i += Scale) {
     painter.drawLine(0, i, width, i);
    }


    // The problem is in Painting Rectangles(!)
        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
        for(i = 1; i < snakeLength + 1; i++) {
            painter.drawRect(i * Scale, 0, Scale, Scale);
        }
//        cout << "Width: " << Scale * N << endl;
//        cout << "Height: " << Scale * M << endl;

}
void Game_Window::snakeMove() {

    /* snake's body moving */
    for(i = snakeLength; i > 0; --i) {
        snake[i].x = snake[i - 1].x;
        snake[i].y = snake[i - 1].y;
    }

    /* snake's head moving */
    switch(direction) {
    case 0:
        snake[0].y += 1; break;
    case 1:
        snake[0].x -= 1; break;
    case 2:
        snake[0].x += 1; break;
    case 3:
        snake[0].y -= 1; break;

    }
}

void Game_Window::drawSnake()
{


}

void Game_Window::onSnakeTimer()
{
    snakeMove();
    qDebug() << "This is the Timer Function" << endl;
}
