//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//   ________  ________  ___  ___  ________  ________  ________  ________  _____ ______        //
//  |\   __  \|\   __  \|\  \|\  \|\   __  \|\   __  \|\   __  \|\   __  \|\   _ \  _   \      //
//  \ \  \|\  \ \  \|\  \ \  \\\  \ \  \|\  \ \  \|\ /\ \  \|\  \ \  \|\  \ \  \\\__\ \  \     //
//   \ \   __  \ \  \\\  \ \  \\\  \ \   __  \ \   __  \ \  \\\  \ \  \\\  \ \  \\|__| \  \    //
//    \ \  \ \  \ \  \\\  \ \  \\\  \ \  \ \  \ \  \|\  \ \  \\\  \ \  \\\  \ \  \    \ \  \   //
//     \ \__\ \__\ \_____  \ \_______\ \__\ \__\ \_______\ \_______\ \_______\ \__\    \ \__\  //
//      \|__|\|__|\|___| \__\|_______|\|__|\|__|\|_______|\|_______|\|_______|\|__|     \|__|  //
//                       \|__|                                                                 //
//																							   //
// 1D Hydraulic Transient Solver														       //
// 																							   //
// Created By Erik Jensen, Ph.D., E.I.T.													   //
// January 24, 2020 - Version v0.2  														   //
//																						       //
// Copyright © 2020 Erik Jensen																   //
// All Rights Reserved																		   //
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

#ifndef PIPE_H
#define PIPE_H

#include <cmath>
#include "fluid.h"

class pipe{

private:
	double diameter;
	double length;
	double thickness;
	double youngsModulus;
	double poissonsRatio;
	double roughness;

	double area;
	double waveSpeed;

public:
	pipe(){
		diameter = 0.0;
		length = 0.0;
		thickness = 0.0;
		youngsModulus = 0.0;
		poissonsRatio = 0.0;
		roughness = 0.0;
	}

	pipe(double d, double l, double t, double E, double nu, double r){
		diameter = d;
		length = l;
		thickness = t;
		youngsModulus = E;
		poissonsRatio = nu;
		roughness = r;
		setArea();
	}

	pipe(double d, double l, double t, double E, double nu, double r, fluid* f){
		diameter = d;
		length = l;
		thickness = t;
		youngsModulus = E;
		poissonsRatio = nu;
		roughness = r;
		setArea();
		setWaveSpeed(f);
	}

	double getDiameter();
	double getLength();
	double getThickness();
	double getYoungsModulus();
	double getPoissonsRatio();
	double getRoughness();

	void setDiameter(double d);
	void setLength(double l);
	void setThickness(double t);
	void setYoungsModulus(double E);
	void setPoissonsRatio(double nu);
	void setRoughness(double r);

	double getArea();
	void setArea();

	double getWaveSpeed();
	void setWaveSpeed(fluid* f);

};

#endif /* PIPE_H */