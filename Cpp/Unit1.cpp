//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x, y;
double dx, dy, difx, dify;
float a;
int k = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
void GetShapeCenter(TShape *shape)
{
x = shape->Left + shape->Width/2;
y = shape->Top + shape->Height/2;
}


//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)

{
if (Tag)
{
Refresh();
GetShapeCenter(Shape1);
Canvas->MoveTo(x, y);
Canvas->LineTo(X, Y);
dx = X-x;
dy = Y-y;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
if (Button == mbLeft)
{
Timer1->Enabled = 0;
Tag = 1;
Shape1->Visible = 0;
Shape1->Left=X-Shape1->Width/2;
Shape1->Top=Y-Shape1->Height/2;
}
Timer2->Enabled=false;
Timer3->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
Tag = 0;
Refresh();
difx = Shape1->Left;
dify = Shape1->Top;
Timer1->Enabled = 1;
Timer2->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
difx += dx/2/Timer1->Interval*(1 +TrackBar1->Position);
dify += dy/2/Timer1->Interval*TrackBar1->Position;
Canvas->MoveTo(difx, dify);
Shape1->Left = difx;
Shape1->Top = dify;
if (Shape1->Left <= 0)
Shape1->Left = 0;
if (Shape1->Left + Shape1->Width >= ClientWidth)
Shape1->Left = ClientWidth - Shape1->Width;
if (Shape1->Left <= 0 || Shape1->Left + Shape1->Width >= ClientWidth)
dx *= -1;
if (Shape1->Top <= 0)
Shape1->Top = 0;
if (Shape1->Top + Shape1->Height + StatusBar1->Height >= ClientHeight)
Shape1->Top = ClientHeight - Shape1->Height - StatusBar1->Height;
if (Shape1->Top <= 0 || Shape1->Top + Shape1->Height + StatusBar1->Height >= ClientHeight)
dy *= -1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
Refresh();
a+=0.2*TrackBar2->Position;
TPoint points1[4];
points1[0] = Point( Shape1->Width/2 *(-cos(a - 3.14/2)) +Shape1->Left + Shape1->Width / 2, Shape1->Width/2 * sin(a - 3.14/2 )+ Shape1->Top + Shape1->Height/2);
points1[1] = Point( Shape1->Width/2 *(-cos(a)) + Shape1->Left + Shape1->Width / 2, Shape1->Width/2 * sin(a)+ Shape1->Top + Shape1->Height/2);
points1[2] = Point( Shape1->Width/2 *(-cos(a + 3.14/2)) + Shape1->Left + Shape1->Width / 2, Shape1->Width/2 * sin(a + 3.14/2 )+ Shape1->Top + Shape1->Height/2);
points1[3] = Point( Shape1->Width/2 *(-cos(a + 3.14)) + Shape1->Left + Shape1->Width / 2, Shape1->Width/2 * sin(a + 3.14 )+ Shape1->Top + Shape1->Height/2);
Canvas->Brush->Color=RGB(255*Shape1->Left/(Form1->Width-Shape1->Width),255,0);
Canvas->Ellipse(Shape1->Left,Shape1->Top,Shape1->Left+Shape1->Width,Shape1->Top+Shape1->Height);
Canvas->Brush->Color=RGB((255*(Form1->Width-Shape1->Width)-255*Shape1->Left)/(Form1->Width-Shape1->Width),0,255*Shape1->Left/(Form1->Width-Shape1->Width));
Canvas->Polygon(points1, 3);
Canvas->Brush->Color=RGB(255*Shape1->Left/(Form1->Width-Shape1->Width),255,0);
Canvas->Ellipse(Shape1->Left + Shape1->Width/4,Shape1->Top + Shape1->Height/4, Shape1->Left + Shape1->Width*3/4, Shape1->Top + Shape1->Height *3/4);
if (Shape1->Left + Shape1-> Width >= Form1->ClientWidth || Shape1->Top <= 0 || Shape1->Top + Shape1->Height + StatusBar1->Height>=Form1->ClientHeight || Shape1->Left<=0)
{
Timer3->Enabled = false;
Timer2->Enabled = true;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
Refresh();
a+=0.2*TrackBar2->Position;
TPoint points1[4];
points1[0] = Point( Shape1->Width/2 *cos(a - 3.14/2) +Shape1->Left + Shape1->Width / 2, Shape1->Width/2 * sin(a - 3.14/2)+ Shape1->Top + Shape1->Height/2);
points1[1] = Point( Shape1->Width/2 *cos(a) + Shape1->Left + Shape1->Width / 2, Shape1->Width/2 * sin(a)+ Shape1->Top + Shape1->Height/2);
points1[2] = Point( Shape1->Width/2 *cos(a + 3.14/2) + Shape1->Left + Shape1->Width / 2, Shape1->Width/2 * sin(a + 3.14/2)+ Shape1->Top + Shape1->Height/2);
points1[3] = Point( Shape1->Width/2 *cos(a + 3.14) + Shape1->Left + Shape1->Width / 2, Shape1->Width/2 * sin(a + 3.14)+ Shape1->Top + Shape1->Height/2);
Canvas->Brush->Color=RGB(255*Shape1->Left/(Form1->Width-Shape1->Width),255,0);
Canvas->Ellipse(Shape1->Left,Shape1->Top,Shape1->Left+Shape1->Width,Shape1->Top+Shape1->Height);
Canvas->Brush->Color=RGB((255*(Form1->Width-Shape1->Width)-255*Shape1->Left)/(Form1->Width-Shape1->Width),0,255*Shape1->Left/(Form1->Width-Shape1->Width));
Canvas->Polygon(points1, 3);
Canvas->Brush->Color=RGB(255*Shape1->Left/(Form1->Width-Shape1->Width),255,0);
Canvas->Ellipse(Shape1->Left + Shape1->Width/4,Shape1->Top + Shape1->Height/4, Shape1->Left + Shape1->Width*3/4, Shape1->Top + Shape1->Height*3/4);
if (Shape1->Left + Shape1-> Width >= Form1->ClientWidth || Shape1->Top <= 0 || Shape1->Top + Shape1->Height + StatusBar1->Height >= Form1->ClientHeight || Shape1->Left<=0 )
{
Timer2->Enabled = false;
Timer3->Enabled = true;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
if(Timer3->Enabled==true)k=1;
if(Timer2->Enabled==true)k=-1;
Timer1->Enabled=false;
Timer2->Enabled=false;
Timer3->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
if(k == 1)
Timer3->Enabled=true;
if(k == -1)
Timer2->Enabled=true;
Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar3Change(TObject *Sender)
{
Shape1->Height=TrackBar3->Position*20;
Shape1->Width=TrackBar3->Position*20;
}
//---------------------------------------------------------------------------
