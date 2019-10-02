//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//   ________  ________  ___  ___  ________  ________  ________  ________  _____ ______      
//  |\   __  \|\   __  \|\  \|\  \|\   __  \|\   __  \|\   __  \|\   __  \|\   _ \  _   \    
//  \ \  \|\  \ \  \|\  \ \  \\\  \ \  \|\  \ \  \|\ /\ \  \|\  \ \  \|\  \ \  \\\__\ \  \   
//   \ \   __  \ \  \\\  \ \  \\\  \ \   __  \ \   __  \ \  \\\  \ \  \\\  \ \  \\|__| \  \  
//    \ \  \ \  \ \  \\\  \ \  \\\  \ \  \ \  \ \  \|\  \ \  \\\  \ \  \\\  \ \  \    \ \  \ 
//     \ \__\ \__\ \_____  \ \_______\ \__\ \__\ \_______\ \_______\ \_______\ \__\    \ \__\
//      \|__|\|__|\|___| \__\|_______|\|__|\|__|\|_______|\|_______|\|_______|\|__|     \|__|
//                       \|__|                                                                
//
// 1D Hydraulic Transient Solver
// 
// Created By Erik Jensen, Ph.D.
// August 7, 2019 - Version v0.1  
//
// Copyright © 2019 Erik Jensen
// All Rights Reserved
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef PIPE_H
#define PIPE_H

#include <cmath>

class pipe{

private:
	double diameter;
	double length;
	double thickness;
	double youngsModulus;
	double poissonsRatio;
	double roughness;

	double area;

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

};

#endif /* PIPE_H */