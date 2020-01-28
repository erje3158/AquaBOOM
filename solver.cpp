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

#include "solver.h"

const double PI = 3.14159265358979323846;
const double g = 9.8;

int singlePhaseSolver::getNumberOfElements(){
	return numberOfElements;
}

int singlePhaseSolver::getOscillations(){
	return oscillations;
}

double singlePhaseSolver::getFlowRate(){
	return flowRate;
}

double singlePhaseSolver::getReservoirHeight(){
	return reservoirHeight;
}

double singlePhaseSolver::getValveClosingTime(){
	return valveClosingTime;
}

void singlePhaseSolver::setNumberOfElements(int numElem){
	numberOfElements = numElem;
}

void singlePhaseSolver::setOscillations(int osc){
	oscillations = osc;
}

void singlePhaseSolver::setFlowRate(double Q0){
	flowRate = Q0;
}

void singlePhaseSolver::setReservoirHeight(double H){
	reservoirHeight = H;
}

void singlePhaseSolver::setValveClosingTime(double t_v){
	valveClosingTime = t_v;
}

fluid* singlePhaseSolver::getFluid(){
	return inputFluid;
}
pipe* singlePhaseSolver::getPipe(){
	return inputPipe;
}

void singlePhaseSolver::setFluid(fluid* f){
	inputFluid = f;
}

void singlePhaseSolver::setPipe(pipe* p){
	inputPipe = p;
}

double singlePhaseSolver::getFlowVelocity(){
	return flowVelocity;
}

double singlePhaseSolver::getRenoldsNumber(){
	return renoldsNumber;
}

void singlePhaseSolver::setFlowVelocity(){
	flowVelocity = flowRate / inputPipe->getArea();
}

void singlePhaseSolver::setRenoldsNumber(){
	renoldsNumber = inputFluid->getDensity() * flowVelocity * inputPipe->getDiameter() / inputFluid->getViscosity();
}

double singlePhaseSolver::getTravelTime(){
	return travelTime;
}

double singlePhaseSolver::getTimeStep(){
	return timeStep;
}

double singlePhaseSolver::getTotalTime(){
	return totalTime;
}

void singlePhaseSolver::setTravelTime(){
	travelTime = inputPipe->getLength() / inputPipe->getWaveSpeed();
}

void singlePhaseSolver::setTimeStep(){
	///TODO travelTime could be null (or uninitialized) - put in catch
	///TODO check integer division and recasting...
	timeStep = travelTime / numberOfElements;
}

void singlePhaseSolver::setTotalTime(){
	totalTime = 4 * oscillations * travelTime;
}

double singlePhaseSolver::getElementSize(){
	return elementSize;
}

int singlePhaseSolver::getNumberOfTimeSteps(){
	return numberOfTimeSteps;
}

int singlePhaseSolver::getNumberOfNodes(){
	return numberOfNodes;
}

void singlePhaseSolver::setElementSize(){
	elementSize = inputPipe->getWaveSpeed() * timeStep;
}

void singlePhaseSolver::setNumberOfTimeSteps(){
	numberOfTimeSteps = (int) round(totalTime / timeStep);
}

void singlePhaseSolver::setNumberOfNodes(){
	numberOfNodes = (int) round(inputPipe->getLength() / elementSize);
}

void singlePhaseSolver::initializeSolutionArrays(){
	//Creates flattened array
	flowRateSolution = new double[numberOfNodes * numberOfTimeSteps];
	headSolution = new double[numberOfNodes * numberOfTimeSteps];
}








