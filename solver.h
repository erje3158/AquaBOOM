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

#ifndef SOLVER_H
#define SOLVER_H

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

		fluid* inputFluid;
		pipe* inputPipe;

	public:
		singlePhaseSolver(){
			flowRate = 0.0;
			reservoirHeight = 0.0;
			valveClosingTime = 0.0;
			numberOfElements = 0;
			oscillations = 0;
		}

		singlePhaseSolver(double Q0, double H, double t_v, int numElem, int osc, pipe* p, fluid* f){
			flowRate = Q0;
			reservoirHeight = H;
			valveClosingTime = t_v;
			numberOfElements = numElem;
			oscillations = osc;
			inputPipe = p;
			inputFluid = f;
			setFlowVelocity();
			setRenoldsNumber();
			setTravelTime();
			setTimeStep();
			setTotalTime();
			setElementSize();
			setNumberOfTimeSteps();
			setNumberOfNodes();
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

		fluid* getFluid();
		pipe* getPipe();

		void setFluid(fluid* f);
		void setPipe(pipe* p);

		double getFlowVelocity();
		double getRenoldsNumber();

		void setFlowVelocity();
		void setRenoldsNumber();

		double getTravelTime();
		double getTimeStep();
		double getTotalTime();

		void setTravelTime();
		void setTimeStep();
		void setTotalTime();

		double getElementSize();
		int getNumberOfTimeSteps();
		int getNumberOfNodes();

		void setElementSize();
		void setNumberOfTimeSteps();
		void setNumberOfNodes();

		void initializeSolutionArrays();

};

#endif /* SOLVER_H */