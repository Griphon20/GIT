#include <iostream>
#include <graphics.h>
#include <time.h>
#include<cmath>

class tPoint {
private:
int x;
int y;
int mv;
int color;
public:
virtual void SetX(int X) {
x = X;
}
virtual int GetX() {
return x;
}

virtual void SetY(int X) {
y = X;
}
virtual int GetY() {
return y;
}

virtual void SetColor(int X) {
color = X;
}
virtual int GetColor() {
return color;
}

virtual void SetMv(int X) {
mv = X;
}
virtual int GetMv() {
return mv;
}

virtual void Move()
{
switch (mv) {
case 1:x += 5;
if (x > 775) {
mv = 2;
}
break;
case 2:x -= 5;
if (x < 15) {
mv = 1;
}
break;
case 3:y -= 5;
if (y < 15) {
mv = 4;
}
break;
case 4:y += 5;
if (y > 775) {
mv = 3;
}
break;
}

}
};

class Otrezok :public tPoint {
private:
int x2;
int y2;
public:
virtual void SetX2(int X) {
x2 = X;
}
virtual int GetX2() {
return x2;
}

virtual void SetY2(int X) {
y2 = X;
}
virtual int GetY2() {
return y2;
}

void Move() {
switch (GetMv()) {
case 1:SetX(GetX() + 5);
SetX2(GetX2() + 5);
if (GetX() > 700 || GetX2() > 700) {
SetMv(2);
}
break;
case 2:SetX(GetX() - 5);
SetX2(GetX2() - 5);
if (GetX() < 0 || GetX2() < 0) {
SetMv(1);
}
break;
case 3:SetY(GetY() - 5);
SetY2(GetY2() - 5);
if (GetY() < 0 || GetY2() < 0) {
SetMv(4);
}
break;
case 4:SetY(GetY() + 5);
SetY2(GetY2() + 5);
if (GetY() > 800 || GetY2() > 800) {
SetMv(3);
}
break;
}
}
virtual void construction() {
setcolor(GetColor());
int x1, x2, y1, y2;
x1 = GetX();
x2 = GetX2();
y1 = GetY();
y2 = GetY2();
line(x1, y1, x2, y2);
}
};

class Circle :public tPoint {
private:
int R;
public:
void SetR(int X) {
R = X;
}
int GetR() {
return R;
}

virtual void construction() {
int x, y, color;
color = GetColor();
x = GetX();
y = GetY();
setcolor(color);
setfillstyle(1, color);
circle(x, y, R);
floodfill(x, y, color);
}

virtual void Move() {
switch (GetMv()) {
case 1:SetX(GetX() + 5);

if (GetX() + R > 700) {
SetMv(2);
}
break;
case 2:SetX(GetX() - 5);

if (GetX() - R < 0) {
SetMv(1);
}
break;
case 3:SetY(GetY() - 5);

if (GetY() - R < 0) {
SetMv(4);
}
break;
case 4:SetY(GetY() + 5);

if (GetY() + R > 800) {
SetMv(3);
}
break;
}

}
};

class Rectangl :public tPoint {
private:
int x2;
int y2;
public:
virtual void SetX2(int X) {
x2 = X;
}
virtual int GetX2() {
return x2;
}

virtual void SetY2(int X) {
y2 = X;
}
virtual int GetY2() {
return y2;
}
virtual void Move() {
switch (GetMv()) {
case 1:SetX(GetX() + 5);
SetX2(GetX2() + 5);
if (GetX() > 700 || GetX2() > 700) {
SetMv(2);
}
break;
case 2:SetX(GetX() - 5);
SetX2(GetX2() - 5);
if (GetX() < 0 || GetX2() < 0) {
SetMv(1);
}
break;
case 3:SetY(GetY() - 5);
SetY2(GetY2() - 5);
if (GetY() < 0 || GetY2() < 0) {
SetMv(4);
}
break;
case 4:SetY(GetY() + 5);
SetY2(GetY2() + 5);
if (GetY() > 800 || GetY2() > 800) {
SetMv(3);
}
break;
}
}
virtual void construction() {
int x1, x2, y1, y2,color;
x1 = GetX();
x2 = GetX2();
y1 = GetY();
y2 = GetY2();
color = GetColor();
setcolor(color);
rectangle(x1, y1, x2, y2);
}
};

