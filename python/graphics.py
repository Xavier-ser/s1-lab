import turtle

screen = turtle.Screen()
screen.bgcolor("yellow")


t = turtle.Turtle()
t.speed(0)  
t.pensize(2)


colors = ["black", "red", "blue", "white", "green", "orange"]


for i in range(60):
    t.color(colors[i % 6])  
    t.forward(60)
    t.right(50)
    t.forward(60)
    t.right(50)
    t.forward(60)
    t.right(50)
    t.forward(60)
    t.right(50)
    t.forward(60)
    t.right(50)
    t.forward(60)
    t.right(11)  
t.hideturtle()
turtle.done()
