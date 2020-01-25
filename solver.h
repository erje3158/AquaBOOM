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

#include <math.h>
#include "pipe.h"
#include "fluid.h"

class singlePhaseSolver{
	private:
		double flowVelocity;
		double flowRate;
		double renoldsNumber;

		double reservoirHeight; //Currently assumes that reservoir is upstream
		double valveClosingTime; //Currently assumes that valve is downstream

		int numberOfNodes;
		int numberOfElements; //number of elements in each pipe
		int numberOfPipes;
		int oscillations; //number of times pressure wave oscilates
		double elementSize;

		int numberOfTimeSteps;
		double travelTime;
		double timeStep;
		double totalTime;

		double* flowRateSolution;
		double* headSolution;

	public:
		singlePhaseSolver(double Q0, double H, double t_v, int numElem, int osc){
			flowRate = Q0;
			reservoirHeight = H;
			valveClosingTime = t_v;
			numberOfElements = numElem;
			oscillations = osc;
		}

		int getNumberOfElements();
		int getOscillations();
		double getFlowRate();
		double getReservoirHeight();
		double getValveClosingTime();

		void setNumberOfElements(int numElem);
		void setOscillations(int osc);
		void setFlowRate(double Q0);
		void setReservoirHeight(double H);
		void setValveClosingTime(double t_v);

		double getFlowVelocity();
		double getRenoldsNumber();

		void setFlowVelocity(pipe* p);
		void setRenoldsNumber(pipe* p, fluid* f);

		double getTravelTime();
		double getTimeStep();
		double getTotalTime();

		void setTravelTime(pipe* p);
		void setTimeStep();
		void setTotalTime();

		double getElementSize();
		int getNumberOfTimeSteps();
		int getNumberOfNodes();

		void setElementSize(pipe* p);
		void setNumberOfTimeSteps();
		void setNumberOfNodes(pipe* p);

		void initializeSolutionArrays();

};



