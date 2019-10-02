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