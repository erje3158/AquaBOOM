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

#include "pipe.h"

const double PI = 3.14159265358979323846;

double pipe::getDiameter(){
	return diameter;
}

double pipe::getLength(){
	return length;
}

double pipe::getThickness(){
	return thickness;
}

double pipe::getYoungsModulus(){
	return youngsModulus;
}

double pipe::getPoissonsRatio(){
	return poissonsRatio;
}

double pipe::getRoughness(){
	return roughness;
}

void pipe::setDiameter(double d){
	diameter = d;
}

void pipe::setLength(double l){
	length = l;
}

void pipe::setThickness(double t){
	thickness = t;
}

void pipe::setYoungsModulus(double E){
	youngsModulus = E;
}

void pipe::setPoissonsRatio(double nu){
	poissonsRatio = nu;
}

void pipe::setRoughness(double r){
	roughness = r;
}

double pipe::getArea(){
	return area;
}

void pipe::setArea(){
	area = PI * pow(diameter / 2, 2);
}

double pipe::getWaveSpeed(){
	return waveSpeed;
}

void pipe::setWaveSpeed(fluid* f){
	double numerator, denominator, c1;

	///TODO Add ability to use other c1 values for different axial constraints
	c1 = 1.0; //for pipe anchored with expansion joints throughout
	//c1 = 1 - pow(p->getPoissonsRatio(), 2); //c1 refers to axially constrained pipe.
	//c1 = 2 * p->getThickness() / (p->getDiameter() * (1 + p->getPoissonsRatio())) + 
	//	p->getDiameter() * (1 - pow(p->getPoissonsRatio(),2) / (p->getDiameter() + p->getThickness()));
	numerator = pow(f->getBulkModulus() / f->getDensity(), 0.5);
	denominator = pow(1 + c1 * (f->getBulkModulus() * diameter / (thickness * youngsModulus)), 0.5);

	waveSpeed = numerator / denominator;
}