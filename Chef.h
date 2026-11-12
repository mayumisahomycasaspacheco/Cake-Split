#pragma once
using namespace System;
using namespace System::Drawing;

ref class Chef
{
private:
	int x, y;
	int dx;
	int ancho, alto;
	Bitmap^ sprite_chef;
public:
	Chef();
	~Chef();
};

Chef::Chef()
{
	x = 100;
	y = 100;
	dx = 0;
}

Chef::~Chef()
{
	delete sprite_chef;
}