class triangle :public tPoint {
private:
int x2;
int y2;
int x3;
int y3;
public:
virtual void SetX2(int X) {
x2 = X;
}
virtual int GetX2() {
return x2;
}

virtual void SetX3(int X) {
x3 = X;
}
int GetX3() {
return x3;
}

virtual void SetY2(int X) {
y2 = X;
}
virtual int GetY2() {
return y2;
}

virtual void SetY3(int X) {
y3 = X;
}
virtual int GetY3() {
return y3;
}

virtual void Move() {
switch (GetMv()) {
case 1:SetX(GetX() + 5);
SetX2(GetX2() + 5);
SetX3(GetX3() + 5);
if (GetX() > 700 || GetX2() > 700 || GetX3() > 700) {
SetMv(2);
}
break;
case 2:SetX(GetX() - 5);
SetX2(GetX2() - 5);
SetX3(GetX3() - 5);
if (GetX() < 0 || GetX2() < 0 || GetX3() < 0) {
SetMv(1);
}
break;
case 3:SetY(GetY() - 5);
SetY2(GetY2() - 5);
SetY3(GetY3() - 5);
if (GetY() < 0 || GetY2() < 0 || GetY3() < 0) {
SetMv(4);
}
break;
case 4:SetY(GetY() + 5);
SetY2(GetY2() + 5);
SetY3(GetY3() + 5);
if (GetY() > 800 || GetY2() > 800 || GetY3() > 800) {
SetMv(3);
}
break;
}
}

virtual void construction() {
int x1, x2, y1, y2,x3,y3,color;
color = GetColor();
x1 = GetX();
x2 = GetX2();
x3 = GetX3();
y1 = GetY();
y2 = GetY2();
y3 = GetY3();
setcolor(color);
line(x1, y1, x2, y2);
setcolor(color);
line(x1, y1, x3, y3);
setcolor(color);
line(x2, y2, x3, y3);
}
virtual void DrawRectangle( double angle,int color)
{
int x0=200,y0=200,x1, y1, x2, y2=200, x3, y3,x4,y4,x7,x8,x9,y7,y8,y9,x10,y10;
float d;
d=200;


x1 = round(x0 + (d/2) * cos(angle * M_PI / 180)); 
y1 = round(y0 +(d/2) * sin(angle * M_PI / 180)); 

x3 = round(x1 - d * cos(angle * M_PI / 180)); 
y3 = round(y1 - d * sin(angle * M_PI / 180)); 

x4 = round(x2 + d * cos(angle * M_PI / 180)); 
y4 = round(y2 + d * sin(angle * M_PI / 180)); 
x7 = round(400 + d * cos(angle * M_PI / 180)); 
y7 = round(400 + d * sin(angle * M_PI / 180)); 
x10 = round(400 - d * cos(angle * M_PI / 180)); 
y10 = round(400 - d * sin(angle * M_PI / 180)); 
x8 = round(550 + (d/2) * cos(angle * M_PI / 180)); 
y8 = round(550+ (d/2) * sin(angle * M_PI / 180)); 
line(x2, y2, x1, y1); 
line(x2, y2, x3, y3); 
line(x2, y2, x4, y4);
line(x1, y1, x4, y4);
line(x1, y1, x3, y3);
 line(x7, y7, x10, y10);
    ellipse (y8, x8, 0, 360, 80, 40);
}
};




int main()
{
int  ang=0;
initwindow(700, 700);
setlocale(LC_ALL, "ru");
tPoint mas[3];
//otrezok a;
//a.SetX(100);
//a.SetX2(200);
//a.SetY(300);
//a.SetY2(400);
//a.SetColor(5);
//a.SetMv(1);
//while (1) {
//delay(100);
//setfillstyle(1, 0);
//bar(0, 0, 700, 700);
//a.Move();
//a.construction();
//}
//Circle a;
//a.SetMv(1);
//a.SetX(200);
//a.SetY(200);
//a.SetR(80);
//a.SetColor(3);
//while (1) {
// delay(100);
// setfillstyle(1, 0);
// bar(0, 0, 700, 700);
// a.Move();
// a.construction();
//}

//Rectangl a;
//a.SetColor(2);
//a.SetX(100);
//a.SetX2(200);
//a.SetY(100);
//a.SetY2(200);
//a.SetMv(2);
//while (1) {
// delay(100);
// setfillstyle(1, 0);
// bar(0, 0, 700, 700);
// a.Move();
// a.construction();
//}

triangle a;
a.SetColor(2);
a.SetX(100);
a.SetX2(300);
a.SetX3(250);
a.SetY(100);
a.SetY2(150);
a.SetY3(500);
a.SetMv(2);
while (1) {
delay(100);
setfillstyle(1, 0);
bar(0, 0, 700, 700);
a.Move();
a.construction();
setcolor(4);
a.DrawRectangle(ang, 4);
delay(100);
a.DrawRectangle( ang, 0);
ang += 10;
}
}




