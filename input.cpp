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

#include "input.h"

fluid* readFluidInput(const char * inputFile){
	fluid* inputFluid = new fluid();
	std::string line; 
	std::ifstream input(inputFile);

	if (!input){
		std::cout << "Fluid Input File does cannot be opened!" << std::endl;
		exit(1);
	}

	double dummy = 0.0;
  	while ( getline(input,line) ){
    	if ( line == "$FLUID INPUTS" ){
    		input >> dummy;
    		inputFluid->setDensity(dummy);
    		input >> dummy;
    		inputFluid->setBulkModulus(dummy);
    		input >> dummy;
    		inputFluid->setViscosity(dummy);
    	}
    }
	input.close();
	return inputFluid;
}

pipe* readPipeInput(const char * inputFile, fluid* f){
	pipe* inputPipe = new pipe();
	std::string line; 
	std::ifstream input(inputFile);

	if (!input){
		std::cout << "Pipe Input File does cannot be opened!" << std::endl;
		exit(1);
	}

	double dummy = 0.0;
  	while ( getline(input,line) ){
    	if ( line == "$PIPE INPUTS" ){
    		input >> dummy;
    		inputPipe->setDiameter(dummy);
    		input >> dummy;
    		inputPipe->setLength(dummy);
    		input >> dummy;
    		inputPipe->setThickness(dummy);
    		input >> dummy;
    		inputPipe->setYoungsModulus(dummy);
    		input >> dummy;
    		inputPipe->setPoissonsRatio(dummy);
    		input >> dummy;
    		inputPipe->setRoughness(dummy);
    	}
    }
	input.close();

	inputPipe->setArea();
	inputPipe->setWaveSpeed(f);

	return inputPipe;
}

singlePhaseSolver* readSinglePhaseSolverInput(const char * inputFile, fluid* f, pipe* p){
	singlePhaseSolver* inputSolver = new singlePhaseSolver();
	std::string line;
	std::ifstream input(inputFile);

	if (!input){
		std::cout << "Pipe Input File does cannot be opened!" << std::endl;
		exit(1);
	}

	double dummy = 0.0;
  	while ( getline(input,line) ){
    	if ( line == "$SINGLE PHASE SOLVER INPUTS" ){
    		input >> dummy;
    		inputSolver->setFlowRate(dummy);
    		input >> dummy;
    		inputSolver->setReservoirHeight(dummy);
    		input >> dummy;
    		inputSolver->setValveClosingTime(dummy);
    		input >> dummy;
    		inputSolver->setNumberOfElements(dummy);
    		input >> dummy;
    		inputSolver->setOscillations(dummy);
    	}
    }
	input.close();

	inputSolver->setFluid(f);
	inputSolver->setPipe(p);
	inputSolver->setFlowVelocity();
	inputSolver->setRenoldsNumber();
	inputSolver->setTravelTime();
	inputSolver->setTimeStep();
	inputSolver->setTotalTime();
	inputSolver->setElementSize();
	inputSolver->setNumberOfTimeSteps();
	inputSolver->setNumberOfNodes();

	return inputSolver;
}

