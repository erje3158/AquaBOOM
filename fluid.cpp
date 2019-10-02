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

#include "fluid.h"

double fluid::getDensity(){
	return density;
}

double fluid::getBulkModulus(){
	return bulkModulus;
}

double fluid::getViscosity(){
	return viscosity;
}

void fluid::setDensity(double rho){
	density = rho;
}

void fluid::setBulkModulus(double K){
	bulkModulus = K;
}

void fluid::setViscosity(double mu){
	viscosity = mu;
}

double fluid::getWaveSpeed(){
	return waveSpeed;
}

void fluid::setWaveSpeed(pipe* p){
	double numerator, denominator, c1;

	///TODO Add ability to use other c1 values for different axial constraints
	c1 = 1.0; //for pipe anchored with expansion joints throughout
	//c1 = 1 - pow(p->getPoissonsRatio(), 2); //c1 refers to axially constrained pipe.
	//c1 = 2 * p->getThickness() / (p->getDiameter() * (1 + p->getPoissonsRatio())) + 
	//	p->getDiameter() * (1 - pow(p->getPoissonsRatio(),2) / (p->getDiameter() + p->getThickness()));
	numerator = pow(bulkModulus / density, 0.5);
	denominator = pow(1 + c1 * (bulkModulus * p->getDiameter() / (p->getThickness() * p->getYoungsModulus())), 0.5);

	waveSpeed = numerator / denominator;
}