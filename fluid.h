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
#ifndef FLUID_H
#define FLUID_H

#include <cmath>
#include "pipe.h"

class fluid{

private:
	double density;
	double bulkModulus;
	double viscosity;

	double waveSpeed;

public:
	fluid(){
		density = 0.0;
		bulkModulus = 0.0;
		viscosity = 0.0;
	}

	fluid(double rho, double K, double mu){
		density = rho;
		bulkModulus = K;
		viscosity = mu;
	}

	fluid(double rho, double K, double mu, pipe* p){
		density = rho;
		bulkModulus = K;
		viscosity = mu;
		setWaveSpeed(p);
	}

	double getDensity();
	double getBulkModulus();
	double getViscosity();

	void setDensity(double rho);
	void setBulkModulus(double K);
	void setViscosity(double mu);

	double getWaveSpeed();
	void setWaveSpeed(pipe* p);

};

#endif /* FLUID_H */