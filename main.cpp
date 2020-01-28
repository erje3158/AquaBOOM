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

#include <iostream>
#include "main.h"
#include "pipe.h"
#include "fluid.h"
#include "solver.h"
#include "input.h"

using namespace std;

int main(int argc, char * argv[]){

	cout << endl << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Welcome to AquaBOOM!" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	const char * inputFile = "./inputFile.txt";
	fluid* testFluid = readFluidInput(inputFile);
	pipe* testPipe = readPipeInput(inputFile, testFluid);
	singlePhaseSolver* testSolver = readSinglePhaseSolverInput(inputFile, testFluid, testPipe);

	///TODO Code currently can only handle 1 pipe and 1 fluid

	cout << "Length = " << testPipe->getLength() << endl;
	cout << "Area = " << testPipe->getArea() << endl << endl;
	cout << "WaveSpeed = " << testPipe->getWaveSpeed() << endl;
	cout << "Flow Velocity = " << testSolver->getFlowVelocity() << endl;
	cout << "Renolds Number = " << testSolver->getRenoldsNumber() << endl << endl;
	cout << "Travel Time = " << testSolver->getTravelTime() << endl;
	cout << "Time Step = " << testSolver->getTimeStep() << endl;
	cout << "Total Time = " << testSolver->getTotalTime() << endl;
	cout << "Element Size = " << testSolver->getElementSize() << endl;
	cout << "Number of Timesteps = " << testSolver->getNumberOfTimeSteps() << endl;
	cout << "Number of Nodes = " << testSolver->getNumberOfNodes() << endl << endl;

	///TODO current question - how do I pass in an array of pipes or pipe pointers?

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl << endl;




	return 0;
}


