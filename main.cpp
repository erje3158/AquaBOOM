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

#include <iostream>
#include "main.h"
#include "pipe.h"
#include "fluid.h"
#include "solver.h"

int main(int argc, char * argv[]){

	cout << endl << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Welcome to AquaBOOM!" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	pipe* testPipe = new pipe(0.02, 15.22, 0.001, 120000000000, 0.35, 0.0000015);
	fluid* testFluid = new fluid(998.2, 2200000000, 0.001002, testPipe);

	cout << "Length = " << testPipe->getLength() << endl;
	cout << "Area = " << testPipe->getArea() << endl << endl;

	singlePhaseSolver* testSolver = new singlePhaseSolver(0.000156, 46.0, 0.018, 48, 20);

	testSolver->setFlowVelocity(testPipe);
	testSolver->setRenoldsNumber(testPipe, testFluid);
	cout << "WaveSpeed = " << testFluid->getWaveSpeed() << endl;
	cout << "Flow Velocity = " << testSolver->getFlowVelocity() << endl;
	cout << "Renolds Number = " << testSolver->getRenoldsNumber() << endl << endl;

	testSolver->setTravelTime(testPipe, testFluid);
	testSolver->setTimeStep();
	testSolver->setTotalTime();
	testSolver->setElementSize(testFluid);
	testSolver->setNumberOfTimeSteps();
	testSolver->setNumberOfNodes(testPipe);
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

